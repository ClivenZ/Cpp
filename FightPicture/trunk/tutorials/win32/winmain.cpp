#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

// ���ڹ���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message)
	{
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, "�㵥����������", "WM_LBUTTONDOWN", MB_OK);
		break;
	case WM_CHAR:
		char szChar[64];
		sprintf_s(szChar, 64, "�㰴���˼��̼�:%c", wParam);
		MessageBox(hWnd, szChar, "WM_CHAR", MB_OK);
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			// TODO: �ڴ���������ͼ����...
			SetTextColor(hdc, RGB(255,0,0));
			SetBkColor(hdc, RGB(0,255,0));
			TextOut(hdc, 200, 200, "Hello World!", strlen("Hello World!"));
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine, int       nCmdShow){
	// ע�ᴰ����
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_HAND);
	wcex.hbrBackground	= (HBRUSH)(GetStockObject(BLACK_BRUSH));
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "mywndclass";
	wcex.hIconSm		= NULL;
	RegisterClassEx(&wcex);

	// ��������
	HWND hWnd = CreateWindowEx(0, "mywndclass", "This is a win32 wnd", WS_OVERLAPPEDWINDOW,
		100, 100, 800, 600, NULL, NULL, hInstance, NULL);

	// ��ʾ����
	ShowWindow(hWnd, nCmdShow);

	// ������Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}