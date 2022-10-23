
// Proba_1.h : main header file for the Proba_1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProba1App:
// See Proba_1.cpp for the implementation of this class
//

class CProba1App : public CWinApp
{
public:
	CProba1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProba1App theApp;
