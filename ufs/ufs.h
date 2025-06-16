#ifndef _UFS_H_
#define _UFS_H_

/*
***author:jackie
***data: 2025/05/31
**Note: There are too many members. It's rather troublesome to assign values using the parameter list. \
		Just directly use the initial values within the class for assignment
*/

#include"..\type\typedef.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>

/*
note£º
***If there is a virtual function, there will be a virtual function table vftable, 
	which will cause sizeof to increase and will not conform to the SPEC
***Pay attention to the compilation environment. It is recommended to use win32 to 
	avoid size errors caused by the pointer occupying 8 bytes
*/
#define TRANS_TYPE_MASK (0x3F)
#define TRANS_TYPE_SHIFT (0x00)
/*initiator to targte(host to device)*/
#define TRANS_TYPE_NOP_OUT (0x00)
#define TRANS_TYPE_CMD (0x01)
#define TRANS_TYPE_DATA_OUT (0x02)
#define TRANS_TYPE_TASK_MANAG (0x04)
#define TRANS_TYPE_QUERY (0x16)
/*target to initiator(device to host)*/
#define TRANS_TYPE_NOP_IN (0x20)
#define TRANS_TYPE_RESP (0x21)
#define TRANS_TYPE_DATA_IN (0x22)
#define TRANS_TYPE_TASK_MANAG_RESP (0x24)
#define TRANS_TYPE_RTT (0x31)
#define TRANS_TYPE_QUERY_RESP (0x36)
#define TRANS_TYPE_REJECT (0x3F)


/*
	temp define
*/
#define UPIU_HEADER_SIZE	(16)
#define UPIU_SIZE			(32)


#pragma pack(1) /* align 1 byte*/

/*define cmd upiu header*/
class Cmd_upiu_header
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Cmd_upiu_header &upiu_header);

	/* user only care about important parameter*/
	Cmd_upiu_header(U8 task_tag, U8 flags, U32 exp_data_trans_len, U8 lun = 0, U8 cmd_set_type = 0, U8 iid = 0) : 
	m_task_tag(task_tag), m_flags(flags), m_lun(lun), m_cmd_set_type(cmd_set_type & 0x0F), 
	m_iid(iid & 0x0F), m_exp_data_trans_len(exp_data_trans_len) {}

	/* The subsequent error check can be defined as an friend function*/
private:
	U8 m_trans_type = TRANS_TYPE_CMD;
	U8 m_flags = 0;
	U8 m_lun = 0;
	U8 m_task_tag;

	U8 m_cmd_set_type : 4;
	U8 m_iid : 4;
	U8 m_byte5_rsv = 0;
	U8 m_byte6_rsv = 0;
	U8 m_byte7_rsv = 0;

	U8 m_EHS = 0;
	U8 m_byte9_rsv = 0;
	U16 m_data_seg_len = 0;
	U32 m_exp_data_trans_len = 0;
};


/*define response upiu header*/
class Resp_upiu_header
{
public:
	Resp_upiu_header(U8 task_tag, U8 response, U8 status = 0, U8 lun = 0, U8 flags = 0, U32 residual_trans_cnt = 0, U8 device_info = 0, U8 cmd_set_type = 0, U8 iid = 0) : 
	m_task_tag(task_tag), m_resp(response), m_status(status), m_lun(lun), m_flags(flags),
	m_residual_trans_cnt(residual_trans_cnt), m_device_info(device_info), m_cmd_set_type(cmd_set_type & 0x0F), m_iid(iid & 0x0F) {}

private:
	U8 m_trans_type = TRANS_TYPE_RESP;
	U8 m_flags = 0;
	U8 m_lun = 0;
	U8 m_task_tag;

	U8 m_cmd_set_type : 4;
	U8 m_iid : 4;
	U8 m_byte5_rsv = 0;
	U8 m_resp = 0;
	U8 m_status = 0;

	U8 m_EHS = 0;
	U8 m_device_info = 0;
	U16 m_data_seg_len = 0;
	U32 m_residual_trans_cnt = 0;
};


/* define cmd upiu cdb*/
class Cdb{
public:
	Cdb() = default;
	void assign(void *src_ptr, U8 len)
	{
		if(len > 16)
		{
			std::cout << "CDB length overflow" << std::endl;
			while(1);
		}
		if(src_ptr != nullptr){
			memcpy(m_cdb, src_ptr, len);
		}
	}
private:
	U8 m_cdb[16] = {0};	/* default value*/
};


/* define cmd upiu*/
class Cmd_upiu : public Cmd_upiu_header, protected Cdb{		/* */
public:
	Cmd_upiu(U8 task_tag, U8 flags, U32 exp_data_trans_len, U8 lun = 0, U8 cmd_set_type = 0, U8 iid = 0) : 
		Cmd_upiu_header(task_tag, flags, exp_data_trans_len, lun, cmd_set_type, iid), Cdb() {}
	void scsi_cdb_assign(void *src_ptr, U8 len)
	{
		assign(src_ptr, len);
	}
private:
};


/* define scsi cmd*/
class Scsi_read_06
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Scsi_read_06 &read_06);

	Scsi_read_06(U8 lba_h, U16 lba_l, U8 trans_len) : 
	m_lba_high(lba_h & 0x0F), m_lba_low(lba_l), m_trans_len(trans_len){}
	
private:
	U8 m_opcode = 0x08;
	U8 m_byte1_high_rsv : 4;
	U8 m_lba_high : 4;
	U16 m_lba_low;
	U8 m_trans_len;
	U8 m_ctl = 0;
};

class Scsi_read_10
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Scsi_read_10 &read_10);

	Scsi_read_10(U32 lba, U16 trans_len, BOOL fua_en = 0, BOOL dpo_en = 0, U8 group_num = 0) : 
	m_lba(lba),  m_trans_len(trans_len), m_fua(fua_en), m_dpo(dpo_en), 
	m_obsolete(0), m_fua_NV(0), m_rsv0(0), m_RDProtect(0), m_group_num(group_num), m_rsv1(0){}
	
private:
	U8 m_opcode = 0x28;
	U8 m_obsolete : 1;
	U8 m_fua_NV : 1;
	U8 m_rsv0 : 1;
	U8 m_fua : 1;
	U8 m_dpo : 1;
	U8 m_RDProtect : 3;
	U32 m_lba;
	U8 m_group_num : 4;
	U8 m_rsv1 : 4;
	U16 m_trans_len;
	U8 m_ctl = 0;
};

class Scsi_read_16
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Scsi_read_16 &read_16);

	Scsi_read_16(U64 lba, U32 trans_len, BOOL fua_en = 0, BOOL dpo_en = 0, U8 group_num = 0) : 
	m_lba(lba),  m_trans_len(trans_len), m_fua(fua_en), m_dpo(dpo_en), 
	m_obsolete(0), m_fua_NV(0), m_rsv0(0), m_RDProtect(0), m_group_num(group_num), m_rsv1(0){}

private:
	U8 m_opcode = 0x28;
	U8 m_obsolete : 1;
	U8 m_fua_NV : 1;
	U8 m_rsv0 : 1;
	U8 m_fua : 1;
	U8 m_dpo : 1;
	U8 m_RDProtect : 3;
	U64 m_lba;
	U8 m_group_num : 4;
	U8 m_rsv1 : 4;
	U32 m_trans_len;
	U8 m_ctl = 0;
};


class Scsi_write_06
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Scsi_write_06 &write_06);

	Scsi_write_06(U8 lba_h, U16 lba_l, U8 trans_len) : 
	m_lba_high(lba_h & 0x0F), m_lba_low(lba_l), m_trans_len(trans_len){}

private:
	U8 m_opcode = 0x08;
	U8 m_byte1_high_rsv : 4;
	U8 m_lba_high : 4;
	U16 m_lba_low;
	U8 m_trans_len;
	U8 m_ctl = 0;
};


class Scsi_write_10
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Scsi_write_10 &write_10);

	Scsi_write_10(U32 lba, U16 trans_len, BOOL fua_en = 0, BOOL dpo_en = 0, U8 group_num = 0) : 
	m_lba(lba),  m_trans_len(trans_len), m_fua(fua_en), m_dpo(dpo_en), 
	m_obsolete(0), m_fua_NV(0), m_rsv0(0), m_RDProtect(0), m_group_num(group_num), m_rsv1(0){}

private:
	U8 m_opcode = 0x28;
	U8 m_obsolete : 1;
	U8 m_fua_NV : 1;
	U8 m_rsv0 : 1;
	U8 m_fua : 1;
	U8 m_dpo : 1;
	U8 m_RDProtect : 3;
	U32 m_lba;
	U8 m_group_num : 4;
	U8 m_rsv1 : 4;
	U16 m_trans_len;
	U8 m_ctl = 0;
};

class Scsi_write_16
{
public:
	friend std::ostream &operator<<(std::ostream &os, const Scsi_write_16 &write_16);

	Scsi_write_16(U64 lba, U32 trans_len, BOOL fua_en = 0, BOOL dpo_en = 0, U8 group_num = 0) : 
	m_lba(lba),  m_trans_len(trans_len), m_fua(fua_en), m_dpo(dpo_en), 
	m_obsolete(0), m_fua_NV(0), m_rsv0(0), m_RDProtect(0), m_group_num(group_num), m_rsv1(0){}

private:
	U8 m_opcode = 0x28;
	U8 m_obsolete : 1;
	U8 m_fua_NV : 1;
	U8 m_rsv0 : 1;
	U8 m_fua : 1;
	U8 m_dpo : 1;
	U8 m_RDProtect : 3;
	U64 m_lba;
	U8 m_group_num : 4;
	U8 m_rsv1 : 4;
	U32 m_trans_len;
	U8 m_ctl = 0;
};

extern std::ostream &operator<<(std::ostream &os, const Cmd_upiu_header &upiu_header);
extern std::ostream &operator<<(std::ostream &os, const Scsi_read_06 &read_06);
extern std::ostream &operator<<(std::ostream &os, const Scsi_read_10 &read_10);
extern std::ostream &operator<<(std::ostream &os, const Scsi_read_16 &read_16);
extern std::ostream &operator<<(std::ostream &os, const Scsi_write_06 &write_06);
extern std::ostream &operator<<(std::ostream &os, const Scsi_write_10 &write_10);
extern std::ostream &operator<<(std::ostream &os, const Scsi_write_16 &write_16);

#pragma pack()

#endif
