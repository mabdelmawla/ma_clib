/*
 * tst_ma_cmn.c
 *
 *  Created on: May 18, 2019
 *      Author: mabdelmawla
 */

#include <string.h>
#include <ma_common.h>

_t_ma_err tst_ma_cmn_memcpy(char *fn_name){
	_t_ma_err ret = MA_ERR_OK;
	const int sz = 127;
	int i;
	_t_ma_u8 in[sz];
	_t_ma_u8 out[sz];
	memset(out, 0, sz);

	for(i = 0; i < sz; i++){
		in[i] = i+1;
	}

	ma_cmn_memcpy(in,out,sz);

	for(i = 0; i < sz; i++){
		if(in[i] != out[i]){
			ret = MA_ERR_NOT_OK;
			break;
		}
	}

	strcpy(fn_name, __FUNCTION__);
	return ret;
}
