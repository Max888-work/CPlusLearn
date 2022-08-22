#include <Windows.h>
#include <iostream>

//	a) 左击窗口，获取点击的坐标，通过对话框显示出来
//	提示：a) 如何获取，查看MSDN，通过消息查看， WM_XXX， window message(window信息)
//	      b) windows下，格式化字符串
//			  TCHAR  buf[1024] = { 0 };
//			  wsprintf(buf, TEXT("x = %d, y = %d"), 10, 10);
//			  
//	b) 键盘按下（上，下，左，右）， 通过对话显示出来
//		键盘值的宏（MSDN）：VK_XXX， virtual key（虚拟按键） 首字母，或者通过ASCII值比较




LPCWSTR ClassName = TEXT("Test");
LPCWSTR WindowName = TEXT("Window");

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR buf[1024] = { 0 };

	switch (msg)
	{
	case WM_LBUTTONDOWN:
		POINT point;
		RECT rect;
		GetCursorPos(&point);
		GetWindowRect(hwnd, &rect);
		wsprintf(buf, TEXT("x = %d ,y = %d"), point.x-rect.left, point.y-rect.top);
		MessageBox(hwnd, buf,TEXT("坐标"), MB_OK);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			MessageBox(hwnd, TEXT("下"), TEXT("键盘操作"), MB_OK);
			break;
		case VK_UP:
			MessageBox(hwnd, TEXT("上"), TEXT("键盘操作"), MB_OK);
			break;
		case VK_LEFT:
			MessageBox(hwnd, TEXT("左"), TEXT("键盘操作"), MB_OK);
			break;
		case VK_RIGHT:
			MessageBox(hwnd, TEXT("右"), TEXT("键盘操作"), MB_OK);
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}



int WINAPI WinMain(_In_ HINSTANCE hInst,
				   __in_opt HINSTANCE hPrev,
				   _In_ LPSTR lpComLine,
				   _In_ int nShowCom) 
{
	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.lpszClassName = ClassName;
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	RegisterClass(&wc);
	HWND hwnd =  CreateWindow(
		ClassName,
		WindowName,
		WS_OVERLAPPEDWINDOW,
		100, 100, 300, 300,
		NULL, NULL, hInst, NULL);
	if (hwnd == NULL) return -1;
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	MSG msg;
	BOOL bRet = FALSE;

	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}