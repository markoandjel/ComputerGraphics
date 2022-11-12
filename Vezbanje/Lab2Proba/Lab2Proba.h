
// Lab2Proba.h : main header file for the Lab2Proba application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab2ProbaApp:
// See Lab2Proba.cpp for the implementation of this class
//

class CLab2ProbaApp : public CWinApp
{
public:
	CLab2ProbaApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab2ProbaApp theApp;
