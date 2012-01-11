// UMS data processorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CUMSdataprocessorDlg �Ի���
class CUMSdataprocessorDlg : public CDialog
{
// ����
public:
	CUMSdataprocessorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_UMSDATAPROCESSOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
