
// Lab4_PripremaView.cpp : implementation of the CLab4PripremaView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab4_Priprema.h"
#endif

#include "Lab4_PripremaDoc.h"
#include "Lab4_PripremaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab4PripremaView

IMPLEMENT_DYNCREATE(CLab4PripremaView, CView)

BEGIN_MESSAGE_MAP(CLab4PripremaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CLab4PripremaView construction/destruction

CLab4PripremaView::CLab4PripremaView() noexcept
{
	// TODO: add construction code here

}

CLab4PripremaView::~CLab4PripremaView()
{
}

BOOL CLab4PripremaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab4PripremaView drawing

void CLab4PripremaView::OnDraw(CDC* pDC)
{
	CLab4PripremaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	m_glRenderer.DrawScene(pDC);
}


// CLab4PripremaView printing

BOOL CLab4PripremaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab4PripremaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab4PripremaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab4PripremaView diagnostics

#ifdef _DEBUG
void CLab4PripremaView::AssertValid() const
{
	CView::AssertValid();
}

void CLab4PripremaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab4PripremaDoc* CLab4PripremaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab4PripremaDoc)));
	return (CLab4PripremaDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab4PripremaView message handlers


int CLab4PripremaView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CDC* pDC = GetDC();
	m_glRenderer.CreateGLContext(pDC);
	ReleaseDC(pDC);

	return 0;
}


void CLab4PripremaView::OnDestroy()
{
	CView::OnDestroy();

	CDC* pDC = GetDC();
	m_glRenderer.DestroyScene(pDC);
	ReleaseDC(pDC);
}


BOOL CLab4PripremaView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}


void CLab4PripremaView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	CDC* pDC = GetDC();
	m_glRenderer.Reshape(pDC, cx, cy);
	ReleaseDC(pDC);
}

void CLab4PripremaView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	CDC* pDC = GetDC();
	m_glRenderer.PrepareScene(pDC);
	ReleaseDC(pDC);
}
