#include "ufs.h"

std::ostream &operator<<(std::ostream &os, const Cmd_upiu_header &upiu_header)  
{
    os << "\t\tm_trans_type = " << upiu_header.m_trans_type << '\n'
        << "\t\tm_flags = " << upiu_header.m_flags << '\n'
        << "\t\tm_lun = " << upiu_header.m_lun << '\n'
        << "\t\tm_task_tag = " << upiu_header.m_task_tag << '\n'
        << "\t\tm_cmd_set_type = " << upiu_header.m_cmd_set_type << '\n'
        << "\t\tm_iid = " << upiu_header.m_iid << '\n'
        << "\t\tm_byte5_rsv = " << upiu_header.m_byte5_rsv << '\n'
        << "\t\tm_byte6_rsv = " << upiu_header.m_byte6_rsv << '\n'
        << "\t\tm_byte7_rsv = " << upiu_header.m_byte7_rsv << '\n'
        << "\t\tm_EHS = " << upiu_header.m_EHS << '\n'
        << "\t\tm_byte9_rsv = " << upiu_header.m_byte9_rsv << '\n'
        << "\t\tm_data_seg_len = " << upiu_header.m_data_seg_len << '\n'
        << "\t\tm_exp_data_trans_len = " << upiu_header.m_exp_data_trans_len << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Scsi_read_06 &read_06)
{
    os << "\t\tm_opcode = " << read_06.m_opcode << '\n'
        << "\t\tm_byte1_high_rsv = " << read_06.m_byte1_high_rsv << '\n'
        << "\t\tm_lba_high = " << read_06.m_lba_high << '\n'
        << "\t\tm_lba_low = " << read_06.m_lba_low << '\n'
        << "\t\tm_trans_len = " << read_06.m_trans_len << '\n'
        << "\t\tm_ctl = " << read_06.m_ctl << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Scsi_read_10 &read_10)
{
    os << "\t\tm_opcode = " << read_10.m_opcode << '\n'
        << "\t\tm_obsolete = " << read_10.m_obsolete << '\n'
        << "\t\tm_fua_NV = " << read_10.m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << read_10.m_rsv0 << '\n'
        << "\t\tm_fua = " << read_10.m_fua << '\n'
        << "\t\tm_dpo = " << read_10.m_dpo << '\n'
        << "\t\tm_RDProtect = " << read_10.m_RDProtect << '\n'
        << "\t\tm_lba = " << read_10.m_lba << '\n'
        << "\t\tm_group_num = " << read_10.m_group_num << '\n'
        << "\t\tm_rsv1 = " << read_10.m_rsv1 << '\n'
        << "\t\tm_trans_len = " << read_10.m_trans_len << '\n'
        << "\t\tm_ctl = " << read_10.m_ctl << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Scsi_read_16 &read_16)
{
    os << "\t\tm_opcode = " << read_16.m_opcode << '\n'
        << "\t\tm_obsolete = " << read_16.m_obsolete << '\n'
        << "\t\tm_fua_NV = " << read_16.m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << read_16.m_rsv0 << '\n'
        << "\t\tm_fua = " << read_16.m_fua << '\n'
        << "\t\tm_dpo = " << read_16.m_dpo << '\n'
        << "\t\tm_RDProtect = " << read_16.m_RDProtect << '\n'
        << "\t\tm_lba = " << read_16.m_lba << '\n'
        << "\t\tm_group_num = " << read_16.m_group_num << '\n'
        << "\t\tm_rsv1 = " << read_16.m_rsv1 << '\n'
        << "\t\tm_trans_len = " << read_16.m_trans_len << '\n'
        << "\t\tm_ctl = " << read_16.m_ctl << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Scsi_write_06 &write_06)
{
    os << "\t\tm_opcode = " << write_06.m_opcode << '\n'
        << "\t\tm_byte1_high_rsv = " << write_06.m_byte1_high_rsv << '\n'
        << "\t\tm_lba_high = " << write_06.m_lba_high << '\n'
        << "\t\tm_lba_low = " << write_06.m_lba_low << '\n'
        << "\t\tm_trans_len = " << write_06.m_trans_len << '\n'
        << "\t\tm_ctl = " << write_06.m_ctl << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Scsi_write_10 &write_10)
{
    os << "\t\tm_opcode = " << write_10.m_opcode << '\n'
        << "\t\tm_obsolete = " << write_10.m_obsolete << '\n'
        << "\t\tm_fua_NV = " << write_10.m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << write_10.m_rsv0 << '\n'
        << "\t\tm_fua = " << write_10.m_fua << '\n'
        << "\t\tm_dpo = " << write_10.m_dpo << '\n'
        << "\t\tm_RDProtect = " << write_10.m_RDProtect << '\n'
        << "\t\tm_lba = " << write_10.m_lba << '\n'
        << "\t\tm_group_num = " << write_10.m_group_num << '\n'
        << "\t\tm_rsv1 = " << write_10.m_rsv1 << '\n'
        << "\t\tm_trans_len = " << write_10.m_trans_len << '\n'
        << "\t\tm_ctl = " << write_10.m_ctl << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Scsi_write_16 &write_16)
{
    os << "\t\tm_opcode = " << write_16.m_opcode << '\n'
        << "\t\tm_obsolete = " << write_16.m_obsolete << '\n'
        << "\t\tm_fua_NV = " << write_16.m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << write_16.m_rsv0 << '\n'
        << "\t\tm_fua = " << write_16.m_fua << '\n'
        << "\t\tm_dpo = " << write_16.m_dpo << '\n'
        << "\t\tm_RDProtect = " << write_16.m_RDProtect << '\n'
        << "\t\tm_lba = " << write_16.m_lba << '\n'
        << "\t\tm_group_num = " << write_16.m_group_num << '\n'
        << "\t\tm_rsv1 = " << write_16.m_rsv1 << '\n'
        << "\t\tm_trans_len = " << write_16.m_trans_len << '\n'
        << "\t\tm_ctl = " << write_16.m_ctl << std::endl;
    return os;
}





