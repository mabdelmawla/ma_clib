#include <stdio.h>
#include "tst_ma_utils.h"
#include "tst_ma_cmn.h"
#include "tst_ma_aes_common.h"
#include "tst_ma_aes.h"

const _t_tst_ma_fptr ga_tst_cmn[] = { tst_ma_cmn_memcpy };

const _t_tst_ma_fptr ga_tst_aes_cmn[] = {
		tst_ma_aes_cmn_add_round_key,
		tst_ma_aes_cmn_shift_rows,
		tst_ma_aes_cmn_inv_shift_rows,
		tst_ma_aes_cmn_mix_columns,
		tst_ma_aes_cmn_inv_mix_columns,
		tst_ma_aes_cmn_key_expansion_128,
		tst_ma_aes_cmn_key_expansion_192,
		tst_ma_aes_cmn_key_expansion_256 };
const _t_tst_ma_fptr ga_tst_aes[] = { tst_ma_aes_ecb_encrypt};

_t_ma_err tst_run(_t_ma_enum_tst_module_id enum_tst_module_id,
		_t_ma_enum_tst_scope enum_tst_scope) {
	_t_ma_err ret = MA_ERR_OK;
	_t_tst_ma_fptr *fp = MA_NULL;
	int N, is_all = 0;
	switch (enum_tst_module_id) {
	case MA_TST_MODULE_ID_ALL:

	case MA_TST_MODULE_ID_CMN:
		fp = (_t_tst_ma_fptr*) ga_tst_cmn;
		N = sizeof(ga_tst_cmn) / sizeof(_t_tst_ma_fptr);
		break;
	case MA_TST_MODULE_ID_AES_CMN:
		fp = (_t_tst_ma_fptr*) ga_tst_aes_cmn;
		N = sizeof(ga_tst_aes_cmn) / sizeof(_t_tst_ma_fptr);
		break;
	case MA_TST_MODULE_ID_AES:
		fp = (_t_tst_ma_fptr*) ga_tst_aes;
		N = sizeof(ga_tst_aes) / sizeof(_t_tst_ma_fptr);
		break;
	default:
		ret = MA_ERR_NOT_SUPPORTED;
	}

	if (MA_ERR_OK == ret) {
		int i;
		_t_ma_err res;
		printf("[%03d] Module Test Start:\n", enum_tst_module_id);
		for (i = 0; i < N; i++) {
			char fn_name[128] = { 0 };
			res = fp[i](fn_name);
			printf("\t[%02d] %s ==> ", i, fn_name);
			if (MA_ERR_OK == res) {
				printf("OK\n");
			} else {
				printf("\033[1;31m"); // change console color to red
				printf("ERR%ld\n", res);
				printf("\033[0;0m"); // reset color change
			}
		}
		printf("[%03d] Module Test End\n",enum_tst_module_id);
	}
	return ret;
}
