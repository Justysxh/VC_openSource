
Gifps.dll: dlldata.obj Gif_p.obj Gif_i.obj
	link /dll /out:Gifps.dll /def:Gifps.def /entry:DllMain dlldata.obj Gif_p.obj Gif_i.obj \
		mtxih.lib mtx.lib mtxguid.lib \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
		ole32.lib advapi32.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		/MD \
		$<

clean:
	@del Gifps.dll
	@del Gifps.lib
	@del Gifps.exp
	@del dlldata.obj
	@del Gif_p.obj
	@del Gif_i.obj
