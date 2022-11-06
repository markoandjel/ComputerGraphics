
// Lab1_CirkoView.cpp : implementation of the CLab1CirkoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab1_Cirko.h"
#endif

#include "Lab1_CirkoDoc.h"
#include "Lab1_CirkoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab1CirkoView

IMPLEMENT_DYNCREATE(CLab1CirkoView, CView)

BEGIN_MESSAGE_MAP(CLab1CirkoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CLab1CirkoView construction/destruction

CLab1CirkoView::CLab1CirkoView() noexcept
{
	// TODO: add construction code here
	grid = false;
}

CLab1CirkoView::~CLab1CirkoView()
{
}

BOOL CLab1CirkoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab1CirkoView drawing
void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle)
{
	CPen* olovka = new CPen(PS_SOLID,2, RGB(255, 255,0));
	pDC->SelectObject(olovka);
	float pi = 3.1415926535897932384626433832795;

	float alfa = 2 * pi / n;
	CPoint* tacke=new CPoint[n];
	float rotAngleRad = pi * rotAngle / 180;
	float ugao = 0;
	for (int i = 0; i < n; i++)
	{
		tacke[i] = CPoint(cx + r * cos(ugao+rotAngleRad), cy + r * sin(ugao+rotAngleRad));
		ugao += alfa;
	}
	pDC->Polygon(tacke, n);
	olovka->DeleteObject();
}

CPoint CentarUpisaneKruznice(CPoint* tacke)
{
	CPoint centar;
	float a = sqrt(pow(tacke[0].x - tacke[1].x, 2) + pow(tacke[0].y - tacke[1].y, 2));
	float b = sqrt(pow(tacke[1].x - tacke[2].x, 2) + pow(tacke[1].y - tacke[2].y, 2));
	float c = sqrt(pow(tacke[2].x - tacke[0].x, 2) + pow(tacke[2].y - tacke[0].y, 2));
	float s = a + b + c;

	return centar = CPoint((a * tacke[2].x + b * tacke[0].x + c * tacke[1].x) / s,
		(a * tacke[2].y + b * tacke[0].y + c * tacke[1].y) / s);
}

void CLab1CirkoView::OnDraw(CDC* pDC)
{
	CLab1CirkoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen* olovka = new CPen(PS_SOLID, 5, RGB(255, 255,0));

	CBrush* zutaCetka = new CBrush(RGB(255, 255, 0));
	CBrush* plavaCetka = new CBrush(HS_DIAGCROSS, RGB(150, 150, 255));
	CBrush* zelenaCetka = new CBrush(RGB(50, 205, 50));
	CBrush* crvenaCetka = new CBrush(RGB(255, 0, 0));
	CBrush* narandzastaCetka = new CBrush(RGB(255,153,51));
	CBrush* rozeCetka = new CBrush(RGB(255, 153, 204));
	CBrush* ljubicastaCetka = new CBrush(RGB(153, 0, 204));

	CBrush* cetkaPozadine = new CBrush(RGB(221, 221, 221));
	CPen* olovkaPozadine = new CPen(PS_NULL, 1, RGB(0, 0, 0));

	CPen* staraOlovka = pDC->SelectObject(olovkaPozadine);
	CBrush* staraCetka = pDC->SelectObject(cetkaPozadine);
	pDC->Rectangle(0, 0, 500, 500);

	
	pDC->SelectObject(olovka);

	pDC->SelectObject(plavaCetka);
	CPoint tackeSrafiranogTougla[] = { CPoint(25,137),CPoint(175,137),CPoint(175,287) };
	pDC->Polygon(tackeSrafiranogTougla, 3);

	pDC->SelectObject(zelenaCetka);
	CPoint tackeZelenogTougla[] = { CPoint(175,137),CPoint(175,212),CPoint(250,212)};
	pDC->Polygon(tackeZelenogTougla, 3);

	pDC->SelectObject(crvenaCetka);
	CPoint tackeCrvenogTougla[] = { CPoint(250,212),CPoint(325,137),CPoint(325,287) };
	pDC->Polygon(tackeCrvenogTougla, 3);

	pDC->SelectObject(zutaCetka);
	CPoint tackeZutogTougla[] = { CPoint(325,137),CPoint(475,137),CPoint(325,287) };
	pDC->Polygon(tackeZutogTougla, 3);

	pDC->SelectObject(narandzastaCetka);
	CPoint tackeNarandzastogKvadrata[] = { CPoint(175,212),CPoint(250,212),CPoint(250,287),CPoint(175,287) };
	pDC->Polygon(tackeNarandzastogKvadrata, 4);

	pDC->SelectObject(rozeCetka);
	CPoint tackeRozePalalelograma[] = { CPoint(250,212),CPoint(325,287),CPoint(325,362),CPoint(250,287) };
	pDC->Polygon(tackeRozePalalelograma, 4);

	pDC->SelectObject(ljubicastaCetka);
	CPoint tackeLjubicastogTougla[] = { CPoint(175,287),CPoint(250,287),CPoint(175,362)};
	pDC->Polygon(tackeLjubicastogTougla, 3);


	pDC->SelectObject(plavaCetka);
	DrawRegularPolygon(pDC, CentarUpisaneKruznice(tackeSrafiranogTougla).x,
		CentarUpisaneKruznice(tackeSrafiranogTougla).y, 20, 6, 0);

	pDC->SelectObject(zelenaCetka);
	DrawRegularPolygon(pDC, CentarUpisaneKruznice(tackeZelenogTougla).x,
		CentarUpisaneKruznice(tackeZelenogTougla).y, 14, 7, -15);
	
	pDC->SelectObject(crvenaCetka);
	DrawRegularPolygon(pDC, CentarUpisaneKruznice(tackeCrvenogTougla).x,
		CentarUpisaneKruznice(tackeCrvenogTougla).y, 15, 8, 0);

	pDC->SelectObject(zelenaCetka);
	DrawRegularPolygon(pDC, CentarUpisaneKruznice(tackeZelenogTougla).x,
		CentarUpisaneKruznice(tackeZelenogTougla).y, 14, 7, 0);

	pDC->SelectObject(ljubicastaCetka);
	DrawRegularPolygon(pDC, CentarUpisaneKruznice(tackeLjubicastogTougla).x,
		CentarUpisaneKruznice(tackeLjubicastogTougla).y, 12, 5, 0);

	if (grid)
	{
		CPen* olovkaGrida = new CPen(PS_SOLID, 2, RGB(238, 238, 238));
		pDC->SelectObject(olovkaGrida);
		for (int i = 0; i <= 500; i += 25)
		{
			pDC->MoveTo(i, 0);
			pDC->LineTo(i, 500);
		}
		for (int j = 0; j <= 500; j += 25)
		{
			pDC->MoveTo(0, j);
			pDC->LineTo(500, j);
		}
	}

	




	pDC->SelectObject(staraOlovka);
	pDC->SelectObject(staraCetka);

	plavaCetka->DeleteObject();
	zutaCetka->DeleteObject();
	zelenaCetka->DeleteObject();
	ljubicastaCetka->DeleteObject();
	crvenaCetka->DeleteObject();
	narandzastaCetka->DeleteObject();
	rozeCetka->DeleteObject();
	olovka->DeleteObject();
	olovkaPozadine->DeleteObject();
	cetkaPozadine->DeleteObject();
	// TODO: add draw code for native data here
}


// CLab1CirkoView printing

BOOL CLab1CirkoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab1CirkoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab1CirkoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab1CirkoView diagnostics

#ifdef _DEBUG
void CLab1CirkoView::AssertValid() const
{
	CView::AssertValid();
}

void CLab1CirkoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab1CirkoDoc* CLab1CirkoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab1CirkoDoc)));
	return (CLab1CirkoDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab1CirkoView message handlers


void CLab1CirkoView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 'G')
	{
		grid = !grid;
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
