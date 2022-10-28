
// Lab1_PripremaView.cpp : implementation of the CLab1PripremaView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab1_Priprema.h"
#endif

#include "Lab1_PripremaDoc.h"
#include "Lab1_PripremaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab1PripremaView

IMPLEMENT_DYNCREATE(CLab1PripremaView, CView)

BEGIN_MESSAGE_MAP(CLab1PripremaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLab1PripremaView construction/destruction

CLab1PripremaView::CLab1PripremaView() noexcept
{
	// TODO: add construction code here

}

CLab1PripremaView::~CLab1PripremaView()
{
}

BOOL CLab1PripremaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab1PripremaView drawing

void CLab1PripremaView::OnDraw(CDC* pDC)
{
	CLab1PripremaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);
	//SetBkColor(RGB(255, 255, 0));
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(100, -100);
	pDC->SetWindowOrg(-50, 50);
	pDC->SetViewportExt(rect.right, rect.bottom);


	CPen* olovka = new CPen(PS_SOLID, 2, RGB(255, 0, 0));
	CBrush* cetka = new CBrush(HS_CROSS,RGB(0, 255, 0));
	CBrush* plavaCetka = new CBrush(HS_CROSS, RGB(0, 0, 255));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->SetBrushOrg(100, 100);
	CBrush* staraCetka = pDC->SelectObject(cetka);
	pDC->SetBkMode(TRANSPARENT);
	pDC->Rectangle(10, 10, 400, 400);
	CBrush* staraPlavaCetka = pDC->SelectObject(plavaCetka);
	pDC->Rectangle(500, 10, 600, 600);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();
	cetka->DeleteObject();

	// TODO: add draw code for native data here
}


// CLab1PripremaView printing

BOOL CLab1PripremaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab1PripremaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab1PripremaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab1PripremaView diagnostics

#ifdef _DEBUG
void CLab1PripremaView::AssertValid() const
{
	CView::AssertValid();
}

void CLab1PripremaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab1PripremaDoc* CLab1PripremaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab1PripremaDoc)));
	return (CLab1PripremaDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab1PripremaView message handlers
