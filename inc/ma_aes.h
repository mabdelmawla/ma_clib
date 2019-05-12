/**
@file		ma_aes.h
@brief		This module contains AES APIs declaration
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
#ifndef _MA_AES_H_
#define _MA_AES_H_
#include "ma_common.h"

/**
@function	ma_aes_ecb_encrypt
@brief		Perform AEC ECB encryption
@param[IN]	in: Input block array in bytes
@param[OUT]	out: Output block array in bytes
@param[IN]	key: Key array in bytes with size defined by NK
@param[IN]	NK: Can be (ONLY) one of the following MACRO values depending on the desired key size
					MA_AES_CMN_NK_128
					MA_AES_CMN_NK_192
					MA_AES_CMN_NK_256
@return		NO Return
@notes		No input parameters error checking is performed. The caller is responsible for the validity of the passed parameters
@author		M. Abdelmawla
@date		12 MAY 2019
@version	1.0
*/
void ma_aes_ecb_encrypt(_t_ma_u8 *in, _t_ma_u8 *out, _t_ma_u8 *key, _t_ma_u8 nk);
#endif //_MA_AES_H_
