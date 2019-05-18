#ifndef _TST_MA_UTILS_H_
#define _TST_MA_UTILS_H_
#include <ma_common.h>
typedef enum _TST_SCOPE_ENUM{
	MA_TST_SCOPE_ALL
} _t_ma_enum_tst_scope;

typedef enum _TST_MODULE_ID_ENUM{
	MA_TST_MODULE_ID_ALL,
	MA_TST_MODULE_ID_CMN,
	MA_TST_MODULE_ID_AES,
	MA_TST_MODULE_ID_DES
} _t_ma_enum_tst_module_id;

typedef _t_ma_err(*_t_tst_ma_fptr)(char*);
_t_ma_err tst_run(
	_t_ma_enum_tst_module_id enum_tst_module_id, 
	_t_ma_enum_tst_scope enum_tst_scope);
#endif //_TST_MA_UTILS_H_
