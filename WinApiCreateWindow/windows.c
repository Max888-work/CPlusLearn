#include <Windows.h>

LPCWSTR ClassName = TEXT(" ");
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hwnd,msg,wParam,lParam);//默认消息处理
}
//WINAPI :修饰函数 规定函数参数入栈	从右往左，函数调用完毕，自动清理堆栈
int WINAPI WinMain(_In_ HINSTANCE hIns, //应用程序实例
				   _In_opt_ HINSTANCE hPrevIns, //上一个应用程序实例
					_In_ LPSTR lpCmdLine, //命令行参数  long pointer string 指针指向字符串 char*
				    _In_ int nConShow)  //窗口的样式 最大化最小化
{
	WNDCLASS WndClass;//设计窗口类
	WndClass.cbClsExtra = 0;//类的附加信息
	WndClass.cbWndExtra = 0;//窗口附加信息
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景色
	WndClass.hCursor = LoadCursor(NULL, IDC_HELP);//加载默认光标
	WndClass.hIcon = LoadIcon(NULL, IDI_WARNING);//系统默认图标
	WndClass.hInstance = hIns;
	WndClass.lpszClassName = ClassName; //类名
	WndClass.lpfnWndProc = WndProc; 
	WndClass.lpszMenuName = NULL;//菜单名称
	WndClass.style = nConShow;//显示风格

	RegisterClass(&WndClass);

	HWND hwnd = CreateWindow(
		ClassName,
		TEXT("test"),
		WS_OVERLAPPEDWINDOW,
		100, 100,
		300, 300,
		NULL, NULL,
		hIns, NULL);
	if (hwnd == NULL) return -1;
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg,hwnd,0,0))
	{

		//翻译工作  如将实体键盘的消息通知转化为虚拟按键信息并重新添加到消息队列中
		TranslateMessage(&msg);

		//给操作系统分发消息
		DispatchMessage(&msg);
	}
	return 0;
}
	