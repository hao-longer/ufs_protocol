#ifndef _COMMON_H_
#define _COMMON_H_

#include"..\type\typedef.h"
#include<iostream>
#include<array>

#ifdef _COMMON_C_
#define EXTERN
#else
#define EXTERN extern
#endif // DEBUG

/*
***The current version is set to support up to 128 tasks to execute simultaneously at most, 
    ensuring that task tags will not be exhausted
*/
class Task_tag_ctl
{
public:
    Task_tag_ctl() = default;
    U8 get_cur_task_tag() 
    { 
        return m_task_tag;
    }
    void set_task_tag();
    
private:
    U8 m_task_tag = 0;              /* */
    std::array <U8, 32> m_task_tag_mask = {0};   /* task tag range is 0~255, so need 256 bit*/
    U8 counter = 0;                 /* record send task count*/

    BOOL check_task_tag_mask(void);
    void clr_task_tag_mask(U8 task_tag);
    void set_task_tag_mask(void)
    {
        U8 offset, shift;
        offset = m_task_tag / 8;
        shift = m_task_tag % 8;
        m_task_tag_mask[offset] |= BIT(shift);
    }
};

EXTERN Task_tag_ctl gTaskTagCtl;

#define ENDIAN_16(x)    (((x & 0xFF) << 8) | ((x >> 8) & 0xFF))
#define ENDIAN_32(x)    ()





#undef EXTERN

#endif
