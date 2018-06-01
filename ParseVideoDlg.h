
// ParseVideoDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxeditbrowsectrl.h"
#include "ffmpeg.h"
#include "afxwin.h"
#include "DlgSdlShow.h"

#define WM_EXPORT_IMAGE					10086


// CParseVideoDlg 对话框
class CParseVideoDlg : public CDialogEx
{
// 构造
public:
	CParseVideoDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CParseVideoDlg();
// 对话框数据
	enum { IDD = IDD_PARSEVIDEO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CDlgSdlShow *m_pdlgsdl;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void ExportImage();

	DECLARE_MESSAGE_MAP()
public:
	// 视频帧列表
	CListCtrl m_listFrames;
	// 选择或者输入文件名控件
	CMFCEditBrowseCtrl m_editbrowseInput;
	// 解析进度显示
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
