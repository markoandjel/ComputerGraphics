
// Lab2ProbaView.h : interface of the CLab2ProbaView class
//

#pragma once


class CLab2ProbaView : public CView
{
protected: // create from serialization only
	CLab2ProbaView() noexcept;
	DECLARE_DYNCREATE(CLab2ProbaView)

// Attributes
public:
	CLab2ProbaDoc* GetDocument() const;

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
	virtual ~CLab2ProbaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Lab2ProbaView.cpp
inline CLab2ProbaDoc* CLab2ProbaView::GetDocument() const
   { return reinterpret_cast<CLab2ProbaDoc*>(m_pDocument); }
#endif

