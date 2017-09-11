/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Sep 05 10:46:45 2008
 */
/* Compiler settings for G:\¸Ä½ø\Gif\Gif.idl:
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

const IID IID_ICGif = {0x4EE73DA0,0x6361,0x4B01,{0x9D,0x1C,0xC0,0xE8,0x75,0xC9,0x72,0x37}};


const IID LIBID_GIFLib = {0x29117CB0,0xF3A1,0x4012,{0xAC,0x94,0x96,0x64,0x14,0x7F,0xD6,0xFC}};


const CLSID CLSID_CGif = {0x55237D6B,0xAFA9,0x4C08,{0xB8,0x94,0x1C,0x8C,0xCB,0xBA,0x02,0x9C}};


#ifdef __cplusplus
}
#endif

