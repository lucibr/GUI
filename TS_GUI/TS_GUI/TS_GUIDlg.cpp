
// TS_GUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TS_GUI.h"
#include "TS_GUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTS_GUIDlg dialog



CTS_GUIDlg::CTS_GUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TS_GUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTS_GUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTS_GUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCLOSE, &CTS_GUIDlg::OnBnClickedClose)
END_MESSAGE_MAP()


// CTS_GUIDlg message handlers

BOOL CTS_GUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	RECT r;
	int screen_x_size, screen_y_size, dim_x, dim_y, aux_x, aux_y;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	screen_x_size = rect.Width();
	screen_y_size = rect.Height();
	SetWindowPos(NULL, -1, -1, screen_x_size, screen_y_size, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	CWnd *elem;

	//Pozitionare buton inchidere
	elem = GetDlgItem(IDCLOSE);
	elem->GetWindowRect(&r);
	dim_y = r.bottom - r.top;
	dim_x = r.right - r.left;
	elem->MoveWindow(screen_x_size-(dim_x+0.02*screen_x_size), screen_y_size-(dim_y + 0.07*screen_y_size), dim_x, dim_y);

	//Pozitionare buton restart
	elem = GetDlgItem(IDREFRESH);
	elem->GetWindowRect(&r);
	dim_x = r.right - r.left;
	elem->MoveWindow(0.01*screen_x_size, screen_y_size - (dim_y + 0.07*screen_y_size), dim_x, dim_y);
	
	//Pozitionare text cale folder
	elem = GetDlgItem(IDC_STATIC_TEXTCALE);
	elem->GetWindowRect(&r);
	aux_y = r.bottom - r.top;
	aux_x = r.right - r.left;
	elem->MoveWindow(0.01*screen_x_size, screen_y_size - (dim_y + 0.07*screen_y_size + 2*aux_y), aux_x, dim_y);
	aux_x = r.right;

	//Pozitionare control alegere folder
	elem = GetDlgItem(IDC_CALE_IMG);
	elem->GetWindowRect(&r);
	dim_y = r.bottom - r.top;
	elem->MoveWindow(aux_x + 0.01*screen_x_size, screen_y_size - (dim_y + 0.07*screen_y_size + 2 * aux_y), screen_x_size - (aux_x + 0.01*screen_x_size + screen_x_size*0.02), dim_y);

	//Pozitionare chenar configurari procesare
	elem = GetDlgItem(IDC_CONFIG_PAN);
	elem->GetWindowRect(&r);
	elem->MoveWindow(0.01*screen_x_size, 0.02*screen_y_size, 0.24*screen_x_size, 0.4*screen_y_size);

	//Pozitionare chenar statistici
	elem = GetDlgItem(IDC_STAT_PAN);
	elem->GetWindowRect(&r);
	elem->MoveWindow(0.01*screen_x_size, 0.44*screen_y_size, 0.24*screen_x_size, 0.4*screen_y_size);

	//Pozitionare chenar diplay imagini
	elem = GetDlgItem(IDC_IMG_DISP);
	elem->GetWindowRect(&r);
	elem->MoveWindow(0.26*screen_x_size, 0.02*screen_y_size, 0.72*screen_x_size, 0.82*screen_y_size);

	//Pozitionare zona imagine marita camera 1
	elem = GetDlgItem(IDC_IMG_CAM1);
	elem->MoveWindow(0.47*screen_x_size, 0.10*screen_y_size, 0.3*screen_x_size, 0.36*screen_y_size);

	//Pozitionare zona imagine camera 1 - previuos
	elem = GetDlgItem(IDC_IMG_CAM1_PREV);
	elem->MoveWindow(0.28*screen_x_size, 0.19*screen_y_size, 0.15*screen_x_size, 0.18*screen_y_size);

	//Pozitionare zona imagine camera 1 - next
	elem = GetDlgItem(IDC_IMG_CAM1_NEXT);
	elem->MoveWindow(0.81*screen_x_size, 0.19*screen_y_size, 0.15*screen_x_size, 0.18*screen_y_size);

	//Pozitionare zona imagine marita camera 2
	elem = GetDlgItem(IDC_IMG_CAM2);
	elem->MoveWindow(0.47*screen_x_size, 0.46*screen_y_size, 0.3*screen_x_size, 0.36*screen_y_size);

	//Pozitionare zona imagine camera 2 - previuos
	elem = GetDlgItem(IDC_IMG_CAM2_PREV);
	elem->MoveWindow(0.28*screen_x_size, 0.55*screen_y_size, 0.15*screen_x_size, 0.18*screen_y_size);

	//Pozitionare zona imagine camera 2 - next
	elem = GetDlgItem(IDC_IMG_CAM2_NEXT);
	elem->MoveWindow(0.81*screen_x_size, 0.55*screen_y_size, 0.15*screen_x_size, 0.18*screen_y_size);

	//Pozitionare slider imagini
	elem = GetDlgItem(IDC_IMG_SLIDER);
	elem->MoveWindow(0.27*screen_x_size, 0.055*screen_y_size, 0.70*screen_x_size, 0.03*screen_y_size);

	//Pozitionare spin imagini
	elem = GetDlgItem(IDC_SPIN_IMG);
	elem->MoveWindow(0.58*screen_x_size, 0.035*screen_y_size, 0.04*screen_x_size, 0.025*screen_y_size);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTS_GUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTS_GUIDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTS_GUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTS_GUIDlg::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDCLOSE);
}
