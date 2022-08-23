#include <Windows.h>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <intsafe.h>
//	a) ������ڣ���ȡ��������꣬ͨ���Ի�����ʾ����
//	��ʾ��a) ��λ�ȡ���鿴MSDN��ͨ����Ϣ�鿴�� WM_XXX�� window message(window��Ϣ)
//	      b) windows�£���ʽ���ַ���
//			  TCHAR  buf[1024] = { 0 };
//			  wsprintf(buf, TEXT("x = %d, y = %d"), 10, 10);
//			  
//	b) ���̰��£��ϣ��£����ң��� ͨ���Ի���ʾ����
//		����ֵ�ĺ꣨MSDN����VK_XXX�� virtual key�����ⰴ���� ����ĸ������ͨ��ASCIIֵ�Ƚ�


LPDIRECT3D9             g_pD3D = NULL; //Direct3D����
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; //Direct3D�豸����
LPD3DXLINE              g_pLine = NULL; //Direct3D�߶���
D3DXVECTOR2* g_pLineArr = NULL; //�߶ζ��� 


//-----------------------------------------------------------------------------
// Desc: ��ʼ��Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D(HWND hWnd)
{
	//����Direct3D����, �ö�����������Direct3D�豸����
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	//����D3DPRESENT_PARAMETERS�ṹ, ׼������Direct3D�豸����
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	//����Direct3D�豸����
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	// ����Direct3D�߶���
	if (FAILED(D3DXCreateLine(g_pd3dDevice, &g_pLine)))
	{
		return E_FAIL;
	}

	//����߶���,ע�⣺�����Ķ�����Ļ���꣬����Ҫת��
	g_pLineArr = new D3DXVECTOR2[4];
	g_pLineArr[0].x = g_pLineArr[0].y = 50;
	g_pLineArr[1].x = 100;
	g_pLineArr[1].y = 50;
	g_pLineArr[2].x = 50;
	g_pLineArr[2].y = 100;
	g_pLineArr[3].x = 100;
	g_pLineArr[3].y = 100;

	return S_OK;
}


//-----------------------------------------------------------------------------
// Desc: �ͷŴ�������
//-----------------------------------------------------------------------------
VOID Cleanup()
{
	// �ͷ�Line����
	if (g_pLine != NULL)
	{
		g_pLine->Release();
	}
	//�ͷ�Direct3D�豸����
	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	//�ͷ�Direct3D����
	if (g_pD3D != NULL)
		g_pD3D->Release();
}


//-----------------------------------------------------------------------------
// Desc: ��Ⱦͼ��
//-----------------------------------------------------------------------------
VOID Render()
{
	//��պ�̨������
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(43, 43, 43), 1.0f, 0);

	//��ʼ�ں�̨����������ͼ��
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		//������
		g_pLine->SetWidth(3.f);
		g_pLine->SetAntialias(TRUE);
		g_pLine->Draw(g_pLineArr, 4, 0xffffffff);

		//�����ں�̨��������Ⱦͼ��
		g_pd3dDevice->EndScene();
	}

	//���ں�̨���������Ƶ�ͼ���ύ��ǰ̨��������ʾ
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}


//-----------------------------------------------------------------------------
// Desc: ��Ϣ����
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		Render();
		ValidateRect(hWnd, NULL);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}


LPCWSTR ClassName = TEXT("Test");
LPCWSTR WindowName = TEXT("Window");

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR buf[1024] = { 0 };

	switch (msg)
	{
	case WM_LBUTTONDOWN:
		POINT point;
		RECT rect;
		GetCursorPos(&point);
		GetWindowRect(hwnd, &rect);
		wsprintf(buf, TEXT("x = %d ,y = %d"), point.x-rect.left, point.y-rect.top);
		MessageBox(hwnd, buf,TEXT("����"), MB_OK);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		case VK_UP:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		case VK_LEFT:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		case VK_RIGHT:
			MessageBox(hwnd, TEXT("��"), TEXT("���̲���"), MB_OK);
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}



int WINAPI WinMain(_In_ HINSTANCE hInst,
				   __in_opt HINSTANCE hPrev,
				   _In_ LPSTR lpComLine,
				   _In_ int nShowCom) 
{















	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.lpszClassName = ClassName;
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	RegisterClass(&wc);
	HWND hwnd =  CreateWindow(
		ClassName,
		WindowName,
		WS_OVERLAPPEDWINDOW,
		100, 100, 300, 300,
		NULL, NULL, hInst, NULL);
	if (hwnd == NULL) return -1;
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	MSG msg;
	BOOL bRet = FALSE;
	if (SUCCEEDED(InitD3D(hwnd)))
	{
		//��ʾ������
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);

		//������Ϣѭ��
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
}
			else
			{
				Render();  //��Ⱦͼ��
			}
		}
	}




#if 0
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			//Render();  //��Ⱦͼ��
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
#endif
	UnregisterClass(L"ClassName", wc.hInstance);
	return 0;
}