// UMS data processor.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUMSdataprocessorApp:
// �йش����ʵ�֣������ UMS data processor.cpp
//

class CUMSdataprocessorApp : public CWinApp
{
public:
	CUMSdataprocessorApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUMSdataprocessorApp theApp;