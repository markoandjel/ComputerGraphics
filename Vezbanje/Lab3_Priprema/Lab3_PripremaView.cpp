
// Lab3_PripremaView.cpp : implementation of the CLab3PripremaView class
//
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab3_Priprema.h"
#endif

#include "Lab3_PripremaDoc.h"
#include "Lab3_PripremaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab3PripremaView

IMPLEMENT_DYNCREATE(CLab3PripremaView, CView)

BEGIN_MESSAGE_MAP(CLab3PripremaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLab3PripremaView construction/destruction

CLab3PripremaView::CLab3PripremaView() noexcept
{
	// TODO: add construction code here
	Slike = new DImage[9]();
	CString pom;
	for (int i = 1; i < 10; i++)
	{
		CString s1 = CString("image (");
		pom.Format(L"%d", i);
		s1 += pom;
		s1 += CString(").dib");
		Slike[i-1].Load(CString(s1));
	}
}

CLab3PripremaView::~CLab3PripremaView()
{
}

BOOL CLab3PripremaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab3PripremaView drawing
void CLab3PripremaView::Translate(CDC* pDC, float dX, float dY, bool rightMultiply)
{
	XFORM xform = { 1,0,0,1,dX,dY };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab3PripremaView::Scale(CDC* pDC, float sX, float sY, bool rightMultiply)
{
	XFORM xform = { sX,0,0,sY,0,0 };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab3PripremaView::Rotate(CDC* pDC, float angle, bool rightMultiply)
{
	float pi = 3.141592;
	angle = angle * pi / 180;
	XFORM xform = { cos(angle),sin(angle),-sin(angle),cos(angle),0,0 };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}

void CLab3PripremaView::Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply)
{
	XFORM xform = { 0,0,0,0,0,0 };
	xform.eM11 = mx ? -1 : 1;
	xform.eM22 = my ? -1 : 1;
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}

void CLab3PripremaView::OnDraw(CDC* pDC)
{
	CLab3PripremaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//Slike[0].Draw(pDC, CRect(0, 0, 256, 256), CRect(0, 0, 256, 256));
	
}


// CLab3PripremaView printing

BOOL CLab3PripremaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab3PripremaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab3PripremaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab3PripremaView diagnostics

#ifdef _DEBUG
void CLab3PripremaView::AssertValid() const
{
	CView::AssertValid();
}

void CLab3PripremaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab3PripremaDoc* CLab3PripremaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab3PripremaDoc)));
	return (CLab3PripremaDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab3PripremaView message handlers
