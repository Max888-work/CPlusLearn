//#include <windows.h>
//
//
//
//LPCSTR className = " "; //������Ĵ�������
//LPCSTR caption = " "; //������Ĵ��ڱ���
//int x = 0, y = 0; //������Ĵ���λ��
//int width = 640, height = 480; //������Ĵ��ڿ��
//
////����ص�����
////�ص�����������������Ϣ��
////����Ϣѭ���Ĺ����У���Ϣ���ַ����ص��������ص������ڵĴ����ṩ����
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
////ע ����̨�ʹ��ڵĲ�һ����Ҫָ���������Ͳ�д��Ӧ�����
//int WINAPI WinMain(_In_ HINSTANCE hInst,//ʵ�����
//				   _In_opt_ HINSTANCE hPrev,
//				   _In_ LPSTR lpComLine,
//				   _In_ int nShowCmd)
//{
//	WNDCLASSA wc;//���ڽṹ�� 		//��������winuser�еĶ���鿴 tagWNDCLASSA
//	memset(&wc,0,sizeof(wc));//��ʼ��wc ����ֵ0 ���ַ������������÷�  https://www.cnblogs.com/pengjun-shanghai/p/4807354.html
//	wc.lpszClassName = className;
//	wc.hInstance = hInst;
//	wc.lpfnWndProc = wndProc;//�ص�����
//	RegisterClassA(&wc);//ע�ᴰ��]
//	//HWND hwnd = CreateWindowA(className, caption, WS_VISIBLE | WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, hInst, NULL);  //��������
//
//	HWND hwnd = CreateWindowA(
//		className,//�������� Ҫһ��
//		"123",  //���ڱ���
//		WS_VISIBLE | WS_OVERLAPPEDWINDOW , //���ڷ��
//		100,100, //���ڵ�λ��xy
//		648,648,//���ڿ� �� ��С
//		NULL, NULL,//������ �˵� 
//		hInst,//ʵ�����
//		NULL);//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexa CreateWindowA ��CreateWindowW������
//	if (hwnd == NULL) return -1;
//	ShowWindow(hwnd, SW_SHOW); // ��CreateWindowA��ָ�����ڷ�����������Ҫ�˲��裬������ʾ����
//	MSG msg;//��Ϣ�� ������Ϣѭ��
//	while (true) if(GetMessage(&msg,NULL,0,0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return 0;
//	//*�����β�ʱ��ʶ�������Ϊָ������ ���е���ʱ��Ҫ & �������α�ʶ����ַ����
//
//}