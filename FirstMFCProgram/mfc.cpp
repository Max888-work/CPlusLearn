#include "mfc.h"

//����ֻ��һ��ȫ�ֵ�Ӧ�ó��������
MyApp myApp;

//�������ڵ�ַ
BOOL MyApp::InitInstance()
{
	/*
	1��������������
	2����ʾ����
	3�����´���
	4�������������ָ��
	*/
	//������������
	MyFrameWnd *myFramWnd = new MyFrameWnd;

	myFramWnd->ShowWindow(SW_SHOWNORMAL);
	myFramWnd->UpdateWindow();
	//	4�������������ָ��
	m_pMainWnd = myFramWnd;
	return TRUE;
}
//������Ϣ��
BEGIN_MESSAGE_MAP(MyFrameWnd, CFrameWnd) //������ ����
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrameWnd::MyFrameWnd()
{ 
	//CWnd��ĳ�Ա����
	//CFrameWnd �Ǽ̳���CWnd
	Create(NULL,//��׼����
		TEXT("MFC"));//����
		  
}

void MyFrameWnd::OnLButtonDown(UINT, CPoint)
{
	//Cwnd :: MessageBox
	MessageBox(TEXT("����������"));
}

void MyFrameWnd::OnPaint()
{
	const COLORREF rgbRed = 0x00FF0000;

	CPaintDC dc(this);
	dc.SetTextColor(rgbRed);
	dc.TextOutW(100, 100, TEXT("����"));
}




