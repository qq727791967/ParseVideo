
// ParseVideo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CParseVideoApp:
// �йش����ʵ�֣������ ParseVideo.cpp
//

class CParseVideoApp : public CWinApp
{
public:
	CParseVideoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CParseVideoApp theApp;