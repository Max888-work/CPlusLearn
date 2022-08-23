#include <Windows.h>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <intsafe.h>
//	a) 左击窗口，获取点击的坐标，通过对话框显示出来
//	提示：a) 如何获取，查看MSDN，通过消息查看， WM_XXX， window message(window信息)
//	      b) windows下，格式化字符串
//			  TCHAR  buf[1024] = { 0 };
//			  wsprintf(buf, TEXT("x = %d, y = %d"), 10, 10);
//			  
//	b) 键盘按下（上，下，左，右）， 通过对话显示出来
//		键盘值的宏（MSDN）：VK_XXX， virtual key（虚拟按键） 首字母，或者通过ASCII值比较


LPDIRECT3D9             g_pD3D = NULL; //Direct3D对象
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; //Direct3D设备对象
LPD3DXLINE              g_pLine = NULL; //Direct3D线对象
D3DXVECTOR2* g_pLineArr = NULL; //线段顶点 


//-----------------------------------------------------------------------------
// Desc: 初始化Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D(HWND hWnd)
{
	//创建Direct3D对象, 该对象用来创建Direct3D设备对象
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	//设置D3DPRESENT_PARAMETERS结构, 准备创建Direct3D设备对象
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	//创建Direct3D设备对象
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	// 创建Direct3D线对象
	if (FAILED(D3DXCreateLine(g_pd3dDevice, &g_pLine)))
	{
		return E_FAIL;
	}

	//填充线顶点,注意：线填充的都是屏幕坐标，不需要转换
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
// Desc: 释放创建对象
//-----------------------------------------------------------------------------
VOID Cleanup()
{
	// 释放Line对象
	if (g_pLine != NULL)
	{
		g_pLine->Release();
	}
	//释放Direct3D设备对象
	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	//释放Direct3D对象
	if (g_pD3D != NULL)
		g_pD3D->Release();
}


//-----------------------------------------------------------------------------
// Desc: 渲染图形
//-----------------------------------------------------------------------------
VOID Render()
{
	//清空后台缓冲区
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(43, 43, 43), 1.0f, 0);

	//开始在后台缓冲区绘制图形
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		//绘制线
		g_pLine->SetWidth(3.f);
		g_pLine->SetAntialias(TRUE);
		g_pLine->Draw(g_pLineArr, 4, 0xffffffff);

		//结束在后台缓冲区渲染图形
		g_pd3dDevice->EndScene();
	}

	//将在后台缓冲区绘制的图形提交到前台缓冲区显示
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}


//-----------------------------------------------------------------------------
// Desc: 消息处理
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
		MessageBox(hwnd, buf,TEXT("坐标"), MB_OK);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			MessageBox(hwnd, TEXT("下"), TEXT("键盘操作"), MB_OK);
			break;
		case VK_UP:
			MessageBox(hwnd, TEXT("上"), TEXT("键盘操作"), MB_OK);
			break;
		case VK_LEFT:
			MessageBox(hwnd, TEXT("左"), TEXT("键盘操作"), MB_OK);
			break;
		case VK_RIGHT:
			MessageBox(hwnd, TEXT("右"), TEXT("键盘操作"), MB_OK);
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
		//显示主窗口
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);

		//进入消息循环
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
				Render();  //渲染图形
			}
		}
	}




#if 0
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			//Render();  //渲染图形
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