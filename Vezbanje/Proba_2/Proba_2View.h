
// Proba_2View.h : interface of the CProba2View class
//

#pragma once


class CProba2View : public CView
{
protected: // create from serialization only
	CProba2View() noexcept;
	DECLARE_DYNCREATE(CProba2View)

// Attributes
public:
	CProba2Doc* GetDocument() const;

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
	virtual ~CProba2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Proba_2View.cpp
inline CProba2Doc* CProba2View::GetDocument() const
   { return reinterpret_cast<CProba2Doc*>(m_pDocument); }
#endif

