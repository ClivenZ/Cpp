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



