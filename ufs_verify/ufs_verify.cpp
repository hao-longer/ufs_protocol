
#define _UFS_VERIFY_C
#include "ufs_verify.h"
#include "../common/common.h"

BOOL upiu_size_check(void){

	if(sizeof(Cmd_upiu_header) != UPIU_HEADER_SIZE)
	{
 		gwUpiuSizeChkRlt |= BIT(0);
		return FALSE;
	}

	if(sizeof(Resp_upiu_header) != UPIU_HEADER_SIZE)
	{
		gwUpiuSizeChkRlt |= BIT(1);
		return FALSE;	
	}

	if(sizeof(Cdb) != UPIU_HEADER_SIZE)
	{
		gwUpiuSizeChkRlt |= BIT(2);
		return FALSE;	
	}
	
	if(sizeof(Cmd_upiu) != UPIU_SIZE)
	{
		gwUpiuSizeChkRlt |= BIT(3);
		return FALSE;	
	}	

	return TRUE;
}


void test_cmd_upiu_combine(void)
{
	U32 lba;
	U8 trans_len;

	Scsi_write_06 write_06();

	U8 flag;
	U32 exp_trans_len;
	Cmd_upiu cmd_upiu(gTaskTagCtl.get_cur_task_tag(), 0, 0);

}