#include <Windows.h>

LPCWSTR ClassName = TEXT("asd");
LPCWSTR WindowName = TEXT("测试");

long long WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(_In_ HINSTANCE hInst,
				   _In_opt_ HINSTANCE hPrev,
				   _In_ LPSTR lpComLine,
				   _In_ int nShowCom)
{

	WNDCLASSW WndClass;
	memset(&WndClass, 0, sizeof(WndClass));
	WndClass.lpszClassName = ClassName;
	WndClass.hInstance = hInst;
	WndClass.lpfnWndProc = WndProc;
	RegisterClassW(&WndClass);

	HWND hwnd = CreateWindowW(
		ClassName,
		WindowName,
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		100, 100,
		300, 300,
		NULL, NULL,
		hInst, NULL);
	if (hwnd == NULL) return -1;
	ShowWindow(hwnd, SW_SHOW);
	MSG msg;						//返回可能为-1 官方建议避免使用此声明
	while (GetMessage(&msg,NULL,0,0))//此处如果给hwnd则会只获取hwnd的消息，并且在hwnd关闭后无法接收WM_QUIT信息 造成无法退出 ；此处为NULL则接受线程中的所有窗口的消息
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return 0;

}

//Windows API函数对字符处理有3种格式：
//W结尾主要针对的是UNICODE编码，
//A结尾主要针对的是ASCII编码格式。
//Windows一般代码格式(Windows code page)，用A来指代ANSI。
//Unicode格式，用W来指代宽字符(Wide)。
//通常大部分版本均会编译为Windows一般代码格式或者Unicode格式。
//一些最新的方法只有Unicode版本。更多信息请参考函数原型的约定.
//UNICODE编码采取的方式是两个字节存储一个字符，而ASCII码采取的是一个字节存储一个字符。
//还有一个区别 ascii码不支持中文，只支持英文，所以有些ascii码乱码 也是ok理解的。