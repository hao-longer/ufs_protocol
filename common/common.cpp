#define _COMMON_C_
#include "..\common\common.h"

void Task_tag_ctl::set_task_tag()
{
    while (TRUE)
    {
        m_task_tag++;
        if (check_task_tag_mask())
        {
            set_task_tag_mask();
            break;
        }
    }
}

BOOL Task_tag_ctl::check_task_tag_mask(void)
{
    U8 offset, shift;
    offset = m_task_tag / 8;
    shift = m_task_tag % 8;

    if (m_task_tag_mask[offset] & BIT(shift)) /* this task tas already been used*/
    {
        return FALSE;
    }
    return TRUE;
}

void Task_tag_ctl::clr_task_tag_mask(U8 task_tag)
{
        U8 offset, shift;
    offset = task_tag / 8;
    shift = task_tag % 8;
    if(m_task_tag_mask[offset] & BIT(shift))
    {
        m_task_tag_mask[offset] &= ~BIT(shift);
    }else{
        std::cout << "task tag no use\n";
        while(1);
    }
}

