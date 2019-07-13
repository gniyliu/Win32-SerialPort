// MFC-SerialPortDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-SerialPort.h"
#include "MFC-SerialPortDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMFCSerialPortDlg dialog




CMFCSerialPortDlg::CMFCSerialPortDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCSerialPortDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSerialPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSerialPortDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void OpenConsole(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	SMALL_RECT srctWindow;//console界面结构
	AllocConsole();//产生一个console界面
	HANDLE hdlWrite = GetStdHandle(STD_OUTPUT_HANDLE);//获取console句柄
	GetConsoleScreenBufferInfo(hdlWrite, &csbiInfo);

	SMALL_RECT rc = {0,0, 80, 30}; // 重置窗口位置和大小
	BOOL bset=SetConsoleWindowInfo(hdlWrite,TRUE ,&rc);//设置界面大小

	SetConsoleTitle("Console");//设置Title
	freopen( "CONOUT$","w",stdout);//支持中文显示
	printf( "Welcome to console!\n" );
//	printf("salary:%d\n",50000);
//	FreeConsole();//释放Console
// CMFCSerialPortDlg message handlers
}

void CloseConsole(void)
{
	FreeConsole();
}


BOOL CMFCSerialPortDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	OpenConsole();
	OpenSerialPort();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCSerialPortDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCSerialPortDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCSerialPortDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CMFCSerialPortDlg::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	m_SerialPort.ClosePort();

	return CDialog::DestroyWindow();
}

int CMFCSerialPortDlg::OpenSerialPort(void)
{
		if(m_SerialPort.InitPort(this->m_hWnd,12,115200, \
			'N', 8, ONESTOPBIT, EV_RXFLAG | EV_RXCHAR, 512))
	    {     
		  m_SerialPort.StartMonitoring();

//          m_bSerialPortOpened=TRUE;
//		  GetDlgItem(ID_OPEN_COM)->SetWindowText("关闭");

//          memset(m_UartRecByteBuf, 0, sizeof(m_UartRecByteBuf));
//          m_Pointer= 0;
	    }
    	else
		{    
            AfxMessageBox("打开串口失败");
//             m_bSerialPortOpened=FALSE;
//			 m_openCommError = 1;
		}

	return 0;
}
