// MFC-SerialPortDlg.h : header file
//

#pragma once

#include "CSerialPort\SerialPort.h"
#include <vector>
#include "afxwin.h"

using std::vector ;

// CMFCSerialPortDlg dialog
class CMFCSerialPortDlg : public CDialog
{
// Construction
public:
	CMFCSerialPortDlg(CWnd* pParent = NULL);	// standard constructor
    CSerialPort   m_SerialPort;

// Dialog Data
	enum { IDD = IDD_MFCSERIALPORT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL DestroyWindow();
	int OpenSerialPort(void);
};
