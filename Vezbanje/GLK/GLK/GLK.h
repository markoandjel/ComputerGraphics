
// GLK.h : main header file for the GLK application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGLKApp:
// See GLK.cpp for the implementation of this class
//

class CLab4PripremaPokusaj2App : public CWinApp
{
public:
	CLab4PripremaPokusaj2App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab4PripremaPokusaj2App theApp;
