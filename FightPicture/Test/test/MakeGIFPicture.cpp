#if 0
#include<tchar.h>
#include<windows.h>


//unicode <- ansi  _T()ת��

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
//��Ϣ�ص�����
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		if (IDOK == MessageBox(hWnd, _T("��ȷ���˳���"), _T("�˳�"), MB_OKCANCEL))
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
	//Step1:ע��һ��������
	HWND hwnd;                //���ڵľ��
	WNDCLASSEX wc;            //������ṹ
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszMenuName = 0;
	wc.lpszClassName = _T("Win32");
	wc.lpfnWndProc = WinProc; //��Ϣ�ص�����
	wc.hInstance = hInstance;
	wc.hIcon = NULL;		  //ϵͳĬ��ͼ��
	wc.hCursor = NULL;        //���
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);    //ע�ᴰ��
	//Step2:����һ������
	hwnd = CreateWindow(
		_T("Win32"), //���ڵ�������Ҳ�������������Զ���Ĵ����������
		_T("�ҵĵ�һ��Win32����"), //���ڵı���
		WS_OVERLAPPEDWINDOW, //����style
		500, //����λ��x����
		300, //����λ��y����
		800, //���ڿ��
		600, //���ڸ߶�
		NULL, //�����ھ��
		NULL, //�˵����
		hInstance, //ʵ�����
		NULL //��������
	);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //��ʾ����
	UpdateWindow(hwnd); //ˢ��
	//Step3:��Ϣѭ��
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
				::MessageBox(NULL,_T("��ť"),_T("����˰�ť"),NULL);
			}
		}
	}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			//CControlUI* pWnd = new CButtonUI;
			////���ÿؼ������ƣ����������ڱ�ʶÿһ���ؼ�������Ψһ���൱��MFC����Ŀؼ�ID
			//pWnd->SetName(_T("bntHello"));
			//// ��������
			//pWnd->SetText(_T("Hello World"));
			//// ���ñ���ɫ
			//pWnd->SetBkColor(0xFF00FF00);       

			//m_PaintManager.Init(m_hWnd);
			//m_PaintManager.AttachDialog(pWnd);
			////��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽdublib����Ϣѭ������Notify��������Ϣ����
			//m_PaintManager.AddNotifier(this);
			//return lRes;
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			// duilib.xml��Ҫ�ŵ�exeĿ¼��
			//CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   
			CControlUI* pRoot = builder.Create(_T("UISkin1.xml"), (UINT)0, NULL, &m_PaintManager);
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			// ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
			m_PaintManager.AddNotifier(this);   
			return lRes;
		}
		// ����3����ϢWM_NCACTIVATE��WM_NCCALCSIZE��WM_NCPAINT��������ϵͳ������
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
				::MessageBox(NULL, _T("��ť"), _T("����˰�ť"), NULL);
			}
		}
	}
	virtual void InitWindow()
	{

		CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));

		if (pActiveXUI)
		{
			IWebBrowser2* pWebBrowser = NULL;

			pActiveXUI->SetDelayCreate(false);              // �൱�ڽ�����������DelayCreate���Ը�ΪFALSE����duilib�Դ���FlashDemo����Կ���������ΪTRUE             
			pActiveXUI->CreateControl(CLSID_WebBrowser);    // �൱�ڽ�����������Clsid����������{8856F961-340A-11D0-A96B-00C04FD705A2}��������CLSID_WebBrowser������뿴��Ӧ��ֵ�����<ExDisp.h>
			pActiveXUI->GetControl(IID_IWebBrowser2, (void**)& pWebBrowser);

//			if (pWebBrowser != NULL)
//			{
//				//pWebBrowser->Navigate(L"https://code.google.com/p/duilib/",NULL,NULL,NULL,NULL);  
////			      pWebBrowser->Navigate(L"http://www.baidu.com/", NULL, NULL, NULL, NULL);  // ���ڹȸ�ʱ��ʱ��ǽ�����Ի��ɷ�Ӧ�����վ
//				pWebBrowser->Release();
//			}
		}
		CDuiString str;
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("ListDemo1")));

		// ���List�б����ݣ�������Add(pListElement)����SetText
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
		// ���List�б����ݣ�������Add(pListElement)����SetText
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
	//��cmd�����������ffempg
	void SendCmd(const CDuiString& strCMD) {
		CDuiString strFFmepgPath = CPaintManagerUI::GetInstancePath();

		//��ʼ���ṹ��
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\system32\\cmd.exe");
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE;

		//����
		ShellExecuteEx(&strSEInfo);
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
		MessageBox(m_hWnd,_T("Finished"),_T("GIF"),IDOK);
	}
#endif
	//�����ļ�
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
			MessageBox(NULL, _T("�����ļ�·��"), _T("BTN"), IDOK);
		}
	}
	//�ü���Ƶ
	void CutView() {
		CDuiString strStartTime = m_pEditStart->GetText();
		if (IsValidTime(strStartTime)) {
			MessageBox(m_hWnd,_T("��ʼʱ������"),_T("Error!"),IDOK);
			return;
		}
		CDuiString strFinishTime = m_pEditFinish->GetText();
		if (IsValidTime(strFinishTime)) {
			MessageBox(m_hWnd, _T("����ʱ������"), _T("Error!"), IDOK);
			return;
		}
		MessageBox(NULL,_T("��ȡ��Ƶ"),_T("BTN"),IDOK);


		//��������
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

			//ʱ��
			fIn.getline(wordInfo, 256);
			//SetText��ȡUnicode(���ֽ�)  -->ת��
			wstring strTime = ANSIToUnicode(wordInfo);
			pListItem->SetText(0, strTime.c_str());

			//�ı�
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

	// ���������new��������ActiveX�ؼ�ʱ���رմ��ڻ��������
	CDuiFrameWnd* pFrame = new CDuiFrameWnd;    
	pFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	pFrame->ShowModal();

	delete pFrame;
	::CoUninitialize();
	return 0;
}


