// MFC-SerialPort.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCSerialPortApp:
// See MFC-SerialPort.cpp for the implementation of this class
//

class CMFCSerialPortApp : public CWinApp
{
public:
	CMFCSerialPortApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCSerialPortApp theApp;