
// Lab1_Priprema_Pokusaj2View.h : interface of the CLab1PripremaPokusaj2View class
//

#pragma once


class CLab1PripremaPokusaj2View : public CView
{
protected: // create from serialization only
	CLab1PripremaPokusaj2View() noexcept;
	DECLARE_DYNCREATE(CLab1PripremaPokusaj2View)

		// Attributes
protected:
	bool toggleGrid;
public:
	CLab1PripremaPokusaj2Doc* GetDocument() const;
	

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
	virtual ~CLab1PripremaPokusaj2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDownLol(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in Lab1_Priprema_Pokusaj2View.cpp
inline CLab1PripremaPokusaj2Doc* CLab1PripremaPokusaj2View::GetDocument() const
   { return reinterpret_cast<CLab1PripremaPokusaj2Doc*>(m_pDocument); }
#endif

