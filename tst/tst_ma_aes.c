/*
 * tst_ma_aes.c
 *
 *  Created on: May 18, 2019
 *      Author: mabdelmawla
 */

#include <string.h>
#include "tst_ma_aes.h"
#include <ma_aes.h>

_t_ma_err tst_ma_aes_ecb_encrypt(char *fn_name){
	_t_ma_err ret = MA_ERR_OK;
	int i;

	/*
	 * Input = 32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
Cipher Key = 2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
	 */
	_t_ma_u8 key[16] = {
			0x2b, 0x7e ,0x15 ,0x16,
			0x28 ,0xae ,0xd2 ,0xa6,
			0xab ,0xf7 ,0x15 ,0x88,
			0x09 ,0xcf ,0x4f ,0x3c
	};
	_t_ma_u8 inp[16] = {
			0x32, 0x43, 0xf6, 0xa8,
			0x88, 0x5a, 0x30, 0x8d,
			0x31, 0x31, 0x98, 0xa2,
			0xe0, 0x37, 0x07, 0x34
	};
	_t_ma_u8 ref[16] = {
			0x39, 0x02, 0xdc, 0x19,
			0x25, 0xdc, 0x11, 0x6a,
			0x84, 0x09, 0x85, 0x0b,
			0x1d, 0xfb, 0x97, 0x32
	};
	_t_ma_u8 out[16];

	ma_aes_ecb_encrypt(inp,out,key,MA_AES_NK_128);

	for(i = 0; i < 16; i++){
		if(inp[i] != out[i]){
			ret = MA_ERR_NOT_OK;
			break;
		}
	}

	strcpy(fn_name, __FUNCTION__);
	return ret;
}
