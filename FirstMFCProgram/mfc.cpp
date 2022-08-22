#include "mfc.h"

//有且只有一个全局的应用程序类对象
MyApp myApp;

//程序的入口地址
BOOL MyApp::InitInstance()
{
	/*
	1、创建框架类对象
	2、显示窗口
	3、更新窗口
	4、保存框架类对象指针
	*/
	//创建框架类对象
	MyFrameWnd *myFramWnd = new MyFrameWnd;

	myFramWnd->ShowWindow(SW_SHOWNORMAL);
	myFramWnd->UpdateWindow();
	//	4、保存框架类对象指针
	m_pMainWnd = myFramWnd;
	return TRUE;
}
//定义消息宏
BEGIN_MESSAGE_MAP(MyFrameWnd, CFrameWnd) //派生类 基类
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrameWnd::MyFrameWnd()
{ 
	//CWnd类的成员函数
	//CFrameWnd 是继承于CWnd
	Create(NULL,//标准类名
		TEXT("MFC"));//标题
		  
}

void MyFrameWnd::OnLButtonDown(UINT, CPoint)
{
	//Cwnd :: MessageBox
	MessageBox(TEXT("鼠标左键落下"));
}

void MyFrameWnd::OnPaint()
{
	const COLORREF rgbRed = 0x00FF0000;

	CPaintDC dc(this);
	dc.SetTextColor(rgbRed);
	dc.TextOutW(100, 100, TEXT("测试"));
}




