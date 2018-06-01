#pragma once

//#include <SDL.h>
//#pragma comment(lib,"SDL2.lib")


//#include <ximage.h>
//#pragma comment(lib,"cximage.lib")

// CDlgSdlShow 对话框
#include "ffmpeg.h"
#include "bitmap.h"

#include <ximage.h>
#pragma comment(lib,"cximage.lib")
#pragma comment(lib,"png.lib")  
#pragma comment(lib,"jasper.lib")  
#pragma comment(lib,"jbig.lib")  
#pragma comment(lib,"Jpeg.lib")  
#pragma comment(lib,"libpsd.lib")  
#pragma comment(lib,"libdcr.lib")  
#pragma comment(lib,"mng.lib") 
#pragma comment(lib,"Tiff.lib")
#pragma comment(lib,"zlib.lib") 


class CDlgSdlShow : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSdlShow)

public:
	CDlgSdlShow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSdlShow();

// 对话框数据
	enum { IDD = IDD_DIALOG_SDL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL InitSdlWindows(void);
	virtual BOOL OnInitDialog();
	BOOL UpdateSdlWindows(BITMAP_DATA *pbitmap);
	void ExportImage(BITMAP_DATA *pbitmap);
//private:
//	SDL_Window *screen;   
//	SDL_Renderer* sdlRenderer;  
//	SDL_Texture* sdlTexture;  
//	SDL_Rect sdlRect;  
private:
	CxImage m_image;
public:
	afx_msg void OnPaint();
};
