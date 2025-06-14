#include<iostream>
#include"ufs\ufs.h"
#include"..\ufs_verify\ufs_verify.h"
#include"..\common\common.h"
#include<iomanip>	

int main(void) {
	
	if(!upiu_size_check())
	{
		std::cout << "upiu header size error, please check 'gwUpiuSizeCheckResult'" << std::endl;
		return 0;
	}


	/*test func*/
	U16 num = 0x89AB;
	//std::cout.setf(std::ios::hex, std::ios::basefield);//设置十六进制显示数值
	//std::cout.setf(std::ios::showbase | std::ios::uppercase);//设置0x头和大写
	std::cout << "num = " << std::hex << std::uppercase << num << '\n';
	std::cout << "endian(num) = " << std::hex << std::uppercase << ENDIAN_16(num) << '\n';

	const Cmd_upiu_header cmd_upiu_header(0, 0, 0);

	std::cout << cmd_upiu_header;

	return 0;
}

