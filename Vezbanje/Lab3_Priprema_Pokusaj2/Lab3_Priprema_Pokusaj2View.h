
// Lab3_Priprema_Pokusaj2View.h : interface of the CLab3PripremaPokusaj2View class
//
#include "DImage.h"
#pragma once


class CLab3PripremaPokusaj2View : public CView
{
protected: // create from serialization only
	CLab3PripremaPokusaj2View() noexcept;
	DECLARE_DYNCREATE(CLab3PripremaPokusaj2View)

// Attributes
public:
	CLab3PripremaPokusaj2Doc* GetDocument() const;
	DImage* Slike;
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
	virtual void Rotate(CDC* pDC, float angle, bool rightMultiply);
	virtual void Scale(CDC* pDC, float sX, float sY, bool rightMultiply);
	virtual void Translate(CDC* pDC, float dX, float dY, bool rightMultiply);
	virtual void Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply);
	virtual void PribaviSliku(CDC* pDC, int i, bool blueFilter);
	virtual void NacrtajSliku(CDC* pDC);

// Implementation
public:
	virtual ~CLab3PripremaPokusaj2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Lab3_Priprema_Pokusaj2View.cpp
inline CLab3PripremaPokusaj2Doc* CLab3PripremaPokusaj2View::GetDocument() const
   { return reinterpret_cast<CLab3PripremaPokusaj2Doc*>(m_pDocument); }
#endif

