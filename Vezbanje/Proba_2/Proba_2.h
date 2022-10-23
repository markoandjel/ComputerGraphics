
// Proba_2.h : main header file for the Proba_2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProba2App:
// See Proba_2.cpp for the implementation of this class
//

class CProba2App : public CWinApp
{
public:
	CProba2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProba2App theApp;
