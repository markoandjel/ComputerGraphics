
// Lab1_CirkoView.h : interface of the CLab1CirkoView class
//

#pragma once


class CLab1CirkoView : public CView
{
protected: // create from serialization only
	CLab1CirkoView() noexcept;
	DECLARE_DYNCREATE(CLab1CirkoView)

// Attributes
private:
	bool grid;
public:
	CLab1CirkoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLab1CirkoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in Lab1_CirkoView.cpp
inline CLab1CirkoDoc* CLab1CirkoView::GetDocument() const
   { return reinterpret_cast<CLab1CirkoDoc*>(m_pDocument); }
#endif

