#if 0
#include<tchar.h>
#include<windows.h>


//unicode <- ansi  _T()转化

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	MessageBox(NULL, _T("Hello World"), _T("Win32"), IDOK);
	return 0;
}
#endif

#if 0
#include <Windows.h>
#include <tchar.h>
//消息回调函数
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL))
		{
			DestroyWindow(hWnd);
			return 0;
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	//Step1:注册一个窗口类
	HWND hwnd;                //窗口的句柄
	WNDCLASSEX wc;            //窗口类结构
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszMenuName = 0;
	wc.lpszClassName = _T("Win32");
	wc.lpfnWndProc = WinProc; //消息回调函数
	wc.hInstance = hInstance;
	wc.hIcon = NULL;		  //系统默认图标
	wc.hCursor = NULL;        //光标
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);    //注册窗口
	//Step2:创建一个窗口
	hwnd = CreateWindow(
		_T("Win32"), //窗口的类名，也就是上面我们自定义的窗口类的名字
		_T("我的第一个Win32程序"), //窗口的标题
		WS_OVERLAPPEDWINDOW, //窗口style
		500, //窗口位置x坐标
		300, //窗口位置y坐标
		800, //窗口宽度
		600, //窗口高度
		NULL, //父窗口句柄
		NULL, //菜单句柄
		hInstance, //实例句柄
		NULL //创建数据
	);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //显示窗口
	UpdateWindow(hwnd); //刷新
	//Step3:消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
#endif


#if 0
#include<windows.h>
#include<tchar.h>
#include"DuiLib/UIlib.h"

using namespace DuiLib;


#ifdef _DEBUG
#	ifdef _UNICODE
#		pragma comment(lib,"DuiLib_ud.lib")
#	else
#		pragma comment(lib,"DuiLib_d.lib")
#	endif
#else
#	ifdef _UNICODE
#		pragma comment(lib,"DuiLib_u.ilb")
#	else
#		pragma comment(lib,"DuiLib.lib")
#	endif
#endif

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{

	return 0;
}

#endif

#include <windows.h>
#include <tchar.h>
#include <UIlib.h>
#include <cstdlib>

using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg) {
		if (msg.sType == _T("click")) {
			if (msg.pSender->GetName() == _T("btnHello")) {
				::MessageBox(NULL,_T("按钮"),_T("点击了按钮"),NULL);
			}
		}
	}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			//CControlUI* pWnd = new CButtonUI;
			////设置控件的名称，这名称用于标识每一个控件，必须唯一，相当于MFC里面的控件ID
			//pWnd->SetName(_T("bntHello"));
			//// 设置文字
			//pWnd->SetText(_T("Hello World"));
			//// 设置背景色
			//pWnd->SetBkColor(0xFF00FF00);       

			//m_PaintManager.Init(m_hWnd);
			//m_PaintManager.AttachDialog(pWnd);
			////添加控件等消息响应，这样消息就会传达到dublib的消息循环，在Notify里面做消息处理
			//m_PaintManager.AddNotifier(this);
			//return lRes;
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			// duilib.xml需要放到exe目录下
			//CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   
			CControlUI* pRoot = builder.Create(_T("UISkin1.xml"), (UINT)0, NULL, &m_PaintManager);
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			// 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
			m_PaintManager.AddNotifier(this);   
			return lRes;
		}
		// 以下3个消息WM_NCACTIVATE、WM_NCCALCSIZE、WM_NCPAINT用于屏蔽系统标题栏
		else if (uMsg == WM_NCACTIVATE) {
			if (!::IsIconic(m_hWnd)) {
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE) {
			return 0;
		}
		else if (uMsg == WM_NCPAINT) {
			return 0;
		}
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};
#endif
#if 0
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const { return _T("DUIMainFrame"); }
	//virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFile() { return _T("UISkin1.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }
	virtual void    Notify(TNotifyUI& msg) {
		if (msg.sType == _T("click")) {
			if (msg.pSender->GetName() == _T("closebtn")) {
				::MessageBox(NULL, _T("按钮"), _T("点击了按钮"), NULL);
			}
		}
	}
	virtual void InitWindow()
	{

		CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));

		if (pActiveXUI)
		{
			IWebBrowser2* pWebBrowser = NULL;

			pActiveXUI->SetDelayCreate(false);              // 相当于界面设计器里的DelayCreate属性改为FALSE，在duilib自带的FlashDemo里可以看到此属性为TRUE             
			pActiveXUI->CreateControl(CLSID_WebBrowser);    // 相当于界面设计器里的Clsid属性里填入{8856F961-340A-11D0-A96B-00C04FD705A2}，建议用CLSID_WebBrowser，如果想看相应的值，请见<ExDisp.h>
			pActiveXUI->GetControl(IID_IWebBrowser2, (void**)& pWebBrowser);

//			if (pWebBrowser != NULL)
//			{
//				//pWebBrowser->Navigate(L"https://code.google.com/p/duilib/",NULL,NULL,NULL,NULL);  
////			      pWebBrowser->Navigate(L"http://www.baidu.com/", NULL, NULL, NULL, NULL);  // 由于谷歌时不时被墙，所以换成反应快的网站
//				pWebBrowser->Release();
//			}
		}
		CDuiString str;
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("ListDemo1")));

		// 添加List列表内容，必须先Add(pListElement)，再SetText
		for (int i = 0; i < 100; i++)
		{
			CListTextElementUI* pListElement = new CListTextElementUI;
			pListElement->SetTag(i);
			pList->Add(pListElement);

			str.Format(_T("%d"), i);
			pListElement->SetText(0, str);
			pListElement->SetText(1, _T("haha"));
		}
	}
};
#endif
#if 0
void SendCmd(const CDuiString& strCMD) {
	CDuiString strFFmpegPath = CPaintManagerUI::GetInstancePath();

	//初始化结构体
	SHELLEXECUTEINFO strSEInfo;
	memset(&strSEInfo,0,sizeof(SHELLEXECUTEINFO));
	strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	strSEInfo.lpFile = _T("C:\\Windows\\Systems32\\cmd.exe");

	CDuiString strFFmpegCmd;
	strFFmpegCmd += _T("/c");
	strFFmpegCmd += strFFmpegPath;
	strFFmpegCmd += strCMD;
	strSEInfo.lpParameters = strFFmpegCmd;
	strSEInfo.nShow = SW_SHOW;

	//给cmd发送命令
	ShellExecuteEx(&strSEInfo);
	WaitForSingleObject(strSEInfo.hProcess, INFINITE);;
}
#endif
	//用cmd发命令
void GenerateGifWithPic() {
		//获取当前工程路径 --> ffmpeg完整路径
		CDuiString strFFmpegPath = CPaintManagerUI::GetInstancePath() + _T("ffmpeg\\ffmpeg");
		
		//1. 初始化结构体
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:/Windows/System32/cmd.exe");

		//构造命令
		CDuiString strPictruePath = CPaintManagerUI::GetInstancePath() + _T("ffmpeg\\Pictrue\\%d.jpg ");
		CDuiString strOutPath = CPaintManagerUI::GetInstancePath() + _T("ffmpeg\\Pictrue\\out.gif");
		CDuiString strCMD(_T("/c"));
		strCMD += strFFmpegPath + _T(" -r 1 -i ") + strPictruePath + strOutPath;

		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE; //隐藏cmd'窗口

		//2. 发送cmd命令
		ShellExecuteEx(&strSEInfo);
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
}

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("UISkin1.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }
	
	virtual void Notify(TNotifyUI& msg) {
		if (msg.sType == _T("click")) {
			if (msg.pSender->GetName() == _T("closebtn")) {
				::MessageBox(NULL, _T("按钮"), _T("点击了按钮"), NULL);
			}
		}
	}

	virtual void InitWindow()
	{
		CDuiString str;
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List")));
		// 添加List列表内容，必须先Add(pListElement)，再SetText
		for (int i = 0; i < 100; i++)
		{
			CListTextElementUI* pListElement = new CListTextElementUI;
			pListElement->SetTag(i);
			pList->Add(pListElement);

			str.Format(_T("%d"), i);
			pListElement->SetText(0, str);
			pListElement->SetText(1, _T("haha"));
		}
	}
};
#if 0
//向cmd发送命令，启动ffempg
void SendCmd(const CDuiString& strCMD) {
	CDuiFrameWnd strFFmepgPath = CPaintManagerUI::GetInstancePath();

	//初始化结构体
	SHELLEXECUTEINFO strSEInfo;
	memset(&strSEInfo,0,sizeof(SHELLEXECUTEINFO));
	strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	strSEInfo.lpFile = _T("C:\\Windows\\system32\\cmd.exe");

	CDuiString strFFmepgCmd;
	strFFmepgCmd += _T("/c");
	strFFmepgCmd += strFFmepgPath;
	strFFmepgCmd += strCMD;
	strSEInfo.lpParameters = strFFmepgCmd;
	strSEInfo.nShow = SW_SHOW;

	//发送
	ShellExecuteEx(&strSEInfo);
	WaitForSingleObject(strSEInfo.hProcess, INFINITE);
}
#endif

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;
	// 这里必须用new，否则有ActiveX控件时，关闭窗口会产生崩溃
	CDuiFrameWnd* pFrame = new CDuiFrameWnd;    
	pFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	pFrame->ShowModal();

	delete pFrame;
	::CoUninitialize();
	return 0;
}


