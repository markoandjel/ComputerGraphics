
// Lab1_Priprema_Pokusaj2.h : main header file for the Lab1_Priprema_Pokusaj2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab1PripremaPokusaj2App:
// See Lab1_Priprema_Pokusaj2.cpp for the implementation of this class
//

class CLab1PripremaPokusaj2App : public CWinApp
{
public:
	CLab1PripremaPokusaj2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab1PripremaPokusaj2App theApp;
