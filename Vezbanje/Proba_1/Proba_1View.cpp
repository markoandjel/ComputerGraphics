
// Proba_1View.cpp : implementation of the CProba1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Proba_1.h"
#endif

#include "Proba_1Doc.h"
#include "Proba_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProba1View

IMPLEMENT_DYNCREATE(CProba1View, CView)

BEGIN_MESSAGE_MAP(CProba1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CProba1View construction/destruction

CProba1View::CProba1View() noexcept
{
	// TODO: add construction code here

}

CProba1View::~CProba1View()
{
}

BOOL CProba1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProba1View drawing

void CProba1View::OnDraw(CDC* /*pDC*/)
{
	CProba1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CProba1View printing

BOOL CProba1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProba1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProba1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CProba1View diagnostics

#ifdef _DEBUG
void CProba1View::AssertValid() const
{
	CView::AssertValid();
}

void CProba1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProba1Doc* CProba1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProba1Doc)));
	return (CProba1Doc*)m_pDocument;
}
#endif //_DEBUG


// CProba1View message handlers
