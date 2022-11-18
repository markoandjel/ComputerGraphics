
// Lab3_Priprema.h : main header file for the Lab3_Priprema application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab3PripremaApp:
// See Lab3_Priprema.cpp for the implementation of this class
//

class CLab3PripremaApp : public CWinApp
{
public:
	CLab3PripremaApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab3PripremaApp theApp;
