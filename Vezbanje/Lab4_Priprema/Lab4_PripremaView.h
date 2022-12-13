
// Lab4_PripremaView.h : interface of the CLab4PripremaView class
//

#pragma once

#include "CGLRenderer.h"

class CLab4PripremaView : public CView
{
protected: // create from serialization only
	CLab4PripremaView() noexcept;
	DECLARE_DYNCREATE(CLab4PripremaView)

// Attributes
public:
	CLab4PripremaDoc* GetDocument() const;
protected:
	CGLRenderer m_glRenderer;
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
	virtual ~CLab4PripremaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in Lab4_PripremaView.cpp
inline CLab4PripremaDoc* CLab4PripremaView::GetDocument() const
   { return reinterpret_cast<CLab4PripremaDoc*>(m_pDocument); }
#endif

