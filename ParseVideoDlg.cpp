
// ParseVideoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ParseVideo.h"
#include "ParseVideoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>
#include "bitmap.h"


#define  MAX_FRAME_COUNT		200
// �����locale��stringͷ�ļ���ʹ��setlocale������
std::wstring StringToWstring(const std::string str)
{
	// stringתwstring
	if(str.length()<1)
		return std::wstring(L"");
	unsigned len = str.size() * 2;// Ԥ���ֽ���
	setlocale(LC_CTYPE, "");     //������ô˺���
	wchar_t *p = new wchar_t[len];// ����һ���ڴ���ת������ַ���
	mbstowcs(p,str.c_str(),len);// ת��
	std::wstring str1(p);
	delete[] p;// �ͷ�������ڴ�
	return str1;
}
std::string WstringToString(const std::wstring str)
{// wstringתstring
	unsigned len = str.size() * 4;
	setlocale(LC_CTYPE, "");
	char *p = new char[len];
	wcstombs(p,str.c_str(),len);
	std::string str1(p);
	delete[] p;
	return str1;
}
TCHAR * GetPixelFormatName(AVPixelFormat p)
{
	switch(p)
	{
	case AV_PIX_FMT_NONE: return _T("AV_PIX_FMT_NONE");
	case AV_PIX_FMT_YUV420P: return _T("AV_PIX_FMT_YUV420P");
	case AV_PIX_FMT_YUYV422: return _T("AV_PIX_FMT_YUYV422");
	case AV_PIX_FMT_RGB24: return _T("AV_PIX_FMT_RGB24");
	case AV_PIX_FMT_BGR24: return _T("AV_PIX_FMT_BGR24");
	case AV_PIX_FMT_YUV422P: return _T("AV_PIX_FMT_YUV422P");
	case AV_PIX_FMT_YUV444P: return _T("AV_PIX_FMT_YUV444P");

	case AV_PIX_FMT_YUV410P: return _T("AV_PIX_FMT_YUV410P");
	case AV_PIX_FMT_YUV411P: return _T("AV_PIX_FMT_YUV411P");
	case AV_PIX_FMT_GRAY8: return _T("AV_PIX_FMT_GRAY8");
	case AV_PIX_FMT_MONOWHITE: return _T("AV_PIX_FMT_MONOWHITE");

	case AV_PIX_FMT_MONOBLACK: return _T("AV_PIX_FMT_MONOBLACK");
	case AV_PIX_FMT_PAL8: return _T("AV_PIX_FMT_PAL8");
	case AV_PIX_FMT_YUVJ420P: return _T("AV_PIX_FMT_YUVJ420P");
	case AV_PIX_FMT_YUVJ422P: return _T("AV_PIX_FMT_YUVJ422P");
	case AV_PIX_FMT_YUVJ444P: return _T("AV_PIX_FMT_YUVJ444P");
	case AV_PIX_FMT_XVMC_MPEG2_MC: return _T("AV_PIX_FMT_XVMC_MPEG2_MC");
	case AV_PIX_FMT_XVMC_MPEG2_IDCT: return _T("AV_PIX_FMT_XVMC_MPEG2_IDCT");
	//case AV_PIX_FMT_XVMC: return _T("AV_PIX_FMT_XVMC");
	case AV_PIX_FMT_UYVY422: return _T("AV_PIX_FMT_UYVY422");
	case AV_PIX_FMT_UYYVYY411: return _T("AV_PIX_FMT_UYYVYY411");
	case AV_PIX_FMT_BGR8: return _T("AV_PIX_FMT_BGR8");
	case AV_PIX_FMT_BGR4: return _T("AV_PIX_FMT_BGR4");
	case AV_PIX_FMT_BGR4_BYTE: return _T("AV_PIX_FMT_BGR4_BYTE");
	case AV_PIX_FMT_RGB8: return _T("AV_PIX_FMT_RGB8");

	case AV_PIX_FMT_RGB4: return _T("AV_PIX_FMT_RGB4");
	case AV_PIX_FMT_RGB4_BYTE: return _T("AV_PIX_FMT_RGB4_BYTE");
	case AV_PIX_FMT_NV12: return _T("AV_PIX_FMT_NV12");
	case AV_PIX_FMT_NV21: return _T("AV_PIX_FMT_NV21");
	case AV_PIX_FMT_ARGB: return _T("AV_PIX_FMT_ARGB");
	case AV_PIX_FMT_RGBA: return _T("AV_PIX_FMT_RGBA");
	case AV_PIX_FMT_ABGR: return _T("AV_PIX_FMT_ABGR");
	case AV_PIX_FMT_BGRA: return _T("AV_PIX_FMT_YUV410P");
	case AV_PIX_FMT_GRAY16BE: return _T("AV_PIX_FMT_GRAY16BE");
	case AV_PIX_FMT_GRAY16LE: return _T("AV_PIX_FMT_GRAY16LE");
	case AV_PIX_FMT_YUV440P: return _T("AV_PIX_FMT_YUV440P");
	case AV_PIX_FMT_YUVJ440P: return _T("AV_PIX_FMT_YUVJ440P");
	case AV_PIX_FMT_YUVA420P: return _T("AV_PIX_FMT_YUVA420P");

	case AV_PIX_FMT_VDPAU_H264: return _T("AV_PIX_FMT_VDPAU_H264");
	case AV_PIX_FMT_VDPAU_MPEG1: return _T("AV_PIX_FMT_VDPAU_MPEG1");
	case AV_PIX_FMT_VDPAU_MPEG2: return _T("AV_PIX_FMT_VDPAU_MPEG2");
	case AV_PIX_FMT_VDPAU_WMV3: return _T("AV_PIX_FMT_VDPAU_WMV3");

	case AV_PIX_FMT_VDPAU_VC1: return _T("AV_PIX_FMT_VDPAU_VC1");
	case AV_PIX_FMT_RGB48BE: return _T("AV_PIX_FMT_RGB48BE");
	case AV_PIX_FMT_RGB48LE: return _T("AV_PIX_FMT_RGB48LE");
	case AV_PIX_FMT_RGB565BE: return _T("AV_PIX_FMT_RGB565BE");
	case AV_PIX_FMT_RGB565LE: return _T("AV_PIX_FMT_RGB565LE");
	case AV_PIX_FMT_RGB555BE: return _T("AV_PIX_FMT_RGB555BE");
	case AV_PIX_FMT_RGB555LE: return _T("AV_PIX_FMT_RGB555LE");
	case AV_PIX_FMT_BGR565BE: return _T("AV_PIX_FMT_BGR565BE");
	case AV_PIX_FMT_BGR565LE: return _T("AV_PIX_FMT_BGR565LE");
	case AV_PIX_FMT_BGR555BE: return _T("AV_PIX_FMT_BGR555BE");
	case AV_PIX_FMT_BGR555LE: return _T("AV_PIX_FMT_BGR555LE");
	case AV_PIX_FMT_VAAPI_MOCO: return _T("AV_PIX_FMT_VAAPI_MOCO");
	case AV_PIX_FMT_VAAPI_IDCT: return _T("AV_PIX_FMT_VAAPI_IDCT");
	case AV_PIX_FMT_VAAPI_VLD: return _T("AV_PIX_FMT_VAAPI_VLD");
	//case AV_PIX_FMT_VAAPI: return _T("AV_PIX_FMT_VAAPI");
	case AV_PIX_FMT_YUV420P16LE: return _T("AV_PIX_FMT_YUV420P16LE");
	case AV_PIX_FMT_YUV420P16BE: return _T("AV_PIX_FMT_YUV420P16BE");
	case AV_PIX_FMT_YUV422P16LE: return _T("AV_PIX_FMT_YUV422P16LE");
	case AV_PIX_FMT_YUV422P16BE: return _T("AV_PIX_FMT_YUV422P16BE");
	case AV_PIX_FMT_YUV444P16LE: return _T("AV_PIX_FMT_YUV444P16LE");
	case AV_PIX_FMT_YUV444P16BE: return _T("AV_PIX_FMT_YUV444P16BE");
	case AV_PIX_FMT_VDPAU_MPEG4: return _T("AV_PIX_FMT_VDPAU_MPEG4");
	case AV_PIX_FMT_DXVA2_VLD: return _T("AV_PIX_FMT_DXVA2_VLD");
	case AV_PIX_FMT_RGB444LE: return _T("AV_PIX_FMT_RGB444LE");
	case AV_PIX_FMT_RGB444BE: return _T("AV_PIX_FMT_RGB444BE");
	case AV_PIX_FMT_BGR444LE: return _T("AV_PIX_FMT_BGR444LE");
	case AV_PIX_FMT_BGR444BE: return _T("AV_PIX_FMT_BGR444BE");
	case AV_PIX_FMT_YA8: return _T("AV_PIX_FMT_YA8");
	//case AV_PIX_FMT_Y400A: return _T("AV_PIX_FMT_Y400A");
	//case AV_PIX_FMT_GRAY8A: return _T("AV_PIX_FMT_GRAY8A");
	case AV_PIX_FMT_BGR48BE: return _T("AV_PIX_FMT_BGR48BE");
	case AV_PIX_FMT_BGR48LE: return _T("AV_PIX_FMT_BGR48LE");
	case AV_PIX_FMT_YUV420P9BE: return _T("AV_PIX_FMT_YUV420P9BE");
	case AV_PIX_FMT_YUV420P9LE: return _T("AV_PIX_FMT_YUV420P9LE");
	case AV_PIX_FMT_YUV420P10BE: return _T("AV_PIX_FMT_YUV420P10BE");
	case AV_PIX_FMT_YUV420P10LE: return _T("AV_PIX_FMT_YUV420P10LE");
	case AV_PIX_FMT_YUV422P10BE: return _T("AV_PIX_FMT_YUV422P10BE");
	case AV_PIX_FMT_YUV422P10LE: return _T("AV_PIX_FMT_YUV422P10LE");
	case AV_PIX_FMT_YUV444P9BE: return _T("AV_PIX_FMT_YUV444P9BE");
	case AV_PIX_FMT_YUV444P9LE: return _T("AV_PIX_FMT_YUV444P9LE");
	case AV_PIX_FMT_YUV444P10BE: return _T("AV_PIX_FMT_YUV444P10BE");
	case AV_PIX_FMT_YUV444P10LE: return _T("AV_PIX_FMT_YUV444P10LE");
	case AV_PIX_FMT_YUV422P9BE: return _T("AV_PIX_FMT_YUV422P9BE");
	case AV_PIX_FMT_YUV422P9LE: return _T("AV_PIX_FMT_YUV422P9LE");
	case AV_PIX_FMT_VDA_VLD: return _T("AV_PIX_FMT_VDA_VLD");
	case AV_PIX_FMT_GBRP: return _T("AV_PIX_FMT_GBRP");
	//case AV_PIX_FMT_GBR24P: return _T("AV_PIX_FMT_GBR24P");
	case AV_PIX_FMT_GBRP9BE: return _T("AV_PIX_FMT_GBRP9BE");
	case AV_PIX_FMT_GBRP9LE: return _T("AV_PIX_FMT_GBRP9LE");
	case AV_PIX_FMT_GBRP10BE: return _T("AV_PIX_FMT_GBRP10BE");
	case AV_PIX_FMT_GBRP10LE: return _T("AV_PIX_FMT_GBRP10LE");
	case AV_PIX_FMT_GBRP16BE: return _T("AV_PIX_FMT_GBRP16BE");
	case AV_PIX_FMT_GBRP16LE: return _T("AV_PIX_FMT_GBRP16LE");
	case AV_PIX_FMT_YUVA422P: return _T("AV_PIX_FMT_YUVA422P");
	case AV_PIX_FMT_YUVA444P: return _T("AV_PIX_FMT_YUVA444P");
	case AV_PIX_FMT_YUVA420P9BE: return _T("AV_PIX_FMT_YUVA420P9BE");
	case AV_PIX_FMT_YUVA420P9LE: return _T("AV_PIX_FMT_YUVA420P9LE");
	case AV_PIX_FMT_YUVA422P9BE: return _T("AV_PIX_FMT_YUVA422P9BE");
	case AV_PIX_FMT_YUVA422P9LE: return _T("AV_PIX_FMT_YUVA422P9LE");
	case AV_PIX_FMT_YUVA444P9BE: return _T("AV_PIX_FMT_YUVA444P9BE");
	case AV_PIX_FMT_YUVA444P9LE: return _T("AV_PIX_FMT_YUVA444P9LE");
	case AV_PIX_FMT_YUVA420P10BE: return _T("AV_PIX_FMT_YUVA420P10BE");
	case AV_PIX_FMT_YUVA420P10LE: return _T("AV_PIX_FMT_YUVA420P10LE");
	case AV_PIX_FMT_YUVA422P10BE: return _T("AV_PIX_FMT_YUVA422P10BE");
	case AV_PIX_FMT_YUVA422P10LE: return _T("AV_PIX_FMT_YUVA422P10LE");

	case AV_PIX_FMT_YUVA444P10BE: return _T("AV_PIX_FMT_YUVA444P10BE");
	case AV_PIX_FMT_YUVA444P10LE: return _T("AV_PIX_FMT_YUVA444P10LE");
	case AV_PIX_FMT_YUVA420P16BE: return _T("AV_PIX_FMT_YUVA420P16BE");
	case AV_PIX_FMT_YUVA420P16LE: return _T("AV_PIX_FMT_YUVA420P16LE");
	case AV_PIX_FMT_YUVA422P16BE: return _T("AV_PIX_FMT_YUVA422P16BE");
	case AV_PIX_FMT_YUVA422P16LE: return _T("AV_PIX_FMT_YUVA422P16LE");
	case AV_PIX_FMT_YUVA444P16BE: return _T("AV_PIX_FMT_YUVA444P16BE");
	case AV_PIX_FMT_YUVA444P16LE: return _T("AV_PIX_FMT_YUVA444P16LE");
	case AV_PIX_FMT_VDPAU: return _T("AV_PIX_FMT_VDPAU");
	case AV_PIX_FMT_XYZ12LE: return _T("AV_PIX_FMT_XYZ12LE");


	case AV_PIX_FMT_XYZ12BE: return _T("AV_PIX_FMT_XYZ12BE");
	case AV_PIX_FMT_NV16: return _T("AV_PIX_FMT_NV16");
	case AV_PIX_FMT_NV20LE: return _T("AV_PIX_FMT_NV20LE");
	case AV_PIX_FMT_NV20BE: return _T("AV_PIX_FMT_NV20BE");
	case AV_PIX_FMT_RGBA64BE: return _T("AV_PIX_FMT_RGBA64BE");
	case AV_PIX_FMT_RGBA64LE: return _T("AV_PIX_FMT_RGBA64LE");
	case AV_PIX_FMT_BGRA64BE: return _T("AV_PIX_FMT_BGRA64BE");
	case AV_PIX_FMT_BGRA64LE: return _T("AV_PIX_FMT_BGRA64LE");
	case AV_PIX_FMT_YVYU422: return _T("AV_PIX_FMT_YVYU422");
	case AV_PIX_FMT_VDA: return _T("AV_PIX_FMT_VDA");

	case AV_PIX_FMT_YA16BE: return _T("AV_PIX_FMT_YA16BE");
	case AV_PIX_FMT_YA16LE: return _T("AV_PIX_FMT_YA16LE");
	case AV_PIX_FMT_GBRAP: return _T("AV_PIX_FMT_GBRAP");
	case AV_PIX_FMT_GBRAP16BE: return _T("AV_PIX_FMT_GBRAP16BE");
	case AV_PIX_FMT_GBRAP16LE: return _T("AV_PIX_FMT_GBRAP16LE");
	case AV_PIX_FMT_QSV: return _T("AV_PIX_FMT_QSV");
	case AV_PIX_FMT_MMAL: return _T("AV_PIX_FMT_MMAL");
	case AV_PIX_FMT_D3D11VA_VLD: return _T("AV_PIX_FMT_D3D11VA_VLD");
	case AV_PIX_FMT_CUDA: return _T("AV_PIX_FMT_CUDA");
	case AV_PIX_FMT_0RGB: return _T("AV_PIX_FMT_0RGB");

	case AV_PIX_FMT_RGB0: return _T("AV_PIX_FMT_RGB0");
	case AV_PIX_FMT_0BGR: return _T("AV_PIX_FMT_0BGR");
	case AV_PIX_FMT_BGR0: return _T("AV_PIX_FMT_BGR0");
	case AV_PIX_FMT_YUV420P12BE: return _T("AV_PIX_FMT_YUV420P12BE");
	case AV_PIX_FMT_YUV420P12LE: return _T("AV_PIX_FMT_YUV420P12LE");
	case AV_PIX_FMT_YUV420P14BE: return _T("AV_PIX_FMT_YUV420P14BE");
	case AV_PIX_FMT_YUV420P14LE: return _T("AV_PIX_FMT_YUV420P14LE");
	case AV_PIX_FMT_YUV422P12BE: return _T("AV_PIX_FMT_YUV422P12BE");
	case AV_PIX_FMT_YUV422P12LE: return _T("AV_PIX_FMT_YUV422P12LE");
	case AV_PIX_FMT_YUV422P14BE: return _T("AV_PIX_FMT_YUV422P14BE");
	case AV_PIX_FMT_YUV422P14LE: return _T("AV_PIX_FMT_YUV422P14LE");
	case AV_PIX_FMT_YUV444P12BE: return _T("AV_PIX_FMT_YUV444P12BE");
	case AV_PIX_FMT_YUV444P12LE: return _T("AV_PIX_FMT_YUV444P12LE");
	case AV_PIX_FMT_YUV444P14BE: return _T("AV_PIX_FMT_YUV444P14BE");
	case AV_PIX_FMT_YUV444P14LE: return _T("AV_PIX_FMT_YUV444P14LE");
	case AV_PIX_FMT_GBRP12BE: return _T("AV_PIX_FMT_GBRP12BE");
	case AV_PIX_FMT_GBRP12LE: return _T("AV_PIX_FMT_GBRP12LE");
	case AV_PIX_FMT_GBRP14BE: return _T("AV_PIX_FMT_GBRP14BE");
	case AV_PIX_FMT_GBRP14LE: return _T("AV_PIX_FMT_GBRP14LE");
	case AV_PIX_FMT_YUVJ411P: return _T("AV_PIX_FMT_YUVJ411P");



	case AV_PIX_FMT_BAYER_BGGR8: return _T("AV_PIX_FMT_BAYER_BGGR8");
	case AV_PIX_FMT_BAYER_RGGB8: return _T("AV_PIX_FMT_BAYER_RGGB8");
	case AV_PIX_FMT_BAYER_GBRG8: return _T("AV_PIX_FMT_BAYER_GBRG8");
	case AV_PIX_FMT_BAYER_GRBG8: return _T("AV_PIX_FMT_BAYER_GRBG8");
	case AV_PIX_FMT_BAYER_BGGR16LE: return _T("AV_PIX_FMT_BAYER_BGGR16LE");
	case AV_PIX_FMT_BAYER_BGGR16BE: return _T("AV_PIX_FMT_BAYER_BGGR16BE");
	case AV_PIX_FMT_BAYER_RGGB16LE: return _T("AV_PIX_FMT_BAYER_RGGB16LE");
	case AV_PIX_FMT_BAYER_RGGB16BE: return _T("AV_PIX_FMT_BAYER_RGGB16BE");
	case AV_PIX_FMT_BAYER_GBRG16LE: return _T("AV_PIX_FMT_BAYER_GBRG16LE");
	case AV_PIX_FMT_BAYER_GBRG16BE: return _T("AV_PIX_FMT_BAYER_GBRG16BE");
	case AV_PIX_FMT_BAYER_GRBG16LE: return _T("AV_PIX_FMT_BAYER_GRBG16LE");
	case AV_PIX_FMT_BAYER_GRBG16BE: return _T("AV_PIX_FMT_BAYER_GRBG16BE");
	case AV_PIX_FMT_YUV440P10LE: return _T("AV_PIX_FMT_YUV440P10LE");
	case AV_PIX_FMT_YUV440P10BE: return _T("AV_PIX_FMT_YUV440P10BE");
	case AV_PIX_FMT_YUV440P12LE: return _T("AV_PIX_FMT_YUV440P12LE");
	case AV_PIX_FMT_YUV440P12BE: return _T("AV_PIX_FMT_YUV440P12BE");
	case AV_PIX_FMT_AYUV64LE: return _T("AV_PIX_FMT_AYUV64LE");
	case AV_PIX_FMT_AYUV64BE: return _T("AV_PIX_FMT_AYUV64BE");
	case AV_PIX_FMT_VIDEOTOOLBOX: return _T("AV_PIX_FMT_VIDEOTOOLBOX");
	case AV_PIX_FMT_P010LE: return _T("AV_PIX_FMT_P010LE");
	case AV_PIX_FMT_P010BE: return _T("AV_PIX_FMT_P010BE");
	case AV_PIX_FMT_GBRAP12BE: return _T("AV_PIX_FMT_GBRAP12BE");
	case AV_PIX_FMT_GBRAP12LE: return _T("AV_PIX_FMT_GBRAP12LE");
	case AV_PIX_FMT_GBRAP10BE: return _T("AV_PIX_FMT_GBRAP10BE");
	case AV_PIX_FMT_GBRAP10LE: return _T("AV_PIX_FMT_GBRAP10LE");

	case AV_PIX_FMT_MEDIACODEC: return _T("AV_PIX_FMT_MEDIACODEC");
	case AV_PIX_FMT_NB: return _T("AV_PIX_FMT_NB");
	default: return _T("AV_PIX_FMT_NONE");
	}

}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CParseVideoDlg �Ի���




CParseVideoDlg::CParseVideoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CParseVideoDlg::IDD, pParent),m_pdlgsdl(NULL)
	, m_Indexbegin(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CParseVideoDlg::~CParseVideoDlg()
{
	if(m_pdlgsdl)
		delete m_pdlgsdl;
}
void CParseVideoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FRAMES, m_listFrames);
	DDX_Control(pDX, IDC_MFCEDITBROWSE_INPUT, m_editbrowseInput);
	DDX_Control(pDX, IDC_PROGRESS_FORPARSE, m_parseProgress);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, m_outputinfo);
	DDX_Text(pDX, IDC_EDIT_BEGINNUM, m_Indexbegin);
}

BEGIN_MESSAGE_MAP(CParseVideoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CParseVideoDlg::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_FRAMES, &CParseVideoDlg::OnLvnItemchangedListFrames)
	ON_WM_DESTROY()
	ON_WM_MOVE()
	ON_NOTIFY(NM_RCLICK, IDC_LIST_FRAMES, &CParseVideoDlg::OnNMRClickListFrames)
	ON_COMMAND(WM_EXPORT_IMAGE,ExportImage)
END_MESSAGE_MAP()


// CParseVideoDlg ��Ϣ�������

BOOL CParseVideoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	//��ʼ��list���
	DWORD dwStyle = m_listFrames.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��

	m_listFrames.SetExtendedStyle(dwStyle);

	m_listFrames.InsertColumn(0,_T("����֡���"),LVCFMT_LEFT,120);//������
	m_listFrames.InsertColumn(1,_T("��ʾ֡���"),LVCFMT_LEFT,120);
	m_listFrames.InsertColumn(2,_T("�Ƿ�ؼ�֡"),LVCFMT_LEFT,120);
	m_listFrames.InsertColumn(3,_T("��Ƶ֡��͸�"),LVCFMT_LEFT,140);
	m_listFrames.InsertColumn(4,_T("������ԭʼ��������"),LVCFMT_LEFT,220);
	m_listFrames.InsertColumn(5,_T("��߱�"),LVCFMT_LEFT,120);
	m_listFrames.InsertColumn(6,_T("��ʾʱ���"),LVCFMT_LEFT,120);

	m_listFrames.InsertColumn(7,_T("ͼ���С"),LVCFMT_LEFT,120);
	//int nRow = m_listFrames.InsertItem(0, _T("11"));//������


	m_pdlgsdl = new CDlgSdlShow;
	m_pdlgsdl->Create(IDD_DIALOG_SDL,this);
	m_pdlgsdl->ShowWindow(SW_HIDE);

	m_Indexbegin = _T("1");
	UpdateData(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CParseVideoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CParseVideoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CParseVideoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CParseVideoDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	//if(m_pdlgsdl->GetSafeHwnd())
	//	AfxMessageBox(_T("right"));
	//m_pdlgsdl->ShowWindow(SW_SHOW);
	ParseVideo();
}

#include "bitmap.h"
BOOL CParseVideoDlg::ParseVideo(void)
{
	CString strVideoPath;
	m_editbrowseInput.GetWindowText(strVideoPath);
	if(strVideoPath.GetLength()<1)
	{
		MessageBox(_T("��ѡ���ļ�"),_T("����"),0);
		return FALSE;
	}

	if(m_Indexbegin.IsEmpty())
	{
		MessageBox(_T("��ʼ֡������Ϊ��"),_T("����"),0);
		return FALSE;
	}
	UpdateData();
	//��ȡ�û��������ʼ��֡��
	int nIndexBegin = _wtoi(m_Indexbegin.GetString())-1;

	if(nIndexBegin<0)
	{
		MessageBox(_T("��ʼ֡��̫С"),_T("����"),0);
		return FALSE;
	}
	CleanItemData();

	AVFormatContext *pFormatCtx;  
	int             i, videoindex;  
	AVCodecContext  *pCodecCtx;  
	AVCodec         *pCodec;  
	AVFrame *pFrame/*,*pFrameYUV*/;  
	//AVFrame *pFrame;  
//	unsigned char *out_buffer;  
	AVPacket *packet;  
	int y_size;  
	int ret, got_picture;  
	struct SwsContext *img_convert_ctx; 
	int nRange = 0;
	//m_editbrowseInput.gett

	//char filepath[]="D:\\src\\media\\ffmpeg\\res\\demo1.flv";
	std::wstring str_wpath = strVideoPath.GetString();
	std::string filepath = WstringToString(str_wpath);
	CString stream_info;

	UINT nfps = 0;
	av_register_all(); //��ʼ��ffmpeg�⣬���ϵͳ�����ffmpegû���ú���������
	avformat_network_init();//��Ҫ����������Ƶ
	pFormatCtx = avformat_alloc_context(); //����FFMPEG���װ��flv��mp4��rmvb��avi�����ܵĽṹ��

	if(avformat_open_input(&pFormatCtx,filepath.c_str(),NULL,NULL)!=0){   //��һ����Ƶ�ļ�
		MessageBox(_T("����Ƶ���ļ�ʧ�ܣ�������Ƶ�ļ���ʽ"));  
		return FALSE;  
	}
	if(avformat_find_stream_info(pFormatCtx,NULL)<0){  //��ȡ��Ƶ�ļ�ͷ��Ϣ
		MessageBox(_T("��ȡ��Ƶ�ļ�ͷʧ��"));  
		return FALSE;  
	}  

	//������δ����������  �ҵ���һ֡��Ƶ��  ���һ�ȡ�����
	videoindex=-1;  
	//pFormatCtx->nb_streams ����Ƶ��������
	for(i=0; i<pFormatCtx->nb_streams; i++)   
		if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO){  
			videoindex=i;  
			break;  
		}  



		//���û�ҵ���Ƶ��   �򱨴�
		if(videoindex==-1){  
			MessageBox(_T("�Ҳ�����Ƶ��"));  
			return FALSE;  
		}  

		pCodecCtx=pFormatCtx->streams[videoindex]->codec;
		//avcodec_find_decoder ����ffmpeg������   avcodec_find_encoder ����ffmpeg������
		pCodec=avcodec_find_decoder(pCodecCtx->codec_id);  
		if(pCodec==NULL){  
			MessageBox(_T("�Ҳ���������"));  
			return FALSE;  
		}  
		//avcodec_open2 �򿪽�����
		if(avcodec_open2(pCodecCtx, pCodec,NULL)<0){  
			MessageBox(_T("�Ҳ���������"));
			return FALSE;  
		}  

		nfps = pFormatCtx->streams[videoindex]->avg_frame_rate.num/pFormatCtx->streams[videoindex]->avg_frame_rate.den;
		std::string strcodename = pFormatCtx->iformat->long_name;
		std::wstring strcodenamew = StringToWstring(strcodename);
		std::string strstreamcode = pCodec->name;

		std::wstring strstreamcodew = StringToWstring(pCodec->name);

		int secs = -1;
		int64_t duration;
		if(AV_NOPTS_VALUE != pFormatCtx->duration)
		{
			duration = pFormatCtx->duration + (pFormatCtx->duration <= INT64_MAX - 5000 ? 5000 : 0);
			double dtmp = (double)duration / (double)AV_TIME_BASE;
			nRange = dtmp*nfps;
			secs  = duration / AV_TIME_BASE;
			
		}
		
		//if(secs>0)



		stream_info.Format(_T("��Ƶ��װ��ʽ:%s ��Ƶ�������ʽ:%s ͼ���ʽ:%s ��:%d ��:%d ��Ƶ��:%d ����:%I64d kbs ֡��:%d fps"),
			strcodenamew.c_str(),
			strstreamcodew.c_str(),
			GetPixelFormatName(pCodecCtx->pix_fmt),
			pCodecCtx->width,
			pCodecCtx->height,
			secs,
			pFormatCtx->bit_rate/1000,
			nfps);


		m_parseProgress.SetRange(0,200);
		m_parseProgress.SetPos(0);


		//AfxMessageBox(stream_info);
		m_outputinfo.SetWindowText(stream_info);
		pFrame=av_frame_alloc();  //����������
		//pFrameYUV=av_frame_alloc();  //����������

  
		//uint8_t *out_buffer;  

		//out_buffer=new uint8_t[avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height)];  
		//avpicture_fill((AVPicture *)pFrameYUV, out_buffer, AV_PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);  


		//��һ�� ��֪����ɶ��
		//out_buffer=(unsigned char *)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_YUV420P,  pCodecCtx->width, pCodecCtx->height,1));  
		//���ݲ��� ���pFrameYUV
		//av_image_fill_arrays(pFrameYUV->data, pFrameYUV->linesize,out_buffer,  
		//	AV_PIX_FMT_YUV420P,pCodecCtx->width, pCodecCtx->height,1);  

		packet=(AVPacket *)av_malloc(sizeof(AVPacket));  

		////Output Info-----------------------------  
		//printf("--------------- File Information ----------------\n");  
		////��ӡ�ļ��ĸ�����Ϣ����Ļ
		//av_dump_format(pFormatCtx,0,filepath,0);  
		//printf("-------------------------------------------------\n");  






		//img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,   
		//	pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);

		img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,   
			pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB32, SWS_BILINEAR, NULL, NULL, NULL);


		//����
		int nIndex = 0;
		while(av_read_frame(pFormatCtx, packet)>=0){  //av_read_frame��ȡһ֡
			if(packet->stream_index==videoindex){  //�Ա�ý����������


				ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);	//avcodec_decode_video2 ����
				if(ret < 0){  
					AfxMessageBox(_T("����ʱ��������"));  
					return FALSE;  
				}  
				if(nIndex<nIndexBegin)
				{
					nIndex ++;
					continue;
				}
				if(nIndex>=nIndexBegin+MAX_FRAME_COUNT)
					break;

				int nRow = m_listFrames.InsertItem(m_listFrames.GetItemCount(),_T(""));
				stream_info.Format(_T("%d"),pFrame->coded_picture_number);
				m_listFrames.SetItemText(nRow,0,stream_info);
				//if(nRange!=0)
				//	m_parseProgress.SetPos((double)pFrame->coded_picture_number/(double)nRange*100);

				stream_info.Format(_T("%d"),pFrame->display_picture_number);
				m_listFrames.SetItemText(nRow,1,stream_info);

				stream_info = pFrame->key_frame == 1?_T("��"):_T("��");
				m_listFrames.SetItemText(nRow,2,stream_info);

				stream_info.Format(_T("%dx%d"),pFrame->width,pFrame->height);
				m_listFrames.SetItemText(nRow,3,stream_info);

				stream_info = GetPixelFormatName((AVPixelFormat)pFrame->format);
				m_listFrames.SetItemText(nRow,4,stream_info);

				stream_info.Format(_T("%d/%d"),pFrame->sample_aspect_ratio.num,pFrame->sample_aspect_ratio.den);
				m_listFrames.SetItemText(nRow,5,stream_info);





				stream_info.Format(_T("%d"),pFrame->pts);
				m_listFrames.SetItemText(nRow,6,stream_info);
				//if(AV_NOPTS_VALUE != pFormatCtx->duration)
				//	m_parseProgress.SetPos((double)pFrame->pts/(double)secs/(double)10);
				if(got_picture){  
					//AVFrame *pFrameYUV=av_frame_alloc();  //����������
					uint8_t *rgb_data = static_cast<uint8_t*>(av_malloc(pCodecCtx->width*pCodecCtx->height*4));
					uint8_t *rgb_src[3]= {rgb_data, NULL, NULL};
					int rgb_stride[3]={4*pCodecCtx->width, 0, 0};
					//int nres = sws_scale(img_convert_ctx, (const unsigned char* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,   
					//	pFrameYUV->data, pFrameYUV->linesize);
					int nres = sws_scale(img_convert_ctx, (const unsigned char* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,   
						rgb_src, rgb_stride);

						BITMAP_DATA* pdata = new BITMAP_DATA;
						int nBmpCount = 0;
						//pdata->pdata = freerdp_bitmap_write_mem(pFrameYUV->data[0],pCodecCtx->width,pCodecCtx->height,24,&nBmpCount);
						pdata->pdata = freerdp_bitmap_write_mem(rgb_data,pCodecCtx->width,pCodecCtx->height,32,&nBmpCount);
						pdata->data_count = nBmpCount;

						int nResKb = nBmpCount/1024;
						if(nResKb<1024)
							stream_info.Format(_T("%d KB"),nResKb);
						else
							stream_info.Format(_T("%.2f MB"),(double)nResKb/1024);
						m_listFrames.SetItemText(nRow,7,stream_info);
						m_listFrames.SetItemData(nRow,(DWORD_PTR)pdata);


				}  
				m_parseProgress.StepIt();
				nIndex ++;
			}  
			av_free_packet(packet);  
			
		}  
		sws_freeContext(img_convert_ctx);


		//av_frame_free(&pFrameYUV);  

		av_frame_free(&pFrame);  
		avcodec_close(pCodecCtx);  
		avformat_close_input(&pFormatCtx);  

		//delete out_buffer;
		m_parseProgress.SetPos(200);
		CString strOutPut;
		int nInterVal = nIndex - nIndexBegin;
		if(nInterVal>0)
			strOutPut.Format(_T("�������,��������%d֡"),nInterVal);
		else
			strOutPut.Format(_T("�������,��������0֡"));
		MessageBox(strOutPut,_T("��ʾ"));
		return FALSE;
}


void CParseVideoDlg::OnLvnItemchangedListFrames(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if(pNMLV->uChanged == LVIF_STATE)
	{
		if(pNMLV->uNewState)
		{
			int nSelectIndex = pNMLV->iItem;
			BITMAP_DATA *pbitmap = (BITMAP_DATA *)m_listFrames.GetItemData(nSelectIndex);
			if(pbitmap)
			{
				m_pdlgsdl->UpdateSdlWindows(pbitmap);
				
			}
			
			
		}
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CParseVideoDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_pdlgsdl->DestroyWindow();
	delete m_pdlgsdl;
	m_pdlgsdl = NULL;
	CleanItemData();
	// TODO: �ڴ˴������Ϣ����������
}


void CParseVideoDlg::CleanItemData(void)
{
	for (int i = 0;i<m_listFrames.GetItemCount();i++)
	{
		BITMAP_DATA *pbitmap = (BITMAP_DATA *)m_listFrames.GetItemData(i);
		if(pbitmap)
		{
			if(pbitmap->pdata)
			{
				delete pbitmap->pdata;
				pbitmap->pdata = NULL;
			}

			delete pbitmap;
			pbitmap = NULL;
		}
	}
	m_listFrames.DeleteAllItems();
}


void CParseVideoDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	//m_pdlgsdl->MoveWindow()
	if(m_pdlgsdl)
	{
		CRect rc;
		m_pdlgsdl->GetWindowRect(&rc);
		CRect rcp;
		GetWindowRect(&rcp);

		m_pdlgsdl->MoveWindow(rcp.right,rcp.top,rc.Width(),rc.Height());
	
	}

	// TODO: �ڴ˴������Ϣ����������
}


void CParseVideoDlg::OnNMRClickListFrames(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//// TODO: �ڴ���ӿؼ�֪ͨ����������
	//*pResult = 0;
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);  
	//��ֹ�ڿհ�����������˵�  
	if (m_listFrames.GetSelectedCount() <= 0)  
	{  
		return;  
	}

	LPPOINT lpoint=new tagPOINT;  
	::GetCursorPos(lpoint);         //�õ����λ��  
	CMenu menu;  
	menu.CreatePopupMenu();             //����һ������ʽ�˵�           

	menu.AppendMenu(MF_STRING,WM_EXPORT_IMAGE,_T("����"));
	menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);//ȷ������ʽ�˵���λ��            
	HMENU hmenu=menu.Detach();   //��Դ����  
	menu.DestroyMenu();  
	delete lpoint;  

}
void CParseVideoDlg::ExportImage()
{
	int nSelectIndex = m_listFrames.GetSelectionMark();
	if(nSelectIndex>=0)
	{
		BITMAP_DATA *pbitmap = (BITMAP_DATA *)m_listFrames.GetItemData(nSelectIndex);
		if(pbitmap)
		{
			m_pdlgsdl->ExportImage(pbitmap);

		}
	}
}