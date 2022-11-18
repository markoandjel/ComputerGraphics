
// Lab3_PripremaView.h : interface of the CLab3PripremaView class
//
#include "DImage.h"
#pragma once


class CLab3PripremaView : public CView
{
protected: // create from serialization only
	CLab3PripremaView() noexcept;
	DECLARE_DYNCREATE(CLab3PripremaView)

// Attributes
private:
	DImage* Slike;
public:
	CLab3PripremaDoc* GetDocument() const;


// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void Translate(CDC* pDC, float dX, float dY, bool rightMultiply);
	virtual void Scale(CDC* pDC, float sX, float sY, bool rightMultiply);
	virtual void Rotate(CDC* pDC, float angle, bool rightMultiply);
	virtual void Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLab3PripremaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Lab3_PripremaView.cpp
inline CLab3PripremaDoc* CLab3PripremaView::GetDocument() const
   { return reinterpret_cast<CLab3PripremaDoc*>(m_pDocument); }
#endif

