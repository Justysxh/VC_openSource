#include <stdafx.h>
#include <stdlib.h>
#define XP_NOERROR              0
#define XP_ERROR                1
#define MAXCOLNAME				25
#define MAXNAME					25
#define MAXTEXT					255

#ifdef __cplusplus
extern "C" {
#endif

RETCODE __declspec(dllexport) xp(SRV_PROC *srvproc);

#ifdef __cplusplus
}
#endif

RETCODE __declspec(dllexport) xp(SRV_PROC *srvproc)
{
    DBSMALLINT i = 0;
    DBCHAR colname[MAXCOLNAME];
	DBCHAR spName[MAXNAME];
	DBCHAR spText[MAXTEXT];
	// Name of this procedure
	wsprintf(spName, "xp");
	//Send a text message
	wsprintf(spText, "%s Sample Extended Stored Procedure", spName);
	srv_sendmsg(
		srvproc,
		SRV_MSG_INFO,
		0,
		(DBTINYINT)0,
		(DBTINYINT)0,
		NULL,
		0,
		0,
		spText,
		SRV_NULLTERM);

    wsprintf(colname, "随机数");	//输出标题
    srv_describe(srvproc, 1, colname, SRV_NULLTERM, SRVINT2, sizeof(DBSMALLINT), SRVINT2, sizeof(DBSMALLINT), 0);
	int num = rand();				//获得随机数
	srv_setcoldata(srvproc, 1, &num);
    srv_sendrow(srvproc);
	srv_senddone(srvproc, SRV_DONE_MORE | SRV_DONE_COUNT, (DBUSMALLINT)0, (DBINT)i);
	return  num ;//XP_NOERROR ;
}

