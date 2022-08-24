
// MFCAppPaintLineView.h: CMFCAppPaintLineView 类的接口
//

#pragma once


class CMFCAppPaintLineView : public CListView
{
protected: // 仅从序列化创建
	CMFCAppPaintLineView() noexcept;
	DECLARE_DYNCREATE(CMFCAppPaintLineView)

// 特性
public:
	CMFCAppPaintLineDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCAppPaintLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_Point;
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString str;
};

#ifndef _DEBUG  // MFCAppPaintLineView.cpp 中的调试版本
inline CMFCAppPaintLineDoc* CMFCAppPaintLineView::GetDocument() const
   { return reinterpret_cast<CMFCAppPaintLineDoc*>(m_pDocument); }
#endif

