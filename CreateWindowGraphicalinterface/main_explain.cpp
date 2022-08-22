//#include <windows.h>
//
//
//
//LPCSTR className = " "; //设置你的窗口类名
//LPCSTR caption = " "; //设置你的窗口标题
//int x = 0, y = 0; //设置你的窗口位置
//int width = 640, height = 480; //设置你的窗口宽高
//
////定义回调函数
////回调函数是用来处理消息的
////在消息循环的过程中，消息被分发到回调函数，回调函数内的代码提供操作
//long long WINAPI wndProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp) {
//	switch (msg)
//	{
//	case WM_CLOSE:
//	case WM_DESTROY:
//	case WM_QUIT:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//	return DefWindowProc(hwnd, msg, wp, lp);
//}
//
//
//
////注 控制台和窗口的不一致需要指定生成类型并写对应的入口
//int WINAPI WinMain(_In_ HINSTANCE hInst,//实例句柄
//				   _In_opt_ HINSTANCE hPrev,
//				   _In_ LPSTR lpComLine,
//				   _In_ int nShowCmd)
//{
//	WNDCLASSA wc;//窗口结构体 		//窗口类在winuser中的定义查看 tagWNDCLASSA
//	memset(&wc,0,sizeof(wc));//初始化wc 并赋值0 对字符串还有其他用法  https://www.cnblogs.com/pengjun-shanghai/p/4807354.html
//	wc.lpszClassName = className;
//	wc.hInstance = hInst;
//	wc.lpfnWndProc = wndProc;//回调函数
//	RegisterClassA(&wc);//注册窗口]
//	//HWND hwnd = CreateWindowA(className, caption, WS_VISIBLE | WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, hInst, NULL);  //创建窗口
//
//	HWND hwnd = CreateWindowA(
//		className,//窗口类名 要一致
//		"123",  //窗口标题
//		WS_VISIBLE | WS_OVERLAPPEDWINDOW , //窗口风格，
//		100,100, //窗口的位置xy
//		648,648,//窗口宽 长 大小
//		NULL, NULL,//父窗口 菜单 
//		hInst,//实例句柄
//		NULL);//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexa CreateWindowA 和CreateWindowW的区别
//	if (hwnd == NULL) return -1;
//	ShowWindow(hwnd, SW_SHOW); // 在CreateWindowA中指定窗口风格内填过后不需要此步骤，用于显示窗口
//	MSG msg;//消息类 用于消息循环
//	while (true) if(GetMessage(&msg,NULL,0,0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return 0;
//	//*修饰形参时标识这个变量为指针类型 进行调用时需要 & 符合修饰标识将地址传输
//
//}