
// Lab2_PripremaView.cpp : implementation of the CLab2PripremaView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab2_Priprema.h"
#endif

#include "Lab2_PripremaDoc.h"
#include "Lab2_PripremaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab2PripremaView

IMPLEMENT_DYNCREATE(CLab2PripremaView, CView)

BEGIN_MESSAGE_MAP(CLab2PripremaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CLab2PripremaView construction/destruction

CLab2PripremaView::CLab2PripremaView() noexcept
{
	// TODO: add construction code here
	grid = false;
}

CLab2PripremaView::~CLab2PripremaView()
{
}

BOOL CLab2PripremaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}



// CLab2PripremaView drawing

void CLab2PripremaView::Translate(CDC* pDC, float dX, float dY, bool rightMultiply)
{
	XFORM xform = { 1,0,0,1,dX,dY };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab2PripremaView::Scale(CDC* pDC, float sX, float sY, bool rightMultiply)
{
	XFORM xform = { sX,0,0,sY,0,0 };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab2PripremaView::Rotate(CDC* pDC, float angle, bool rightMultiply)
{
	XFORM xform = { cos(angle),sin(angle),-sin(angle),cos(angle),0,0};
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}

void crtajKaktus(CDC* pDC)
{
	HENHMETAFILE mf=GetEnhMetaFile(CString("cactus_part.emf"));
	ENHMETAHEADER header;
	GetEnhMetaFileHeader(mf, sizeof(ENHMETAHEADER), &header);
	int width = header.rclBounds.right - header.rclBounds.left;
	int height = header.rclBounds.bottom - header.rclBounds.top;
	pDC->PlayMetaFile(mf, CRect(100, 100,100+width,100+height));
	DeleteEnhMetaFile(mf);
}

void CLab2PripremaView::drawCanvas(CDC* pDC)
{
	CPen* olovka = new CPen(PS_NULL, 1, RGB(0, 0, 0));
	CBrush* cetka = new CBrush(RGB(135, 206, 235));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	CBrush* staraCetka = pDC->SelectObject(cetka);
	pDC->Rectangle(0, 0, 500, 500);

	pDC->SelectObject(staraCetka);
	pDC->SelectObject(staraOlovka);

	olovka->DeleteObject();
	cetka->DeleteObject();
}
void CLab2PripremaView::drawGrid(CDC* pDC)
{
	CPen* olovka=new CPen(PS_SOLID,2,RGB(223, 241, 250));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	for (int i = 0; i <= 500; i += 25)
	{
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 500);
		pDC->MoveTo(0, i);
		pDC->LineTo(500, i);
	}

	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();
}

void CLab2PripremaView::DrawFigure(CDC* pDC)
{
	drawCanvas(pDC);
	crtajKaktus(pDC);
}

void CLab2PripremaView::OnDraw(CDC* pDC)
{
	CLab2PripremaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DrawFigure(pDC);
	if (grid)
		drawGrid(pDC);
}


// CLab2PripremaView printing

BOOL CLab2PripremaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab2PripremaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab2PripremaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab2PripremaView diagnostics

#ifdef _DEBUG
void CLab2PripremaView::AssertValid() const
{
	CView::AssertValid();
}

void CLab2PripremaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab2PripremaDoc* CLab2PripremaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab2PripremaDoc)));
	return (CLab2PripremaDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab2PripremaView message handlers


void CLab2PripremaView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 'G')
	{
		grid = !grid;
		Invalidate();
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
