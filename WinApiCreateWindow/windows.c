#include <Windows.h>

LPCWSTR ClassName = TEXT(" ");
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hwnd,msg,wParam,lParam);//Ĭ����Ϣ����
}
//WINAPI :���κ��� �涨����������ջ	�������󣬺���������ϣ��Զ������ջ
int WINAPI WinMain(_In_ HINSTANCE hIns, //Ӧ�ó���ʵ��
				   _In_opt_ HINSTANCE hPrevIns, //��һ��Ӧ�ó���ʵ��
					_In_ LPSTR lpCmdLine, //�����в���  long pointer string ָ��ָ���ַ��� char*
				    _In_ int nConShow)  //���ڵ���ʽ �����С��
{
	WNDCLASS WndClass;//��ƴ�����
	WndClass.cbClsExtra = 0;//��ĸ�����Ϣ
	WndClass.cbWndExtra = 0;//���ڸ�����Ϣ
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //����ɫ
	WndClass.hCursor = LoadCursor(NULL, IDC_HELP);//����Ĭ�Ϲ��
	WndClass.hIcon = LoadIcon(NULL, IDI_WARNING);//ϵͳĬ��ͼ��
	WndClass.hInstance = hIns;
	WndClass.lpszClassName = ClassName; //����
	WndClass.lpfnWndProc = WndProc; 
	WndClass.lpszMenuName = NULL;//�˵�����
	WndClass.style = nConShow;//��ʾ���

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

		//���빤��  �罫ʵ����̵���Ϣ֪ͨת��Ϊ���ⰴ����Ϣ��������ӵ���Ϣ������
		TranslateMessage(&msg);

		//������ϵͳ�ַ���Ϣ
		DispatchMessage(&msg);
	}
	return 0;
}
	