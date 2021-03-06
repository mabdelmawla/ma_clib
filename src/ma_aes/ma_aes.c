/**
@file		ma_aes.h
@brief		This module contains AES APIs implementation
@author		M. Abdelmawla
@date		08 JAN 2018
@version	1.0

ma_clib is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ma_clib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ma_clib.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "ma_aes_common.h"
#include <ma_aes.h>

void ma_aes_ecb_encrypt(_t_ma_u8 *in, _t_ma_u8 *out, _t_ma_u8 *key, _t_ma_u8 nk){
	//Reference: FIPS 197:
	//Cipher(byte in[4*Nb], byte out[4*Nb], word w[Nb*(Nr+1)])
	_t_ma_u32 w[4 * (MA_AES_CMN_GET_NR(nk) + 1)];
	_t_ma_aes_sb sb;
	int i;
	// generate round keys
	ma_aes_cmn_key_expansion(key, w, nk);

	//begin
	//	byte state[4,Nb]
	//	state = in
	ma_aes_cmn_cov_u8_to_sb(in, &sb);
	//	AddRoundKey(state, w[0, Nb-1]) // See Sec. 5.1.4
	ma_aes_cmn_add_round_key(&sb, &w[0]);
	//	for round = 1 step 1 to Nr–1
	for(i = 1; i < MA_AES_CMN_GET_NR(nk); i++) {
	//		SubBytes(state) // See Sec. 5.1.1
		ma_aes_cmn_sub_bytes(&sb);
	//		ShiftRows(state) // See Sec. 5.1.2
		ma_aes_cmn_shift_rows(&sb);
	//		MixColumns(state) // See Sec. 5.1.3
		ma_aes_cmn_mix_columns(&sb);
	//		AddRoundKey(state, w[round*Nb, (round+1)*Nb-1])
		ma_aes_cmn_add_round_key(&sb,&w[i * 4]);
	//	end for
	}
	//	SubBytes(state)
	ma_aes_cmn_sub_bytes(&sb);
	//	ShiftRows(state)
	ma_aes_cmn_shift_rows(&sb);
	//	AddRoundKey(state, w[Nr*Nb, (Nr+1)*Nb-1])
	ma_aes_cmn_add_round_key(&sb, &w[i*4]);
	//	out = state
	ma_aes_cmn_cov_sb_to_u8(&sb, out);
	//end
}

void ma_aes_ecb_decrypt(_t_ma_u8 *in, _t_ma_u8 *out, _t_ma_u8 *key, _t_ma_u8 nk){
	//Reference: FIPS 197:
	//InvCipher(byte in[4*Nb], byte out[4*Nb], word w[Nb*(Nr+1)])
	_t_ma_u32 w[4 * (MA_AES_CMN_GET_NR(nk) + 1)];
	_t_ma_aes_sb sb;
	int i;
	// generate round keys
	ma_aes_cmn_key_expansion(key, w, nk);

	//begin
	//	byte state[4,Nb]
	//	state = in
	ma_aes_cmn_cov_u8_to_sb(in, &sb);
	//	AddRoundKey(state, w[Nr*Nb, (Nr+1)*Nb-1]) // See Sec. 5.1.4
	ma_aes_cmn_add_round_key(&sb, &w[4 * MA_AES_CMN_GET_NR(nk)]);
	//	for round = Nr-1 step -1 downto 1
	for(i = MA_AES_CMN_GET_NR(nk)-1; i > 0; i--) {
		//		InvShiftRows(state) // See Sec. 5.3.1
		ma_aes_cmn_inv_shift_rows(&sb);
		//		InvSubBytes(state) // See Sec. 5.3.2
		ma_aes_cmn_inv_sub_bytes(&sb);
		//		AddRoundKey(state, w[round*Nb, (round+1)*Nb-1])
		ma_aes_cmn_add_round_key(&sb,&w[i * 4]);
		//		InvMixColumns(state) // See Sec. 5.3.3
		ma_aes_cmn_inv_mix_columns(&sb);
	//	end for
	}
	//	InvShiftRows(state)
	ma_aes_cmn_inv_shift_rows(&sb);
	//	InvSubBytes(state)
	ma_aes_cmn_inv_sub_bytes(&sb);
	//	AddRoundKey(state, w[0, Nb-1])
	ma_aes_cmn_add_round_key(&sb, &w[0]);
	//	out = state
	ma_aes_cmn_cov_sb_to_u8(&sb, out);
	//end
}

