// UMS data processorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UMS data processor.h"
#include "UMS data processorDlg.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

__int32 data[1025];
int m_iMax = 0;
bool m_bIsOpen = FALSE;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
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


// CUMSdataprocessorDlg 对话框




CUMSdataprocessorDlg::CUMSdataprocessorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUMSdataprocessorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUMSdataprocessorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADRESS, m_cAdress);
	DDX_Control(pDX, IDC_AUTOCONVERT, m_cAutoConvert);
	DDX_Control(pDX, IDC_CLINE, m_cCLine);
	DDX_Control(pDX, IDC_GLINE, m_cGLine);
	DDX_Control(pDX, IDC_MAX, m_cMax);
	DDX_Control(pDX, IDC_DATA, m_cData);
	DDX_Control(pDX, IDC_LABEL, m_cLabel);
	DDX_Control(pDX, IDC_TIME, m_cTime);
	DDX_Control(pDX, IDC_POS1, m_cPos1);
	DDX_Control(pDX, IDC_POS2, m_cPos2);
	DDX_Control(pDX, IDC_GRAPH, m_cGraph);
	DDX_Control(pDX, IDC_NPOS1, m_cNPos1);
	DDX_Control(pDX, IDC_NPOS2, m_cNPos2);
	DDX_Control(pDX, IDC_POS1, m_cPos1);
	DDX_Control(pDX, IDC_RESULT, m_cResult);
}

BEGIN_MESSAGE_MAP(CUMSdataprocessorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_HSCROLL()/////////////
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ABOUT, &CUMSdataprocessorDlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_EXIT, &CUMSdataprocessorDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_OPEN, &CUMSdataprocessorDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_CLINE, &CUMSdataprocessorDlg::OnBnClickedCline)
	ON_BN_CLICKED(IDC_GLINE, &CUMSdataprocessorDlg::OnBnClickedGline)
	ON_BN_CLICKED(IDC_LABEL, &CUMSdataprocessorDlg::OnBnClickedLabel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_POS1, &CUMSdataprocessorDlg::OnNMCustomdrawPos1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_POS2, &CUMSdataprocessorDlg::OnNMCustomdrawPos2)
END_MESSAGE_MAP()


// CUMSdataprocessorDlg 消息处理程序

BOOL CUMSdataprocessorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_cAutoConvert.SetCheck(TRUE);
	m_cLabel.SetCheck(TRUE);

	m_cPos1.SetRange(1, 1024);
	m_cPos1.SetLineSize(1);
	m_cPos1.SetPageSize(10);
	m_cPos1.SetPos(1);

	m_cPos2.SetRange(1, 1024);
	m_cPos2.SetLineSize(1);
	m_cPos2.SetPageSize(10);
	m_cPos2.SetPos(1024);


	CString temp;
	temp.Format(_T("%d"), m_cPos1.GetPos());
	m_cNPos1.SetWindowTextW(temp);
	temp.Format(_T("%d"), m_cPos2.GetPos());
	m_cNPos2.SetWindowTextW(temp);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUMSdataprocessorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUMSdataprocessorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CUMSdataprocessorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUMSdataprocessorDlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg AboutDlg;
	AboutDlg.DoModal();
}

void CUMSdataprocessorDlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	PostQuitMessage(0);
}

void CUMSdataprocessorDlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	CFile fp;
	CString temp, m_strData;
	//open file
	CFileDialog dlg(true, NULL, NULL, 4|2, _T("Dat File(*.dat)|*.dat|All Files(*.*)|*.*||") );
	if (IDOK == dlg.DoModal())
	{
		m_cAdress.SetWindowTextW(dlg.GetPathName());
		if ((fp.Open(dlg.GetPathName(),CFile::modeRead|CFile::typeBinary)) == NULL)//if 'open' is successful
		{
			AfxMessageBox(_T("Unable to open file!"));
			goto Error;
		}
		//confirm file length
		if(fp.GetLength() != 4106L)
		{
			AfxMessageBox(_T("The length of the file is not right!"));
			goto Error;
		}
		//begin process
		fp.Seek(6L, CFile::begin);
		for (int i = 0; i <= 1024; i++)
		{
			fp.Read(&data[i], sizeof(__int32));
		}
		fp.Close();	
		m_bIsOpen = TRUE;
	
		//find max
		m_iMax = 0;
		for (int i = 0; i <= 1024; i++) if (m_iMax < data[i]) m_iMax = data[i];
		m_iMax = int(m_iMax * 1.1);
		temp.Format(_T("Upper edge = %d"), m_iMax);
		m_cMax.SetWindowTextW(temp);

		//show
		temp.Format(_T("%d"), data[0]);
		m_cTime.SetWindowTextW(temp);
		for (int j = 1; j <= 1024; j++)
		{
			temp.Format(_T("%d\t%d\r\n"), j, data[j]);
			m_strData += temp;
		}
		m_cData.SetWindowTextW(m_strData);
		//output file
		if (m_cAutoConvert.GetCheck())
		{
			temp.Format(_T(".%ds"), data[0]);
			temp = dlg.GetPathName() + temp + _T(".txt");
			if ((fp.Open(temp, CFile::modeCreate|CFile::modeWrite)) == NULL)//if 'write' is successful
				{
					AfxMessageBox(_T("Unable to write file!"));
					goto Error;
				}
	//		m_cData.GetWindowTextW(temp);
	/*		char * szStr; 
			int num=m_strData.GetLength(); 
			szStr=new char[num]; 
			memcpy(szStr,(LPCTSTR)m_strData,num); 
			WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK , m_strData, 0, szStr, sizeof(m_strData), NULL, NULL);
	*/
			fp.Write(m_strData, m_strData.GetLength() * sizeof(wchar_t));
			fp.Flush();
			fp.Close();
		}

		DrawGraph();
	Error:;
	}
}

void CUMSdataprocessorDlg::DrawGraph(void)
{
	if(m_bIsOpen)
	{
		//intialize
		CDC * pDC;
		pDC = m_cGraph.GetWindowDC();
		CRect rect;
		m_cGraph.GetClientRect(rect);
		CPen PenNormal(PS_SOLID, 1, RGB(0, 0, 0));
		CPen PenGrid(PS_DOT ,1, RGB(255, 128, 0));
		CPen PenLabel(PS_SOLID, 2, RGB(0, 0, 0));
		CPen PenPos(PS_SOLID, 1, RGB(0, 0, 255));
		CString temp;
		int i;

		//dubble buffer

		CDC MemDC;
		CBitmap MemBitmap;
		MemDC.CreateCompatibleDC(NULL);
		MemBitmap.CreateCompatibleBitmap(pDC,rect.Width(), rect.Height());
		CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);
		MemDC.FillSolidRect(0,0,rect.Width(),rect.Height(),RGB(255,255,255));

		//clear
		MemDC.FillSolidRect(rect, RGB(255,255,255));
		//start
		//grid line
		if (m_cGLine.GetCheck())
		{
			MemDC.SelectObject(PenGrid);
			for(i = 1; i <= 3; i++)
			{
				MemDC.MoveTo(0, int(double(rect.Height()) / 4 * i));
				MemDC.LineTo(rect.Width(), int(double(rect.Height()) / 4 * i));

				MemDC.MoveTo(int(double(rect.Width()) / 4 * i), 0);
				MemDC.LineTo(int(double(rect.Width()) / 4 * i), rect.Height());
			}
		}
		//label
		if(m_cLabel.GetCheck())
		{
			MemDC.SelectObject(PenLabel);
			for(i = 0; i <= 5; i++)
			{
				MemDC.MoveTo(0, int(double(rect.Height()) / 4 * i));
				MemDC.LineTo(5 * (2 - i % 2), int(double(rect.Height()) / 4 * i));

				MemDC.MoveTo(int(double(rect.Width()) / 4 * i), rect.Height());
				MemDC.LineTo(int(double(rect.Width()) / 4 * i), rect.Height() - 5 * (2 - i % 2));
			}

		}
		//graph
		MemDC.SelectObject(PenNormal);
		MemDC.MoveTo(1,  rect.Height() - int(double(data[1]) / m_iMax * rect.Height() - .5));
		if (m_cCLine.GetCheck())
		{//draw lines
			for(i = 2; i<=1024; i++)
			{
				MemDC.LineTo(int(double(i) / 1024 * rect.Width() - .5), rect.Height() - int(double(data[i]) / m_iMax * rect.Height() - .5));
			}
		}
		else
		{//draw points
			for(i = 1; i<=1024; i++)
			{
				MemDC.SetPixel(int(double(i) / 1024 * rect.Width() - .5), rect.Height() - int(double(data[i]) / m_iMax * rect.Height() - .5),RGB(0,0,0));
			}
		}
		//pos x 2
		MemDC.SelectObject(PenPos);

		MemDC.MoveTo(int(double(m_cPos1.GetPos()) / 1024 * rect.Width()), 0);
		MemDC.LineTo(int(double(m_cPos1.GetPos()) / 1024 * rect.Width()), rect.Height());

		MemDC.MoveTo(int(double(m_cPos2.GetPos()) / 1024 * rect.Width()), 0);
		MemDC.LineTo(int(double(m_cPos2.GetPos()) / 1024 * rect.Width()), rect.Height());

		pDC->BitBlt(0,0,rect.Width(),rect.Height(),&MemDC,0,0,SRCCOPY); 
		MemBitmap.DeleteObject(); 
		MemDC.DeleteDC(); 

		//calculate
		Calculate();
	}
}


void CUMSdataprocessorDlg::OnBnClickedCline()
{
	// TODO: 在此添加控件通知处理程序代码
	DrawGraph();
}

void CUMSdataprocessorDlg::OnBnClickedGline()
{
	// TODO: 在此添加控件通知处理程序代码
	DrawGraph();
}

void CUMSdataprocessorDlg::OnBnClickedLabel()
{
	// TODO: 在此添加控件通知处理程序代码
	DrawGraph();
}



void CUMSdataprocessorDlg::OnNMCustomdrawPos1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	temp.Format(_T("%d"), m_cPos1.GetPos());
	m_cNPos1.SetWindowTextW(temp);
	
	DrawGraph();
	
	*pResult = 0;
}

void CUMSdataprocessorDlg::OnNMCustomdrawPos2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	temp.Format(_T("%d"), m_cPos2.GetPos());
	m_cNPos2.SetWindowTextW(temp);

	DrawGraph();

	*pResult = 0;
}

void CUMSdataprocessorDlg::Calculate(void)
{
	//calculate area
	int i, left, right, area = 0;
	if(m_cPos1.GetPos() < m_cPos2.GetPos())
	{
		left = m_cPos1.GetPos();
		right = m_cPos2.GetPos();
	}
	else
	{
		left = m_cPos2.GetPos();
		right = m_cPos1.GetPos();
	}
	for(i = left; i <= right; i++)
	{
		area += data[i];
	}
	//show
	CString temp;
	temp.Format(
		_T("\r\nLeft Pos:\r\n%d\r\nLeft Count:\r\n%d\r\n\r\nRight Pos:\r\n%d\r\nRight Count:\r\n%d\r\n\r\n------------\r\nArea:\r\n%d"),
		left, data[left], right, data[right], area);
	m_cResult.SetWindowTextW(temp);
}
