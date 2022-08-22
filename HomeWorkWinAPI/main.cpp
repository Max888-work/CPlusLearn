#include <Windows.h>
#include <iostream>

//	a) ������ڣ���ȡ��������꣬ͨ���Ի�����ʾ����
//	��ʾ��a) ��λ�ȡ���鿴MSDN��ͨ����Ϣ�鿴�� WM_XXX�� window message(window��Ϣ)
//	      b) windows�£���ʽ���ַ���
//			  TCHAR  buf[1024] = { 0 };
//			  wsprintf(buf, TEXT("x = %d, y = %d"), 10, 10);
//			  
//	b) ���̰��£��ϣ��£����ң��� ͨ���Ի���ʾ����
//		����ֵ�ĺ꣨MSDN����VK_XXX�� virtual key�����ⰴ���� ����ĸ������ͨ��ASCIIֵ�Ƚ�




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
		MessageBox(hwnd, buf,TEXT("����"), MB_OK);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		case VK_UP:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		case VK_LEFT:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		case VK_RIGHT:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
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