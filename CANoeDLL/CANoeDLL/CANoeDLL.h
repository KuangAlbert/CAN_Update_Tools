// CANoeDLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

typedef signed char     S8;
typedef unsigned char   U8;
typedef short           S16;
typedef unsigned short  U16;
typedef int             S32;
typedef unsigned int    U32;
typedef long        S64;
typedef unsigned long  U64;

void DataTransfer(U8 InputData[], U8 OutputData[], U32 StartAdrr[], U32 TransferDataLen[]);
