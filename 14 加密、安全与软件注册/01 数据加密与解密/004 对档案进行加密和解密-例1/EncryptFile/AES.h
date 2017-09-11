// AES.h: interface for the CAES class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AES_H__787EA6CD_A461_497A_A0A3_3FE851B9F557__INCLUDED_)
#define AFX_AES_H__787EA6CD_A461_497A_A0A3_3FE851B9F557__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef enum ENUM_KeySize_
{
	 BIT128 = 0,
	 BIT192,
	 BIT256
}ENUM_KEYSIZE;

typedef enum GFCALCMODE_
{
	MODE01 = 0,
	MODE02,
	MODE03,
	MODE09,
	MODE0b,
	MODE0d,
	MODE0e
}GFCALCMODE;

typedef struct BYTE4_
{
	BYTE w[4];
}BYTE4;

class CAES
{
private:
	int Nk,Nr;
	byte (* State)[4],*w[4],*key[4];

	void SubBytes();
	void ShiftRows();
	void MixColumns();
	void AddRoundKey(int round);
	void KeyExpansion();
	void InvShiftRows();
	void InvSubBytes();
	void InvMixColumns();
	BYTE GfCalc(BYTE b,GFCALCMODE Mode);
	void Encrypt(BYTE * input,BYTE * output);
	void Decrypt(BYTE * input,BYTE * output);
	void EncryptBuffer(BYTE * input,int length);
	void DecryptBuffer(BYTE * input,int length);
public:
	CAES();
	virtual ~CAES();

	bool SetKeys(ENUM_KEYSIZE KeySize,CString sKey);
	CString &EncryptString(CString &input);
	CString &DecryptString(CString &input);
	void EncryptFile(CString SourceFile,CString TagerFile);
	void DecryptFile(CString SourceFile,CString TagerFile);
};


#endif // !defined(AFX_AES_H__787EA6CD_A461_497A_A0A3_3FE851B9F557__INCLUDED_)
