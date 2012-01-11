// UMS data processorDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CUMSdataprocessorDlg 对话框
class CUMSdataprocessorDlg : public CDialog
{
// 构造
public:
	CUMSdataprocessorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_UMSDATAPROCESSOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cAdress;
	CButton m_cAutoConvert;
	CButton m_cCLine;
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedExit();
	CButton m_cGLine;
	CStatic m_cMax;
	CEdit m_cData;
	CButton m_cLabel;
	afx_msg void OnBnClickedOpen();
	CEdit m_cTime;
	void DrawGraph(void);
	CStatic m_cGraph;
	CSliderCtrl m_cPos1;
	CSliderCtrl m_cPos2;
	CEdit m_cNPos1;
	CEdit m_cNPos2;
	afx_msg void OnBnClickedCline();
	afx_msg void OnBnClickedGline();
	afx_msg void OnBnClickedLabel();
	afx_msg void OnNMCustomdrawPos1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawPos2(NMHDR *pNMHDR, LRESULT *pResult);
	void Calculate(void);
	CEdit m_cResult;
};
