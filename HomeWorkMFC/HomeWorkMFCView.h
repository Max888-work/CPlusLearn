
// HomeWorkMFCView.h: CHomeWorkMFCView 类的接口
//

#pragma once


class CHomeWorkMFCView : public CView
{
protected: // 仅从序列化创建
	CHomeWorkMFCView() noexcept;
	DECLARE_DYNCREATE(CHomeWorkMFCView)

// 特性
public:
	CHomeWorkMFCDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CHomeWorkMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // HomeWorkMFCView.cpp 中的调试版本
inline CHomeWorkMFCDoc* CHomeWorkMFCView::GetDocument() const
   { return reinterpret_cast<CHomeWorkMFCDoc*>(m_pDocument); }
#endif

