#pragma once	//��ֹͷ�ļ��ظ� ���� ֻ����һ��

#include <afxwin.h>

//Ӧ�ó��� CWinApp  �����ࣨ���ࣩ
class MyApp : public CWinApp
{
public:
	//������麯��
	//������ֻ����д
	virtual BOOL InitInstance(); //MFC�ĳ������

};

//����� CFrameWnd  �����ࣨ���ࣩ

class MyFrameWnd:public CFrameWnd
{
public:
	MyFrameWnd();

	//������Ϣӳ���
	DECLARE_MESSAGE_MAP();
	//������������������
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();


private:

};