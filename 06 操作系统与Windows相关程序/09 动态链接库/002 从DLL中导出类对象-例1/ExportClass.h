/*class CMath
{
public:
	int GetMaxCommDiv(int a,int b);//最大公约数
	int __declspec(dllexport)GetMinCommMul(int a,int b);//最小共倍数
};*/
class __declspec(dllexport)CMath
{
public:
	int GetMaxCommDiv(int a,int b);//最大公约数
	int GetMinCommMul(int a,int b);//最小共倍数
};