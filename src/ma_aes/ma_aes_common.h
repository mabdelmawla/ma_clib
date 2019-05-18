/**
@file		ma_aes_common.h
@brief		This module contains AES Common operation APIs
@author		M. Abdelmawla
@date		22 DEC 2017
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

#ifndef _MA_AES_COMMON_H_
#define _MA_AES_COMMON_H_

#include <ma_common.h>

/** 
Defines
*/
#define MA_AES_CMN_GET_NR(nk)	((nk) + 6)


/**
Typedefs
*/
typedef _t_ma_u8 _t_ma_aes_blk[16];		/** AES in/out block array */
typedef _t_ma_u8 _t_ma_aes_sb[4][4];	/** State array in bytes */
typedef _t_ma_u32 _t_ma_aes_swc[4];		/** state column word array */

void ma_aes_cmn_cov_u8_to_sb(const _t_ma_u8 *inp, _t_ma_aes_sb *sb);
void ma_aes_cmn_cov_sb_to_u8(const _t_ma_aes_sb *sb, _t_ma_u8 *out);

/**
@function	ma_aes_cmn_key_expansion
@brief		Key expansion implementation based on AES Specs algorithm at section5.2
			KeyExpansion(byte key[4*Nk], word w[Nb*(Nr+1)], Nk)
				Nk	= 4 for 128-bit
				= 6 for 192-bit
				= 8 for 256-bit
				Nb = 4
				Nr = Nk + 6
@param[IN]	p_key: Byte array containing the key with size defined by NK value
@param[OUT]	p_w: Word array containing the key schedule size defined by NK value
@return		NA
@notes
@author		M. Abdelmawla
@date		01 JAN 2018
@version	1.0
*/
void ma_aes_cmn_key_expansion(_t_ma_u8 *p_key, _t_ma_u32 *p_w, _t_ma_u8 nk);

/**
@function	ma_aes_cmn_add_round_key
@brief		Transformation in the Cipher that takes all of the columns of the
			State and mixes their data (independently of one another) to
			produce new columns.
@param[IN, OUT] p_state
@param[IN] 	w: Round keys
@return		No return
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		12 MAY 2019
@version	1.0
*/
void ma_aes_cmn_add_round_key(_t_ma_aes_sb* p_state, const _t_ma_u32 *w);

/**
@function	ma_aes_cmn_mix_columns
@brief		Transformation in the Cipher that takes all of the columns of the 
			State and mixes their data (independently of one another) to 
			produce new columns.
@param[IN, OUT] p_state
@return		No return
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
*/
void ma_aes_cmn_mix_columns(_t_ma_aes_sb* p_state);

/**
@function	ma_aes_cmn_shift_rows
@brief		Transformation in the Cipher that processes the State by cyclically 
			shifting the last three rows of the State by different offsets.
@param[IN,OUT] p_state
@return		No return
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
*/
void ma_aes_cmn_shift_rows(_t_ma_aes_sb* p_state);

/**
@function	ma_aes_cmn_sub_bytes
@brief		Transformation in the Cipher that processes the State using a none
			linear byte substitution table (S-box) that operates on each of the 
			State bytes independently
@param[IN, OUT]	p_state
@return		No return
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		12 MAY 2019
@version	1.0
*/
void ma_aes_cmn_sub_bytes(_t_ma_aes_sb* p_state);

/**
@function	ma_aes_cmn_inv_sub_bytes
@brief		Transformation in the Cipher that processes the State using a none
			linear byte substitution table (inverse S-box) that operates on each of the
			State bytes independently
@param[IN, OUT]	p_state
@return		No return
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		12 MAY 2019
@version	1.0
*/
void ma_aes_cmn_inv_sub_bytes(_t_ma_aes_sb* p_state);
#endif //_MA_AES_COMMON_H_
