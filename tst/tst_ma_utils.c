#include "tst_ma_utils.h"
#include "tst_ma_aes_common.h"
#include <stdio.h>

const _t_tst_ma_fptr ga_tst_aes[] = {
	tst_ma_aes_cmn_shift_rows,
	tst_ma_aes_cmn_mix_columns,
	tst_ma_aes_cmn_key_expansion_128,
	tst_ma_aes_cmn_key_expansion_192,
	tst_ma_aes_cmn_key_expansion_256
};

_t_ma_err tst_run(_t_ma_enum_tst_module_id enum_tst_module_id, _t_ma_enum_tst_scope enum_tst_scope){
	_t_ma_err ret = MA_ERR_OK;
	_t_tst_ma_fptr *fp = MA_NULL;
	int N;
	switch (enum_tst_module_id){
		case MA_TST_MODULE_ID_AES:
			fp = (_t_tst_ma_fptr*)ga_tst_aes;
			N = sizeof(ga_tst_aes) / sizeof(_t_tst_ma_fptr);
			break;
		default:
			ret = MA_ERR_NOT_SUPPORTED;
	}

	if (MA_ERR_OK == ret){
		int i;
		_t_ma_err res;
		for (i = 0; i < N; i++){
			char fn_name[128] = { 0 };
			res = fp[i](fn_name);
			printf("[%04d] %s\t\t==> ", i, fn_name);
			if (MA_ERR_OK == res){
				printf("OK\n");
			}
			else {
				printf("ERR%d\n", res);
			}
		}
	}
	return ret;
}