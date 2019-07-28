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
#include <iostream>
#include <fstream>


using namespace std;
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
	virtual void Notify(TNotifyUI& msg) {
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

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("UISkin1.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }

	virtual void Notify(TNotifyUI& msg) {
		if (msg.sType == _T("click")) {
			CDuiString strControlName = msg.pSender->GetName();
			if (strControlName == _T("closebtn")) {
				Close();
			}
			else if (strControlName == _T("mintun")) {
				SendMessage(WM_SYSCOMMAND,SC_MINIMIZE);
			}
			else if (strControlName == _T("Button_load")) {
				LoadFileAddrs();
			}
			else if (strControlName == _T("Button_cut")) {
				CutView();
			}
			else if (strControlName == _T("jiazaiSRT")) {
				GenerateASSFile();
			}
			else if (strControlName == _T("shengchengASS")) {
				LoadASS();
			}
			else if (strControlName == _T("makeGIF")) {
				CComboBoxUI* pCombBox = (CComboBoxUI*)m_PaintManager.GetInstance();
				int i = pCombBox->GetCurSel();
				if (pCombBox->GetCurSel() == 0) {
					GenerateGifWithPic();
				}
				else {
					GenerateGifWithView();
				}
			}
		}
	}
#if 0
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
#endif
#if 1
	//向cmd发送命令，启动ffempg
	void SendCmd(const CDuiString& strCMD) {
		CDuiString strFFmepgPath = CPaintManagerUI::GetInstancePath();

		//初始化结构体
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\system32\\cmd.exe");
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE;

		//发送
		ShellExecuteEx(&strSEInfo);
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
		MessageBox(m_hWnd,_T("Finished"),_T("GIF"),IDOK);
	}
#endif
	//加载文件
	void LoadFileAddrs() {
		OPENFILENAME ofn;
		TCHAR FileName[MAX_PATH];

		memset(&ofn,0,sizeof(OPENFILENAME));
		memset(FileName,0,sizeof(char)*MAX_PATH);

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = _T("\0*.jpg");
		ofn.lpstrFile = FileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn)) {
			MessageBox(NULL, _T("加载文件路径"), _T("BTN"), IDOK);
		}
	}
	//裁剪视频
	void CutView() {
		CDuiString strStartTime = m_pEditStart->GetText();
		if (IsValidTime(strStartTime)) {
			MessageBox(m_hWnd,_T("起始时间有误"),_T("Error!"),IDOK);
			return;
		}
		CDuiString strFinishTime = m_pEditFinish->GetText();
		if (IsValidTime(strFinishTime)) {
			MessageBox(m_hWnd, _T("结束时间有误"), _T("Error!"), IDOK);
			return;
		}
		MessageBox(NULL,_T("截取视频"),_T("BTN"),IDOK);


		//构造命令
		CDuiString StrCMD(_T("/c"));
		StrCMD += CPaintManagerUI::GetInstancePath();
		StrCMD += (_T("ffmpeg\\ffmpeg -ss"));
		StrCMD += strStartTime;
		StrCMD += (_T("-to"));
		StrCMD += strFinishTime;
		StrCMD += (_T("-i"));

		StrCMD += CPaintManagerUI::GetInstancePath();
		StrCMD += (_T("-vcodec copy -acodec copy output.avi"));
		SendCmd(StrCMD);
	}
	bool IsValidTime(const CDuiString& strTime) {
		if (strTime.GetLength() != 8)  return false;
		for (int i = 0; i < 8;++i) {
			if (':' == strTime[i]) {
				continue;
			}
			else if(isdigit(strTime[i])){
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	void GenerateGifWithView() {
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD;

		//ffmpeg -r 1 -i 1.flv 1.gif
		strCMD += _T("/c");
		strCMD += strPath;
		strCMD += (_T("ffmpeg\\ffmpeg -r 50 -i"));
		strCMD += strPath;
		strCMD += (_T("ffmpeg\\output.avi .\\..\\debug\\ffmpeg\\outputview.gif"));

		SendCmd(strCMD);
	}
	void GenerateGifWithPic() {
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD;

		//ffmpeg -r 1 -i .\\Pictrue\\%d.jpg 11.gif
		strCMD += _T("/c");
		strCMD += strPath;
		strCMD += (_T("ffmpeg\\ffmpeg -r 3 -i"));
		strCMD += strPath;
		strCMD += (_T("ffmpeg\\Picture\\%d.jpg .\\..\\debug\\ffmpeg\\outputpic.gif"));

		SendCmd(strCMD);
	}
	void GenerateASSFile() {


	}
	void LoadASS() {
		CDuiString StrPath = CPaintManagerUI::GetInstancePath();
		StrPath += _T("ffmpeg\\word.src");
		ifstream fIn(StrPath.GetData());
		
		char wordInfo[256];//ASCII
		CListUI* pListUI = (CListUI*)m_PaintManager.GetInstance();
		while (!fIn.eof()) {
			CListTextElementUI* pListItem = new CListTextElementUI;
			pListUI->Add(pListItem);

			//时间
			fIn.getline(wordInfo, 256);
			//SetText读取Unicode(宽字节)  -->转化
			wstring strTime = ANSIToUnicode(wordInfo);
			pListItem->SetText(0, strTime.c_str());

			//文本
			fIn.getline(wordInfo, 256);
			wstring strContent = ANSIToUnicode(wordInfo);
			pListItem->SetText(1, strContent.c_str());

		}
		fIn.close();
	}
	wstring ANSIToUnicode(const string& str)
	{
		int len = 0;
		len = str.length();
		int unicodeLen = ::MultiByteToWideChar(CP_ACP,0,str.c_str(),-1,NULL,0);
	
		wchar_t* pUnicode;
		pUnicode = new wchar_t[unicodeLen + 1];

		memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
		::MultiByteToWideChar(CP_ACP,0,str.c_str(),-1,(LPWSTR)pUnicode,unicodeLen);

		wstring rt(pUnicode);
		delete pUnicode;
		return rt;
	}
protected:
	CEditUI* m_pEditStart;
	CEditUI* m_pEditFinish;
};

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


