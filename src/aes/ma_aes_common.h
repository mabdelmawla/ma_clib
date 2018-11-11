/**
@file		ma_aes_common.h
@brief		This module contains AES Common operation APIs
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
*/

#ifndef _MA_AES_COMMON_H_
#define _MA_AES_COMMON_H_

#include <ma_common.h>

/** 
Defines
*/
#define MA_AES_CMN_NK_128	4
#define MA_AES_CMN_NK_192	6
#define MA_AES_CMN_NK_256	8
#define MA_AES_CMN_GET_NR(nk)	(nk + 6)


/**
Typedefs
*/
typedef _t_ma_u8 _t_ma_aes_blk[16];		/** AES in/out block array */
typedef _t_ma_u8 _t_ma_aes_sb[4][4];	/** State array in bytes */
typedef _t_ma_u32 _t_ma_aes_swc[4];		/** state column word array */

void ma_aes_common_cov_blk_to_swc(_t_ma_aes_swc *swc, _t_ma_aes_blk *blk);
void ma_aes_common_cov_swc_to_blk(_t_ma_aes_blk *blk, _t_ma_aes_swc *swc);

/**
@function	ma_aes_cmn_key_expansion
@brief		Key expansion implementation based on AES Specs algorithm at section5.2
			KeyExpansion(byte key[4*Nk], word w[Nb*(Nr+1)], Nk)
				Nk	= 4 for 128-bit
				= 6 for 192-bit
				= 8 for 256-bit
				Nb = 4
				Nr = Nk + 6
@param[IN]
@return		NA
@notes
@author		M. Abdelmawla
@date		01 JAN 2018
@version	1.0
*/
void ma_aes_cmn_key_expansion(_t_ma_u8 *p_key, _t_ma_u32 *p_w, _t_ma_u8 nk);

/**
@function	ma_aes_cmn_add_round_key
@brief		Transformation in the Cipher and Inverse Cipher in which a Round 
			Key is added to the State using an XOR operation.  The length of a 
			Round Key equals the size of the State (i.e., for Nb= 4, the Round 
			Key length equals 128 bits/16 bytes). 
@param[IN]	
@return		MA_ERR_OK in case of success and suitable error code in case of error
@notes		
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
*/
_t_ma_err ma_aes_cmn_add_round_key(void);

/**
@function	ma_aes_cmn_mix_columns
@brief		Transformation in the Cipher that takes all of the columns of the 
			State and mixes their data (independently of one another) to 
			produce new columns.
@param[IN]
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
@param[IN]
@return		No return
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
*/
void ma_aes_cmn_shift_rows(_t_ma_aes_sb* p_state);

/**
@function	ma_aes_cmn_sub_bytes
@brief		Transformation in the Cipher that processes the State using a non�
			linear byte substitution table (S-box) that operates on each of the 
			State bytes independently
@param[IN]
@return		MA_ERR_OK in case of success and suitable error code in case of error
@notes		This function is designed to be used for both direct and inverse operation
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
*/
_t_ma_err ma_aes_cmn_sub_bytes(void);

#endif //_MA_AES_COMMON_H_