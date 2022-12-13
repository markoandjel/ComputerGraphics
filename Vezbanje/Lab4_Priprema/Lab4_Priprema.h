
// Lab4_Priprema.h : main header file for the Lab4_Priprema application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab4PripremaApp:
// See Lab4_Priprema.cpp for the implementation of this class
//

class CLab4PripremaApp : public CWinApp
{
public:
	CLab4PripremaApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab4PripremaApp theApp;
