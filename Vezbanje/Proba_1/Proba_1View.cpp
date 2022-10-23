
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

void CProba1View::OnDraw(CDC* pDC)
{
	CProba1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	//Prvi probni primer

	#pragma region Proba

	/*CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(100, -100);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(-50, 50);
	pDC->Rectangle(-20, 20, 20, -20);*/

	#pragma endregion

	//Primer selektovanja objekta

	/*CPen* olovka = new CPen(PS_DASH, 1, RGB(0, 0, 255));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->MoveTo(10, 10);
	pDC->LineTo(300, 300);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();*/

	//Kreiranje prosirene olovke

	/*LOGBRUSH logBrush;
	logBrush.lbStyle = BS_SOLID;
	logBrush.lbColor = RGB(200, 36, 0);
	CPen* pPen = new CPen(PS_GEOMETRIC | PS_DASH | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 7, &logBrush);
	CPen* oldPen = pDC->SelectObject(pPen);
	pDC->MoveTo(10, 10);
	pDC->LineTo(300, 300);
	pDC->SelectObject(oldPen);
	delete pPen;*/

	#pragma region Mnogougao

	/*CBrush* cetka = new CBrush(HS_HORIZONTAL, RGB(0, 0, 255));
	pDC->SetBrushOrg(100, 100);
	CBrush* staraCetka = pDC->SelectObject(cetka);

	CPen* olovka = new CPen(PS_DASH, 3, RGB(0, 255, 0));
	CPen* staraOlovka = pDC->SelectObject(olovka);

	CPoint tacke[5];
	tacke[0] = CPoint(100, 100);
	tacke[1] = CPoint(100, 200);
	tacke[2] = CPoint(500, 400);
	tacke[3] = CPoint(350, 600);
	tacke[4] = CPoint(240, 300);
	pDC->Polygon(tacke, 3);

	pDC->SelectObject(staraOlovka);
	pDC->SelectObject(staraCetka);
	olovka->DeleteObject();
	cetka->DeleteObject();*/

	#pragma endregion

	#pragma region IzlomljenaLinija

	/*LOGBRUSH logBrush;
	logBrush.lbStyle = BS_SOLID;
	logBrush.lbColor = RGB(0, 0, 240);


	CPen* olovka = new CPen(PS_GEOMETRIC|PS_DASH|PS_ENDCAP_ROUND|PS_JOIN_ROUND,6,&logBrush);
	CPoint tacke[5];
	tacke[0] = CPoint(100, 100);
	tacke[1] = CPoint(100, 200);
	tacke[2] = CPoint(500, 400);
	tacke[3] = CPoint(350, 600);
	tacke[4] = CPoint(240, 300);
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->Polyline(tacke, 5);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();*/

	#pragma endregion

	#pragma region Pravougaonik
	/*
	CPen* olovka = new CPen(PS_DASH, 1, RGB(240, 0, 240));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->Rectangle(100, 100, 500, 400);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();
	*/

	#pragma endregion

	#pragma region Elipsa
	/*
	CPen* olovka = new CPen(PS_DASH, 1, RGB(240, 0, 60));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->Ellipse(100, 100, 500, 400);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();
	*/

	#pragma endregion

	#pragma region ZaobljenPravougaonik

	/*
	CPen* olovka = new CPen(PS_SOLID,5, RGB(60, 140, 180));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->RoundRect(100, 100, 340, 500, 50, 50);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();
	*/
	#pragma endregion

	#pragma region Luk
	
	/*CPen* olovka = new CPen(PS_SOLID, 5, RGB(0, 0, 255));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	pDC->SetArcDirection(AD_COUNTERCLOCKWISE);	
	pDC->Arc(20, 20, 226, 144, 202, 115, 105, 32);

	pDC->SetArcDirection(AD_CLOCKWISE);
	pDC->Arc(10, 10, 226, 150, 300, 400, 80, 20);

	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();*/

	#pragma endregion

	#pragma region Pita
	
	/*CPen* olovka = new CPen(PS_SOLID, 3, RGB(240, 0, 255));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	CRect rect = CRect(50,50,360,480);
	CPoint start = CPoint(280, 50);
	CPoint end = CPoint(360, 400);
	pDC->Pie(rect, start, end);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();*/

	#pragma endregion

	#pragma region Odsecak

	/*CPen* olovka = new CPen(PS_SOLID, 3, RGB(240, 0, 255));
	CPen* staraOlovka = pDC->SelectObject(olovka);
	CRect rect = CRect(50, 50, 360, 480);
	CPoint start = CPoint(280, 50);
	CPoint end = CPoint(360, 400);
	pDC->Chord(rect, start, end);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();*/

	#pragma endregion

	#pragma region Bezier-ova_Kriva

	CPoint Pt[] = { CPoint(20, 12), CPoint(88, 246),
		 CPoint(364, 192), CPoint(250, 48),
		 CPoint(175, 38), CPoint(388, 192), CPoint(145, 125) };

	CPen* olovka = new CPen(PS_SOLID, 3, RGB(240, 0, 255));
	CPen* staraOlovka = pDC->SelectObject(olovka);

	pDC->PolyBezier(Pt, 7);
	pDC->SelectObject(staraOlovka);
	olovka->DeleteObject();

	#pragma endregion	

	







	

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
