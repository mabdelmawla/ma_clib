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
	/*
	Reference: FIPS 197:
	Cipher(byte in[4*Nb], byte out[4*Nb], word w[Nb*(Nr+1)])
	begin
		byte state[4,Nb]
		state = in
		AddRoundKey(state, w[0, Nb-1]) // See Sec. 5.1.4
		for round = 1 step 1 to Nr–1
			SubBytes(state) // See Sec. 5.1.1
			ShiftRows(state) // See Sec. 5.1.2
			MixColumns(state) // See Sec. 5.1.3
			AddRoundKey(state, w[round*Nb, (round+1)*Nb-1])
		end for
		SubBytes(state)
		ShiftRows(state)
		AddRoundKey(state, w[Nr*Nb, (Nr+1)*Nb-1])
		out = state
	end
	*/
}
