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

// Test vectors reference: FIPS 197, Advanced Encryption Standard (AES)
static _t_str_aes_input gstr_aes_input[] = {
		{
			{
				0x32, 0x43, 0xf6, 0xa8,
				0x88, 0x5a, 0x30, 0x8d,
				0x31, 0x31, 0x98, 0xa2,
				0xe0, 0x37, 0x07, 0x34

			},
			{
				0x2b, 0x7e ,0x15 ,0x16,
				0x28 ,0xae ,0xd2 ,0xa6,
				0xab ,0xf7 ,0x15 ,0x88,
				0x09 ,0xcf ,0x4f ,0x3c
			},
			{
				0x39, 0x25, 0x84, 0x1d,
				0x02, 0xdc, 0x09, 0xfb,
				0xdc, 0x11, 0x85, 0x97,
				0x19, 0x6a, 0x0b, 0x32
			},
			MA_AES_NK_128
		},
		{
			{
				0x00, 0x11, 0x22, 0x33,
				0x44, 0x55, 0x66, 0x77,
				0x88, 0x99 ,0xaa, 0xbb,
				0xcc, 0xdd, 0xee, 0xff

			},
			{
				0x00, 0x01, 0x02, 0x03,
				0x04, 0x05, 0x06, 0x07,
				0x08, 0x09, 0x0a, 0x0b,
				0x0c, 0x0d, 0x0e, 0x0f
			},
			{
				0x69, 0xc4, 0xe0, 0xd8,
				0x6a, 0x7b, 0x04, 0x30,
				0xd8, 0xcd, 0xb7, 0x80,
				0x70, 0xb4, 0xc5, 0x5a
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
			if (gstr_aes_input[j].cipher_txt[i] != out[i]) {
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
