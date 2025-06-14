#ifndef _UFS_VERIFY_H
#define _UFS_VERIFY_H

/*
***author: jackie
***data: 2025/06/01
***Note:The file is used to check whether it complies with the UFS SPEC regulations	
*/

#include "..\type\typedef.h"
#include "..\ufs\ufs.h"

#ifdef _UFS_VERIFY_C
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN U16 gwUpiuSizeChkRlt;    /* upiu size check*/

BOOL upiu_size_check(void);     /* check all upiu size to confirm there are all correct*/
void test_cmd_upiu_combine(void);

#undef EXTERN

#endif
