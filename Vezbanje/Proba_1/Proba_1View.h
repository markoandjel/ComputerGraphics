
// Proba_1View.h : interface of the CProba1View class
//

#pragma once


class CProba1View : public CView
{
protected: // create from serialization only
	CProba1View() noexcept;
	DECLARE_DYNCREATE(CProba1View)

// Attributes
public:
	CProba1Doc* GetDocument() const;

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
	virtual ~CProba1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Proba_1View.cpp
inline CProba1Doc* CProba1View::GetDocument() const
   { return reinterpret_cast<CProba1Doc*>(m_pDocument); }
#endif

