
// ParseVideoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxeditbrowsectrl.h"
#include "ffmpeg.h"
#include "afxwin.h"
#include "DlgSdlShow.h"

#define WM_EXPORT_IMAGE					10086


// CParseVideoDlg �Ի���
class CParseVideoDlg : public CDialogEx
{
// ����
public:
	CParseVideoDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CParseVideoDlg();
// �Ի�������
	enum { IDD = IDD_PARSEVIDEO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CDlgSdlShow *m_pdlgsdl;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void ExportImage();

	DECLARE_MESSAGE_MAP()
public:
	// ��Ƶ֡�б�
	CListCtrl m_listFrames;
	// ѡ����������ļ����ؼ�
	CMFCEditBrowseCtrl m_editbrowseInput;
	// ����������ʾ
	CProgressCtrl m_parseProgress;
	afx_msg void OnBnClickedOk();
	BOOL ParseVideo(void);
	CStatic m_outputinfo;
	afx_msg void OnLvnItemchangedListFrames(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	void CleanItemData(void);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnNMRClickListFrames(NMHDR *pNMHDR, LRESULT *pResult);
};
