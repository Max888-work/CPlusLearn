
// MFCAppPaintLineView.cpp: CMFCAppPaintLineView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCAppPaintLine.h"
#endif

#include "MFCAppPaintLineDoc.h"
#include "MFCAppPaintLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppPaintLineView

IMPLEMENT_DYNCREATE(CMFCAppPaintLineView, CListView)

BEGIN_MESSAGE_MAP(CMFCAppPaintLineView, CListView)
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCAppPaintLineView 构造/析构

CMFCAppPaintLineView::CMFCAppPaintLineView() noexcept
{
	// TODO: 在此处添加构造代码
}

CMFCAppPaintLineView::~CMFCAppPaintLineView()
{
}

BOOL CMFCAppPaintLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void CMFCAppPaintLineView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}

void CMFCAppPaintLineView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCAppPaintLineView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCAppPaintLineView 诊断

#ifdef _DEBUG
void CMFCAppPaintLineView::AssertValid() const
{
	CListView::AssertValid();
}

void CMFCAppPaintLineView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMFCAppPaintLineDoc* CMFCAppPaintLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppPaintLineDoc)));
	return (CMFCAppPaintLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppPaintLineView 消息处理程序
void CMFCAppPaintLineView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: 添加代码以响应用户对窗口视图样式的更改
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);
}



//鼠标落下记录点
void CMFCAppPaintLineView::OnLButtonDown(UINT nFlags, CPoint point)
{


// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point); //插入符移动
	str.Empty();

	m_Point = point;
	//CClientDC cdc(this);
	//const COLORREF rgbRed = 0x00FF0000;
	//const COLORREF normal = cdc.GetDCBrushColor();
	//CPoint m_Point1;

	//for (size_t i = 0; i < 500; i++)
	//{
	//	if (i< 250)
	//	{
	//		m_Point1.x = m_Point.x + 1;
	//		m_Point1.y = m_Point.y - 1;
	//		cdc.MoveTo(m_Point);
	//		cdc.LineTo(m_Point1);
	//		m_Point = m_Point1;
	//	}
	//	else
	//	{
	//		m_Point1.x = m_Point.x + 1;
	//		m_Point1.y = m_Point.y + 1;
	//		cdc.MoveTo(m_Point);
	//		cdc.LineTo(m_Point1);
	//		m_Point = m_Point1;
	//	}
	//}
	//CListView::OnLButtonDown(nFlags, point);
}


void CMFCAppPaintLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	//dc.MoveTo(m_Point);
	//dc.LineTo(point);

	CListView::OnLButtonUp(nFlags, point);
}


void CMFCAppPaintLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CClientDC dc(this);
	dc.MoveTo(m_Point);
	dc.LineTo(point);
	m_Point = point;
	CListView::OnMouseMove(nFlags, point);*/
}


void CMFCAppPaintLineView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	CMFCAppPaintLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen *pen = new CPen(PS_DASH, 1, RGB(255, 0, 0));
	CPen *OldPen =  pDC->SelectObject(pen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(220, 100);
	//返回初始画笔；
	pDC->SelectObject(OldPen);
	pDC->Ellipse(120, 120, 220, 220);
	CBrush* brush1 = new CBrush(RGB(255, 0, 0));
	pDC->SelectObject(brush1);
	pDC->Ellipse(120, 120, 220, 220);

	CBrush* brush = new CBrush(HS_BDIAGONAL,RGB(255,0,0));
	pDC->SelectObject(brush);
	pDC->Ellipse(320, 320, 420, 420);


	CBitmap bit;
	bit.LoadBitmapW(IDB_BITMAP1);
	CBrush *brushBit = new CBrush(&bit);
	pDC->SelectObject(brushBit);
	pDC->Ellipse(520, 520, 620, 620);

	CFont font;
	font.CreatePointFont(120, TEXT("宋体"));
	pDC->SelectObject(&font);
	pDC->TextOutW(600, 200, _T("字体刷"));

}






void CMFCAppPaintLineView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CListView::OnPaint()
	OnDraw(&dc);
}


int CMFCAppPaintLineView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CClientDC Cdc(this);
	TEXTMETRIC text;
	Cdc.GetTextMetrics(&text);

	CreateSolidCaret(text.tmAveCharWidth/8,text.tmHeight);
	ShowCaret();
	return 0;
}


void CMFCAppPaintLineView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CString str1;
	//str1.Format(_T("%c"), nChar);
	CPoint caret;
	CClientDC dc(this);
	CSize size = dc.GetTextExtent(str);
	caret.y = m_Point.y;
	if (nChar == VK_RETURN) //换行
	{
		str.Empty();
		caret.y = m_Point.y + size.cy;
		m_Point.y = caret.y;
	}
	else if (nChar == VK_BACK) {
		COLORREF color = dc.GetBkColor();
		COLORREF oldcolor = dc.SetTextColor(color);
		dc.TextOutW(m_Point.x, m_Point.y, str);
		str = str.Left(str.GetLength() - 1);
		dc.SetTextColor(oldcolor);
		dc.TextOutW(m_Point.x, m_Point.y, str);

	}
	else
	{
		str += (TCHAR)nChar;
	}
	size = dc.GetTextExtent(str);
	caret.x = m_Point.x + size.cx;
	HideCaret();  
	dc.TextOutW(m_Point.x, m_Point.y, str);
	ShowCaret();
	SetCaretPos(caret);
	//CListView::OnChar(nChar, nRepCnt, nFlags);
}
