#pragma once	//防止头文件重复 包含 只调用一次

#include <afxwin.h>

//应用程序 CWinApp  派生类（子类）
class MyApp : public CWinApp
{
public:
	//基类的虚函数
	//派生类只是重写
	virtual BOOL InitInstance(); //MFC的程序入口

};

//框架类 CFrameWnd  派生类（子类）

class MyFrameWnd:public CFrameWnd
{
public:
	MyFrameWnd();

	//声明消息映射宏
	DECLARE_MESSAGE_MAP();
	//创建鼠标左键方法声明
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();


private:

};