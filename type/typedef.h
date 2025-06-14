#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#define USING_NOT_TYPEDEF		(1)     /* config?*/

#define TRUE    (1)
#define FALSE   (0)

#define BIT(n)  ((U64)1 << n)

#if USING_NOT_TYPEDEF
using BOOL = unsigned char;
using U8 = unsigned char;
using U16 = unsigned short;
using U32 = unsigned long;
using U64 = unsigned long long;
#else
typedef unsigned char		BOOL;
typedef unsigned char		U8;
typedef unsigned short		U16;
typedef unsigned long		U32;
typedef unsigned long long U64;
#endif






#endif

