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

std::ostream &Scsi_read_06::operator<<(std::ostream &os)
{
    os << "\t\tm_opcode = " << m_opcode << '\n'
        << "\t\tm_byte1_high_rsv = " << m_byte1_high_rsv << '\n'
        << "\t\tm_lba_high = " << m_lba_high << '\n'
        << "\t\tm_lba_low = " << m_lba_low << '\n'
        << "\t\tm_trans_len = " << m_trans_len << '\n'
        << "\t\tm_ctl = " << m_ctl << std::endl;
    return os;
}

std::ostream &Scsi_read_10::operator<<(std::ostream &os)
{
    os << "\t\tm_opcode = " << m_opcode << '\n'
        << "\t\tm_obsolete = " << m_obsolete << '\n'
        << "\t\tm_fua_NV = " << m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << m_rsv0 << '\n'
        << "\t\tm_fua = " << m_fua << '\n'
        << "\t\tm_dpo = " << m_dpo << '\n'
        << "\t\tm_RDProtect = " << m_RDProtect << '\n'
        << "\t\tm_lba = " << m_lba << '\n'
        << "\t\tm_group_num = " << m_group_num << '\n'
        << "\t\tm_rsv1 = " << m_rsv1 << '\n'
        << "\t\tm_trans_len = " << m_trans_len << '\n'
        << "\t\tm_ctl = " << m_ctl << std::endl;
    return os;
}

std::ostream &Scsi_read_16::operator<<(std::ostream &os)
{
    os << "\t\tm_opcode = " << m_opcode << '\n'
        << "\t\tm_obsolete = " << m_obsolete << '\n'
        << "\t\tm_fua_NV = " << m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << m_rsv0 << '\n'
        << "\t\tm_fua = " << m_fua << '\n'
        << "\t\tm_dpo = " << m_dpo << '\n'
        << "\t\tm_RDProtect = " << m_RDProtect << '\n'
        << "\t\tm_lba = " << m_lba << '\n'
        << "\t\tm_group_num = " << m_group_num << '\n'
        << "\t\tm_rsv1 = " << m_rsv1 << '\n'
        << "\t\tm_trans_len = " << m_trans_len << '\n'
        << "\t\tm_ctl = " << m_ctl << std::endl;
    return os;
}

std::ostream &Scsi_write_06::operator<<(std::ostream &os)
{
    os << "\t\tm_opcode = " << m_opcode << '\n'
        << "\t\tm_byte1_high_rsv = " << m_byte1_high_rsv << '\n'
        << "\t\tm_lba_high = " << m_lba_high << '\n'
        << "\t\tm_lba_low = " << m_lba_low << '\n'
        << "\t\tm_trans_len = " << m_trans_len << '\n'
        << "\t\tm_ctl = " << m_ctl << std::endl;
    return os;
}

std::ostream &Scsi_write_10::operator<<(std::ostream &os)
{
    os << "\t\tm_opcode = " << m_opcode << '\n'
        << "\t\tm_obsolete = " << m_obsolete << '\n'
        << "\t\tm_fua_NV = " << m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << m_rsv0 << '\n'
        << "\t\tm_fua = " << m_fua << '\n'
        << "\t\tm_dpo = " << m_dpo << '\n'
        << "\t\tm_RDProtect = " << m_RDProtect << '\n'
        << "\t\tm_lba = " << m_lba << '\n'
        << "\t\tm_group_num = " << m_group_num << '\n'
        << "\t\tm_rsv1 = " << m_rsv1 << '\n'
        << "\t\tm_trans_len = " << m_trans_len << '\n'
        << "\t\tm_ctl = " << m_ctl << std::endl;
    return os;
}

std::ostream &Scsi_write_16::operator<<(std::ostream &os)
{
    os << "\t\tm_opcode = " << m_opcode << '\n'
        << "\t\tm_obsolete = " << m_obsolete << '\n'
        << "\t\tm_fua_NV = " << m_fua_NV << '\n'
        << "\t\tm_rsv0 = " << m_rsv0 << '\n'
        << "\t\tm_fua = " << m_fua << '\n'
        << "\t\tm_dpo = " << m_dpo << '\n'
        << "\t\tm_RDProtect = " << m_RDProtect << '\n'
        << "\t\tm_lba = " << m_lba << '\n'
        << "\t\tm_group_num = " << m_group_num << '\n'
        << "\t\tm_rsv1 = " << m_rsv1 << '\n'
        << "\t\tm_trans_len = " << m_trans_len << '\n'
        << "\t\tm_ctl = " << m_ctl << std::endl;
    return os;
}





