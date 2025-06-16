
#define _UFS_VERIFY_C
#include "ufs_verify.h"
#include "../common/common.h"

void verify_all_case(void)
{
#if ENABLE_VERIFY_FLOW
	upiu_size_check();
	if(gwUpiuSizeChkRlt)
	{
		std::cout << "upiu size check fail, gwUpiuSizeChkRlt = " << gwUpiuSizeChkRlt << std::endl;
	}
	test_cmd_upiu_combine();
	test_cout();
#else
	//no need verify anything
#endif
}


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


void test_cout(void)
{
	Cmd_upiu_header upiu_header(0, 0, 0);

	Scsi_read_06 read_06(0, 0, 0);
	Scsi_read_10 read_10(0, 0);
	Scsi_read_16 read_16(0, 0);

	Scsi_write_06 write_06(0, 0, 0);
	Scsi_write_10 write_10(0, 0);
	Scsi_write_16 write_16(0, 0);

	std::cout << "upiu_header: " << '\n';
	std::cout << upiu_header << '\n';

	std::cout << "read_06: " << '\n';
	std::cout << read_06 << '\n';

	std::cout << "read_10: " << '\n';
	std::cout << read_10 << '\n';

	std::cout << "read_16: " << '\n';
	std::cout << read_16 << '\n';

	std::cout << "write_06: " << '\n';
	std::cout << write_06 << '\n';

	std::cout << "write_10: " << '\n';
	std::cout << write_10 << '\n';

	std::cout << "write_16: " << '\n';
	std::cout << write_16 << '\n';
	std::cout << std::endl;
}


