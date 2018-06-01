// DlgSdlShow.cpp : 实现文件
//

#include "stdafx.h"
#include "ParseVideo.h"
#include "DlgSdlShow.h"
#include "afxdialogex.h"


// CDlgSdlShow 对话框

IMPLEMENT_DYNAMIC(CDlgSdlShow, CDialogEx)

CDlgSdlShow::CDlgSdlShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSdlShow::IDD, pParent)
{

}

CDlgSdlShow::~CDlgSdlShow()
{
}

void CDlgSdlShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSdlShow, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgSdlShow 消息处理程序


BOOL CDlgSdlShow::InitSdlWindows(void)
{
	//int screen_w=0,screen_h=0;  


	////下面是初始化sdl窗口
	//if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {    
	//	printf( "Could not initialize SDL - %s\n", SDL_GetError());   
	//	return -1;  
	//}   
	////screen = SDL_CreateWindow("Simplest ffmpeg player's Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,  
	////	screen_w, screen_h,  
	////	SDL_WINDOW_OPENGL);  
	//screen = SDL_CreateWindowFrom((void *)(GetDlgItem(IDC_STATIC_SDL)->GetSafeHwnd()));  


	//if(!screen) {    
	//	printf("SDL: could not create window - exiting:%s\n",SDL_GetError());    
	//	return -1;  
	//}  
	////创建一个sdl渲染器
	//sdlRenderer = SDL_CreateRenderer(screen, -1, 0);    
	////IYUV: Y + U + V  (3 planes)  
	////YV12: Y + V + U  (3 planes)  
	////在渲染器上  创建一个纹理
	//sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING,900,500/*pCodecCtx->width,pCodecCtx->height*/);    

	//sdlRect.x=0;  
	//sdlRect.y=0;  
	//sdlRect.w=900;  
	//sdlRect.h=500;  


	return FALSE;
}


BOOL CDlgSdlShow::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//CreateBitmapIndirect()
	// TODO:  在此添加额外的初始化
	InitSdlWindows();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CDlgSdlShow::UpdateSdlWindows(BITMAP_DATA *pbitmap)
{
	//CxImage image;
	//if (image.Decode((uint8_t *)pbitmap->pdata, pbitmap->data_count, CXIMAGE_FORMAT_BMP))  
	//{  
	//	ShowWindow(SW_SHOW);
	//	CRect rc;
	//	GetParent()->GetWindowRect(&rc);


	//	char *pdate_tmp = pbitmap->pdata;
	//	BITMAPINFOHEADER1 *header1 = (BITMAPINFOHEADER1 *)(pdate_tmp+sizeof(bmpfile_magic)+sizeof(bmpfile_header));
	//	void *pbuffer  = (void *)(pdate_tmp+sizeof(bmpfile_magic)+sizeof(bmpfile_header)+sizeof(BITMAPINFOHEADER1));
	//	MoveWindow(rc.right,rc.top,header1->width,header1->height*(-1)+10);

	//	HDC hDc = ::GetDC(m_hWnd);
	//	image.Draw(hDc,CRect(0,0,header1->width,header1->height*(-1)));
	//	::ReleaseDC(m_hWnd,hDc);

	//	//const TCHAR *path = _T("LoadInMemory.png");
	//	//image.Save(path,::CXIMAGE_FORMAT_PNG);  
	//}  
	//


	if (m_image.Decode((uint8_t *)pbitmap->pdata, pbitmap->data_count, CXIMAGE_FORMAT_BMP))  
	{  
		ShowWindow(SW_SHOW);
		CRect rc;
		GetParent()->GetWindowRect(&rc);


		char *pdate_tmp = pbitmap->pdata;
		BITMAPINFOHEADER1 *header1 = (BITMAPINFOHEADER1 *)(pdate_tmp+sizeof(bmpfile_magic)+sizeof(bmpfile_header));
		void *pbuffer  = (void *)(pdate_tmp+sizeof(bmpfile_magic)+sizeof(bmpfile_header)+sizeof(BITMAPINFOHEADER1));
		MoveWindow(rc.right,rc.top,header1->width,header1->height*(-1)+10);


		
		//const TCHAR *path = _T("LoadInMemory.png");
		//image.Save(path,::CXIMAGE_FORMAT_PNG);  
		Invalidate();
	}  
	
	return FALSE;
}


void CDlgSdlShow::OnPaint()
{
	CPaintDC dc(this); // device context for painting


	HDC hDc = ::GetDC(m_hWnd);
	m_image.Draw(hDc,CRect(0,0,m_image.GetWidth(),m_image.GetHeight()));
	::ReleaseDC(m_hWnd,hDc);

	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
}
void CDlgSdlShow::ExportImage(BITMAP_DATA *pbitmap)
{
	CFileDialog dlg(FALSE,NULL,_T("output"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("BMP Files (*.bmp)|*.bmp|GIF Files (*.gif)|*.gif|PNG Files (*.png)|*.png|JPG Files (*.jpg)|*.jpg||"));//FALSE表示为“另存为”对话框，否则为“打开”对话框
	dlg.m_ofn.lpstrDefExt = _T("bmp");
	if(dlg.DoModal() == IDOK)
	{
		CString str_ext = dlg.GetFileExt();
		str_ext.MakeLower();
		//AfxMessageBox(dlg.GetPathName());
		ENUM_CXIMAGE_FORMATS ext_format;
		if(str_ext == "bmp")
		{
			ext_format = CXIMAGE_FORMAT_BMP;
		}
		else if(str_ext == "gif")
		{
			ext_format = CXIMAGE_FORMAT_GIF;
		}
		else if(str_ext == "jpg")
		{
			ext_format = CXIMAGE_FORMAT_JPG;
		}
		else if(str_ext == "png")
		{
			ext_format = CXIMAGE_FORMAT_PNG;
		}
		else
		{
			GetParent()->MessageBox(_T("不支持该格式"),_T("提示"),0);
			return;
			//AfxMessageBox(str_ext);
		}
		m_image.Save(dlg.GetPathName().GetString(),ext_format);
		//CxImage image;
		//if(image.Decode((uint8_t *)pbitmap->pdata, pbitmap->data_count,::CXIMAGE_FORMAT_BMP))  
		//{
		//	image.Save(dlg.GetPathName().GetString(),ext_format);
		//}
		//else
		//	GetParent()->MessageBox(_T("导出失败"),_T("提示"),0);


	}
}