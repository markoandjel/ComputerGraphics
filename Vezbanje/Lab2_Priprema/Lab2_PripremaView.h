
// Lab2_PripremaView.h : interface of the CLab2PripremaView class
//

#pragma once


class CLab2PripremaView : public CView
{
protected: // create from serialization only
	CLab2PripremaView() noexcept;
	DECLARE_DYNCREATE(CLab2PripremaView)

// Attributes
public:
	bool grid;
	int alfa;
	int beta;
public:
	CLab2PripremaDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DrawFigure(CDC* pDC);
	virtual void drawGrid(CDC* pDC);
	virtual void Translate(CDC* pDC, float dx, float dY, bool rightMultiply);
	virtual void Scale(CDC* pDC, float sX, float sY, bool rightMultiply);
	virtual void Rotate(CDC* pDC, float angle, bool rightMultiply);
	virtual void drawCanvas(CDC* pDC);
	virtual void Napisitekst(CDC* pDC, CString text);
	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLab2PripremaView();
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

#ifndef _DEBUG  // debug version in Lab2_PripremaView.cpp
inline CLab2PripremaDoc* CLab2PripremaView::GetDocument() const
   { return reinterpret_cast<CLab2PripremaDoc*>(m_pDocument); }
#endif

