#include "ExportClass.h"
#include "windows.h"//使用了MessageBox函数所以要加入此头文件引用
//最大公约数
int CMath::GetMaxCommDiv(int a,int b)
{
	int x=1;//a,b保存相除后的结果
	int ires;//保存结构
    if(a<b)
	{
		MessageBox(NULL,"a不能小于b","出错",MB_OK);
		return 0;
	}
	if(b==0)
	{
		MessageBox(NULL,"b不能为0","出错",MB_OK);
		return 0;
	}
    while(x!=0)
	{
		x=a%b;
        a=b;
		ires=b;
		b=x;
	}
	return ires;
}
//最小共倍数
int CMath::GetMinCommMul(int a,int b)
{
	int x=1;//a,b保存相除后的结果
	int ires;//保存结果
	int m,n;//存储临时的a,b值
	m=a;n=b;
    if(a<b)
	{
		MessageBox(NULL,"a不能小于b","出错",MB_OK);
		return 0;
	}
	if(a==0)
	{
		MessageBox(NULL,"a不能为0","出错",MB_OK);
		return 0;
	}
	if(b==0)
	{
		MessageBox(NULL,"b不能为0","出错",MB_OK);
		return 0;
	}
	
    while(x!=0)
	{
		x=a%b;
        a=b;
		ires=b;
		b=x;
	}
	ires=(m*n)/(ires);
	return ires;
}