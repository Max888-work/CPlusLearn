#include <Windows.h>

LPCWSTR ClassName = TEXT("asd");
LPCWSTR WindowName = TEXT("����");

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
	MSG msg;						//���ؿ���Ϊ-1 �ٷ��������ʹ�ô�����
	while (GetMessage(&msg,NULL,0,0))//�˴������hwnd���ֻ��ȡhwnd����Ϣ��������hwnd�رպ��޷�����WM_QUIT��Ϣ ����޷��˳� ���˴�ΪNULL������߳��е����д��ڵ���Ϣ
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return 0;

}

//Windows API�������ַ�������3�ָ�ʽ��
//W��β��Ҫ��Ե���UNICODE���룬
//A��β��Ҫ��Ե���ASCII�����ʽ��
//Windowsһ������ʽ(Windows code page)����A��ָ��ANSI��
//Unicode��ʽ����W��ָ�����ַ�(Wide)��
//ͨ���󲿷ְ汾�������ΪWindowsһ������ʽ����Unicode��ʽ��
//һЩ���µķ���ֻ��Unicode�汾��������Ϣ��ο�����ԭ�͵�Լ��.
//UNICODE�����ȡ�ķ�ʽ�������ֽڴ洢һ���ַ�����ASCII���ȡ����һ���ֽڴ洢һ���ַ���
//����һ������ ascii�벻֧�����ģ�ֻ֧��Ӣ�ģ�������Щascii������ Ҳ��ok���ġ�