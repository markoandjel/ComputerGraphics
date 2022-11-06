
// Lab1_Cirko.h : main header file for the Lab1_Cirko application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab1CirkoApp:
// See Lab1_Cirko.cpp for the implementation of this class
//

class CLab1CirkoApp : public CWinApp
{
public:
	CLab1CirkoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab1CirkoApp theApp;
