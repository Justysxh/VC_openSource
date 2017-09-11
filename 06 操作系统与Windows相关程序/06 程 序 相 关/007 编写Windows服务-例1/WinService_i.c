/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed May 09 13:27:37 2007
 */
/* Compiler settings for G:\VC\VC经验技巧宝典\程序\用 ATL 编写 Windows 服务\WinService\WinService.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_WINSERVICELib = {0x949AB09E,0xDA08,0x40EF,{0xB8,0x20,0xC9,0xDA,0xC4,0x5E,0xA2,0xA3}};


#ifdef __cplusplus
}
#endif

