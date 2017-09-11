/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Sep 05 10:46:45 2008
 */
/* Compiler settings for G:\¸Ä½ø\Gif\Gif.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Gif_h__
#define __Gif_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICGif_FWD_DEFINED__
#define __ICGif_FWD_DEFINED__
typedef interface ICGif ICGif;
#endif 	/* __ICGif_FWD_DEFINED__ */


#ifndef __CGif_FWD_DEFINED__
#define __CGif_FWD_DEFINED__

#ifdef __cplusplus
typedef class CGif CGif;
#else
typedef struct CGif CGif;
#endif /* __cplusplus */

#endif 	/* __CGif_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ICGif_INTERFACE_DEFINED__
#define __ICGif_INTERFACE_DEFINED__

/* interface ICGif */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICGif;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4EE73DA0-6361-4B01-9D1C-C0E875C97237")
    ICGif : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackStyle( 
            /* [retval][out] */ long __RPC_FAR *pstyle) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderStyle( 
            /* [retval][out] */ long __RPC_FAR *pstyle) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderWidth( 
            /* [in] */ long width) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderWidth( 
            /* [retval][out] */ long __RPC_FAR *width) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DrawMode( 
            /* [in] */ long mode) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DrawMode( 
            /* [retval][out] */ long __RPC_FAR *pmode) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DrawStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DrawStyle( 
            /* [retval][out] */ long __RPC_FAR *pstyle) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DrawWidth( 
            /* [in] */ long width) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DrawWidth( 
            /* [retval][out] */ long __RPC_FAR *pwidth) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FillColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FillColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FillStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FillStyle( 
            /* [retval][out] */ long __RPC_FAR *pstyle) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp __RPC_FAR *pFont) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp __RPC_FAR *pFont) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp __RPC_FAR *__RPC_FAR *ppFont) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ long __RPC_FAR *phwnd) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR strText) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pstrText) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR strCaption) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *pstrCaption) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderVisible( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderVisible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Appearance( 
            /* [in] */ short appearance) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Appearance( 
            /* [retval][out] */ short __RPC_FAR *pappearance) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MousePointer( 
            /* [in] */ long pointer) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MousePointer( 
            /* [retval][out] */ long __RPC_FAR *ppointer) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_MouseIcon( 
            /* [in] */ IPictureDisp __RPC_FAR *pMouseIcon) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseIcon( 
            /* [in] */ IPictureDisp __RPC_FAR *pMouseIcon) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseIcon( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *ppMouseIcon) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Picture( 
            /* [in] */ IPictureDisp __RPC_FAR *pPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ IPictureDisp __RPC_FAR *pPicture) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *ppPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Valid( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Valid( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromFile( 
            LPCTSTR FileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FName( 
            long hParent,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveToFile( 
            BSTR FileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICGifVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICGif __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICGif __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICGif __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICGif __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICGif __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICGif __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICGif __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AutoSize )( 
            ICGif __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AutoSize )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            ICGif __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackStyle )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long style);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackStyle )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pstyle);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BorderColor )( 
            ICGif __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderColor )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BorderStyle )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long style);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderStyle )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pstyle);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BorderWidth )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long width);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderWidth )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *width);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DrawMode )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long mode);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DrawMode )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pmode);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DrawStyle )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long style);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DrawStyle )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pstyle);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DrawWidth )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long width);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DrawWidth )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pwidth);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FillColor )( 
            ICGif __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FillColor )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FillStyle )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long style);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FillStyle )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pstyle);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Font )( 
            ICGif __RPC_FAR * This,
            /* [in] */ IFontDisp __RPC_FAR *pFont);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Font )( 
            ICGif __RPC_FAR * This,
            /* [in] */ IFontDisp __RPC_FAR *pFont);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Font )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ IFontDisp __RPC_FAR *__RPC_FAR *ppFont);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForeColor )( 
            ICGif __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            ICGif __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Window )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *phwnd);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TabStop )( 
            ICGif __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TabStop )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            ICGif __RPC_FAR * This,
            /* [in] */ BSTR strText);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pstrText);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            ICGif __RPC_FAR * This,
            /* [in] */ BSTR strCaption);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pstrCaption);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BorderVisible )( 
            ICGif __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BorderVisible )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Appearance )( 
            ICGif __RPC_FAR * This,
            /* [in] */ short appearance);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Appearance )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pappearance);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MousePointer )( 
            ICGif __RPC_FAR * This,
            /* [in] */ long pointer);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MousePointer )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ppointer);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_MouseIcon )( 
            ICGif __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *pMouseIcon);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MouseIcon )( 
            ICGif __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *pMouseIcon);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MouseIcon )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *ppMouseIcon);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Picture )( 
            ICGif __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *pPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Picture )( 
            ICGif __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *pPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Picture )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *ppPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Valid )( 
            ICGif __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Valid )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFromFile )( 
            ICGif __RPC_FAR * This,
            LPCTSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileName )( 
            ICGif __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileName )( 
            ICGif __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FName )( 
            ICGif __RPC_FAR * This,
            long hParent,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveToFile )( 
            ICGif __RPC_FAR * This,
            BSTR FileName);
        
        END_INTERFACE
    } ICGifVtbl;

    interface ICGif
    {
        CONST_VTBL struct ICGifVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICGif_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICGif_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICGif_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICGif_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICGif_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICGif_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICGif_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICGif_put_AutoSize(This,vbool)	\
    (This)->lpVtbl -> put_AutoSize(This,vbool)

#define ICGif_get_AutoSize(This,pbool)	\
    (This)->lpVtbl -> get_AutoSize(This,pbool)

#define ICGif_put_BackColor(This,clr)	\
    (This)->lpVtbl -> put_BackColor(This,clr)

#define ICGif_get_BackColor(This,pclr)	\
    (This)->lpVtbl -> get_BackColor(This,pclr)

#define ICGif_put_BackStyle(This,style)	\
    (This)->lpVtbl -> put_BackStyle(This,style)

#define ICGif_get_BackStyle(This,pstyle)	\
    (This)->lpVtbl -> get_BackStyle(This,pstyle)

#define ICGif_put_BorderColor(This,clr)	\
    (This)->lpVtbl -> put_BorderColor(This,clr)

#define ICGif_get_BorderColor(This,pclr)	\
    (This)->lpVtbl -> get_BorderColor(This,pclr)

#define ICGif_put_BorderStyle(This,style)	\
    (This)->lpVtbl -> put_BorderStyle(This,style)

#define ICGif_get_BorderStyle(This,pstyle)	\
    (This)->lpVtbl -> get_BorderStyle(This,pstyle)

#define ICGif_put_BorderWidth(This,width)	\
    (This)->lpVtbl -> put_BorderWidth(This,width)

#define ICGif_get_BorderWidth(This,width)	\
    (This)->lpVtbl -> get_BorderWidth(This,width)

#define ICGif_put_DrawMode(This,mode)	\
    (This)->lpVtbl -> put_DrawMode(This,mode)

#define ICGif_get_DrawMode(This,pmode)	\
    (This)->lpVtbl -> get_DrawMode(This,pmode)

#define ICGif_put_DrawStyle(This,style)	\
    (This)->lpVtbl -> put_DrawStyle(This,style)

#define ICGif_get_DrawStyle(This,pstyle)	\
    (This)->lpVtbl -> get_DrawStyle(This,pstyle)

#define ICGif_put_DrawWidth(This,width)	\
    (This)->lpVtbl -> put_DrawWidth(This,width)

#define ICGif_get_DrawWidth(This,pwidth)	\
    (This)->lpVtbl -> get_DrawWidth(This,pwidth)

#define ICGif_put_FillColor(This,clr)	\
    (This)->lpVtbl -> put_FillColor(This,clr)

#define ICGif_get_FillColor(This,pclr)	\
    (This)->lpVtbl -> get_FillColor(This,pclr)

#define ICGif_put_FillStyle(This,style)	\
    (This)->lpVtbl -> put_FillStyle(This,style)

#define ICGif_get_FillStyle(This,pstyle)	\
    (This)->lpVtbl -> get_FillStyle(This,pstyle)

#define ICGif_putref_Font(This,pFont)	\
    (This)->lpVtbl -> putref_Font(This,pFont)

#define ICGif_put_Font(This,pFont)	\
    (This)->lpVtbl -> put_Font(This,pFont)

#define ICGif_get_Font(This,ppFont)	\
    (This)->lpVtbl -> get_Font(This,ppFont)

#define ICGif_put_ForeColor(This,clr)	\
    (This)->lpVtbl -> put_ForeColor(This,clr)

#define ICGif_get_ForeColor(This,pclr)	\
    (This)->lpVtbl -> get_ForeColor(This,pclr)

#define ICGif_put_Enabled(This,vbool)	\
    (This)->lpVtbl -> put_Enabled(This,vbool)

#define ICGif_get_Enabled(This,pbool)	\
    (This)->lpVtbl -> get_Enabled(This,pbool)

#define ICGif_get_Window(This,phwnd)	\
    (This)->lpVtbl -> get_Window(This,phwnd)

#define ICGif_put_TabStop(This,vbool)	\
    (This)->lpVtbl -> put_TabStop(This,vbool)

#define ICGif_get_TabStop(This,pbool)	\
    (This)->lpVtbl -> get_TabStop(This,pbool)

#define ICGif_put_Text(This,strText)	\
    (This)->lpVtbl -> put_Text(This,strText)

#define ICGif_get_Text(This,pstrText)	\
    (This)->lpVtbl -> get_Text(This,pstrText)

#define ICGif_put_Caption(This,strCaption)	\
    (This)->lpVtbl -> put_Caption(This,strCaption)

#define ICGif_get_Caption(This,pstrCaption)	\
    (This)->lpVtbl -> get_Caption(This,pstrCaption)

#define ICGif_put_BorderVisible(This,vbool)	\
    (This)->lpVtbl -> put_BorderVisible(This,vbool)

#define ICGif_get_BorderVisible(This,pbool)	\
    (This)->lpVtbl -> get_BorderVisible(This,pbool)

#define ICGif_put_Appearance(This,appearance)	\
    (This)->lpVtbl -> put_Appearance(This,appearance)

#define ICGif_get_Appearance(This,pappearance)	\
    (This)->lpVtbl -> get_Appearance(This,pappearance)

#define ICGif_put_MousePointer(This,pointer)	\
    (This)->lpVtbl -> put_MousePointer(This,pointer)

#define ICGif_get_MousePointer(This,ppointer)	\
    (This)->lpVtbl -> get_MousePointer(This,ppointer)

#define ICGif_putref_MouseIcon(This,pMouseIcon)	\
    (This)->lpVtbl -> putref_MouseIcon(This,pMouseIcon)

#define ICGif_put_MouseIcon(This,pMouseIcon)	\
    (This)->lpVtbl -> put_MouseIcon(This,pMouseIcon)

#define ICGif_get_MouseIcon(This,ppMouseIcon)	\
    (This)->lpVtbl -> get_MouseIcon(This,ppMouseIcon)

#define ICGif_putref_Picture(This,pPicture)	\
    (This)->lpVtbl -> putref_Picture(This,pPicture)

#define ICGif_put_Picture(This,pPicture)	\
    (This)->lpVtbl -> put_Picture(This,pPicture)

#define ICGif_get_Picture(This,ppPicture)	\
    (This)->lpVtbl -> get_Picture(This,ppPicture)

#define ICGif_put_Valid(This,vbool)	\
    (This)->lpVtbl -> put_Valid(This,vbool)

#define ICGif_get_Valid(This,pbool)	\
    (This)->lpVtbl -> get_Valid(This,pbool)

#define ICGif_LoadFromFile(This,FileName)	\
    (This)->lpVtbl -> LoadFromFile(This,FileName)

#define ICGif_get_FileName(This,pVal)	\
    (This)->lpVtbl -> get_FileName(This,pVal)

#define ICGif_put_FileName(This,newVal)	\
    (This)->lpVtbl -> put_FileName(This,newVal)

#define ICGif_put_FName(This,hParent,newVal)	\
    (This)->lpVtbl -> put_FName(This,hParent,newVal)

#define ICGif_SaveToFile(This,FileName)	\
    (This)->lpVtbl -> SaveToFile(This,FileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_AutoSize_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB ICGif_put_AutoSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_AutoSize_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB ICGif_get_AutoSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_BackColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB ICGif_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_BackColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB ICGif_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_BackStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long style);


void __RPC_STUB ICGif_put_BackStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_BackStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pstyle);


void __RPC_STUB ICGif_get_BackStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_BorderColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB ICGif_put_BorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_BorderColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB ICGif_get_BorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_BorderStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long style);


void __RPC_STUB ICGif_put_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_BorderStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pstyle);


void __RPC_STUB ICGif_get_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_BorderWidth_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long width);


void __RPC_STUB ICGif_put_BorderWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_BorderWidth_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *width);


void __RPC_STUB ICGif_get_BorderWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_DrawMode_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long mode);


void __RPC_STUB ICGif_put_DrawMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_DrawMode_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pmode);


void __RPC_STUB ICGif_get_DrawMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_DrawStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long style);


void __RPC_STUB ICGif_put_DrawStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_DrawStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pstyle);


void __RPC_STUB ICGif_get_DrawStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_DrawWidth_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long width);


void __RPC_STUB ICGif_put_DrawWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_DrawWidth_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pwidth);


void __RPC_STUB ICGif_get_DrawWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_FillColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB ICGif_put_FillColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_FillColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB ICGif_get_FillColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_FillStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long style);


void __RPC_STUB ICGif_put_FillStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_FillStyle_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pstyle);


void __RPC_STUB ICGif_get_FillStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propputref] */ HRESULT STDMETHODCALLTYPE ICGif_putref_Font_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ IFontDisp __RPC_FAR *pFont);


void __RPC_STUB ICGif_putref_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Font_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ IFontDisp __RPC_FAR *pFont);


void __RPC_STUB ICGif_put_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Font_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ IFontDisp __RPC_FAR *__RPC_FAR *ppFont);


void __RPC_STUB ICGif_get_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_ForeColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB ICGif_put_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_ForeColor_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB ICGif_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Enabled_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB ICGif_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Enabled_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB ICGif_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Window_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *phwnd);


void __RPC_STUB ICGif_get_Window_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_TabStop_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB ICGif_put_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_TabStop_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB ICGif_get_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Text_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ BSTR strText);


void __RPC_STUB ICGif_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Text_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pstrText);


void __RPC_STUB ICGif_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Caption_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ BSTR strCaption);


void __RPC_STUB ICGif_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Caption_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pstrCaption);


void __RPC_STUB ICGif_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_BorderVisible_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB ICGif_put_BorderVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_BorderVisible_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB ICGif_get_BorderVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Appearance_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ short appearance);


void __RPC_STUB ICGif_put_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Appearance_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pappearance);


void __RPC_STUB ICGif_get_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_MousePointer_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ long pointer);


void __RPC_STUB ICGif_put_MousePointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_MousePointer_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ppointer);


void __RPC_STUB ICGif_get_MousePointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propputref] */ HRESULT STDMETHODCALLTYPE ICGif_putref_MouseIcon_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *pMouseIcon);


void __RPC_STUB ICGif_putref_MouseIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_MouseIcon_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *pMouseIcon);


void __RPC_STUB ICGif_put_MouseIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_MouseIcon_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *ppMouseIcon);


void __RPC_STUB ICGif_get_MouseIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propputref] */ HRESULT STDMETHODCALLTYPE ICGif_putref_Picture_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *pPicture);


void __RPC_STUB ICGif_putref_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Picture_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *pPicture);


void __RPC_STUB ICGif_put_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Picture_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *ppPicture);


void __RPC_STUB ICGif_get_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_Valid_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB ICGif_put_Valid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_Valid_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB ICGif_get_Valid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICGif_LoadFromFile_Proxy( 
    ICGif __RPC_FAR * This,
    LPCTSTR FileName);


void __RPC_STUB ICGif_LoadFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICGif_get_FileName_Proxy( 
    ICGif __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ICGif_get_FileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_FileName_Proxy( 
    ICGif __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ICGif_put_FileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICGif_put_FName_Proxy( 
    ICGif __RPC_FAR * This,
    long hParent,
    /* [in] */ BSTR newVal);


void __RPC_STUB ICGif_put_FName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICGif_SaveToFile_Proxy( 
    ICGif __RPC_FAR * This,
    BSTR FileName);


void __RPC_STUB ICGif_SaveToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICGif_INTERFACE_DEFINED__ */



#ifndef __GIFLib_LIBRARY_DEFINED__
#define __GIFLib_LIBRARY_DEFINED__

/* library GIFLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_GIFLib;

EXTERN_C const CLSID CLSID_CGif;

#ifdef __cplusplus

class DECLSPEC_UUID("55237D6B-AFA9-4C08-B894-1C8CCBBA029C")
CGif;
#endif
#endif /* __GIFLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
