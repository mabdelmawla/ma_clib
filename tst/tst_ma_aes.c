/*
 * tst_ma_aes.c
 *
 *  Created on: May 18, 2019
 *      Author: mabdelmawla
 */

#include <string.h>
#include <stdio.h>
#include "tst_ma_aes.h"
#include <ma_aes.h>

typedef __attribute__((aligned(4))) struct _t_str_aes_input_ {
	_t_ma_u8 plain_txt[16];
	_t_ma_u8 key[16];
	_t_ma_u8 cipher_txt[16];
	_t_ma_u8 nk;
} _t_str_aes_input;

static _t_str_aes_input gstr_aes_input[] = {
		{
			{
				0x32, 0x43, 0xf6, 0xa8,
				0x88, 0x5a, 0x30, 0x8d,
				0x31, 0x31, 0x98, 0xa2,
				0xe0, 0x37, 0x07, 0x34

			},
			{
				0x2b, 0x7e ,0x15 ,0x1,
				0x28 ,0xae ,0xd2 ,0xa6,
				0xab ,0xf7 ,0x15 ,0x88,
				0x09 ,0xcf ,0x4f ,0x3c
			},
			{
				0x39, 0x02, 0xdc, 0x19,
				0x25, 0xdc, 0x11, 0x6a,
				0x84, 0x09, 0x85, 0x0b,
				0x1d, 0xfb, 0x97, 0x32
			},
			MA_AES_NK_128
		},
};

_t_ma_err tst_ma_aes_ecb_encrypt(char *fn_name){
	int i, j;
	_t_ma_err ret = MA_ERR_OK;
	_t_ma_u8 out[16];

	for (j = 0; j < (sizeof(gstr_aes_input) / sizeof(_t_str_aes_input)); j++) {
		_t_ma_err local_ret = MA_ERR_OK;
		ma_aes_ecb_encrypt(
				gstr_aes_input[j].plain_txt,
				out,
				gstr_aes_input[j].key,
				gstr_aes_input[j].nk
				);
		for (i = 0; i < 16; i++) {
			if (gstr_aes_input[0].cipher_txt[i] != out[i]) {
				ret = MA_ERR_NOT_OK;
				local_ret = MA_ERR_NOT_OK;
				break;
			}
		}
		printf("\t\t[TV%02d] %s ==> ", j, __FUNCTION__);
		if(MA_ERR_OK == local_ret){
			printf("OK\n");
		} else {
			printf("\033[1;31m"); // change console color to red
			printf("ERR%ld\n", local_ret);
			printf("\033[0;0m"); // reset color change
		}
	}

	strcpy(fn_name, __FUNCTION__);
	return ret;
}
