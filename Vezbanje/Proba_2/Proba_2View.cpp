
// Proba_2View.cpp : implementation of the CProba2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Proba_2.h"
#endif

#include "Proba_2Doc.h"
#include "Proba_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProba2View

IMPLEMENT_DYNCREATE(CProba2View, CView)

BEGIN_MESSAGE_MAP(CProba2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CProba2View construction/destruction

CProba2View::CProba2View() noexcept
{
	// TODO: add construction code here

}

CProba2View::~CProba2View()
{
}

BOOL CProba2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProba2View drawing

void CProba2View::OnDraw(CDC* pDC)
{
	CProba2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

#pragma region Odsecanje_pomocu_regiona
		
	CString Text = CString("akldjsfklsajdflkjasdl;fkjas;ldfja;sldfj;lsadjflkasjdfhhsdgfhjagdf");
	CRgn tmpRgn, compoundRgn, rectRgn, eclipseRgn, polyRgn, *oldRgn;
	rectRgn.CreateRectRgn(100, 10, 300, 300);
	eclipseRgn.CreateEllipticRgn(10, 100, 400, 200);
	POINT Poly[] = { {425,225},{400,275},{325,275},{375,300},{350,375},
{425,325},{475,375},{450,300},{525,275},{450,275} };
	polyRgn.CreatePolygonRgn(Poly, 10, WINDING);
	tmpRgn.CreateRectRgn(0, 0, 0, 0);
	compoundRgn.CreateRectRgn(0, 0, 0, 0);

	tmpRgn.CombineRgn(&rectRgn, &eclipseRgn, RGN_XOR);
	compoundRgn.CombineRgn(&tmpRgn, &polyRgn, RGN_OR);

	CRect rect;
	pDC->GetClipBox(&rect);
	int rgnType = pDC->SelectClipRgn(&compoundRgn);
	pDC->SetTextAlign(TA_LEFT | TA_TOP);
	for (int i = 0; i < 400; i += 15)
	{
		pDC->TextOut(0, i, Text);
	}
	pDC->SelectClipRgn(&compoundRgn);
	compoundRgn.DeleteObject();
	tmpRgn.DeleteObject();
	eclipseRgn.DeleteObject();
	rectRgn.DeleteObject();
	polyRgn.DeleteObject();



#pragma endregion




	// TODO: add draw code for native data here
}


// CProba2View printing

BOOL CProba2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProba2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProba2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CProba2View diagnostics

#ifdef _DEBUG
void CProba2View::AssertValid() const
{
	CView::AssertValid();
}

void CProba2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProba2Doc* CProba2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProba2Doc)));
	return (CProba2Doc*)m_pDocument;
}
#endif //_DEBUG


// CProba2View message handlers
