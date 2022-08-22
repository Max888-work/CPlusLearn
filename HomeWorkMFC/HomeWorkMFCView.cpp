
// HomeWorkMFCView.cpp: CHomeWorkMFCView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HomeWorkMFC.h"
#endif

#include "HomeWorkMFCDoc.h"
#include "HomeWorkMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHomeWorkMFCView

IMPLEMENT_DYNCREATE(CHomeWorkMFCView, CView)

BEGIN_MESSAGE_MAP(CHomeWorkMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHomeWorkMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CHomeWorkMFCView 构造/析构

CHomeWorkMFCView::CHomeWorkMFCView() noexcept
{
	// TODO: 在此处添加构造代码

}

CHomeWorkMFCView::~CHomeWorkMFCView()
{
}

BOOL CHomeWorkMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHomeWorkMFCView 绘图

void CHomeWorkMFCView::OnDraw(CDC* /*pDC*/)
{
	CHomeWorkMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CHomeWorkMFCView 打印


void CHomeWorkMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHomeWorkMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHomeWorkMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHomeWorkMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CHomeWorkMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHomeWorkMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHomeWorkMFCView 诊断

#ifdef _DEBUG
void CHomeWorkMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CHomeWorkMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHomeWorkMFCDoc* CHomeWorkMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomeWorkMFCDoc)));
	return (CHomeWorkMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CHomeWorkMFCView 消息处理程序
//	a) 左击窗口，获取点击的坐标，通过对话框显示出来
//	提示：a) 如何获取，查看MSDN，通过消息查看， WM_XXX， window message(window信息)
//	      b) windows下，格式化字符串
//			  TCHAR  buf[1024] = { 0 };
//			  wsprintf(buf, TEXT("x = %d, y = %d"), 10, 10);
//			  
//	b) 键盘按下（上，下，左，右）， 通过对话显示出来
//		键盘值的宏（MSDN）：VK_XXX， virtual key（虚拟按键） 首字母，或者通过ASCII值比较
//	MFC字符串格式化
//	CString str;
//	str.Format(TEXT("%d, %d"), 10, 10);

void CHomeWorkMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(TEXT("X = %d , Y = %d"), point.x, point.y);
	AfxMessageBox(str);
	CView::OnLButtonDown(nFlags, point);
}


void CHomeWorkMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CHomeWorkMFCDoc* pDoc = GetDocument();

	switch (nChar)
	{
	case VK_LEFT:
		::MessageBox(NULL,_T ("左"),_T("键盘操作") , MB_OK);
		break;
	default:
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
