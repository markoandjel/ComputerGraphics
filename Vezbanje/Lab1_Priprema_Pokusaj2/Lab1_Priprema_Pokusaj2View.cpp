
// Lab1_Priprema_Pokusaj2View.cpp : implementation of the CLab1PripremaPokusaj2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab1_Priprema_Pokusaj2.h"
#endif

#include "Lab1_Priprema_Pokusaj2Doc.h"
#include "Lab1_Priprema_Pokusaj2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab1PripremaPokusaj2View

IMPLEMENT_DYNCREATE(CLab1PripremaPokusaj2View, CView)

BEGIN_MESSAGE_MAP(CLab1PripremaPokusaj2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CLab1PripremaPokusaj2View construction/destruction

CLab1PripremaPokusaj2View::CLab1PripremaPokusaj2View() noexcept
{
	// TODO: add construction code here
	toggleGrid = false;

}

CLab1PripremaPokusaj2View::~CLab1PripremaPokusaj2View()
{
}

BOOL CLab1PripremaPokusaj2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle)
{
	double alfa = 2 * 3.14159265359 / n;
	double ugao = 0;
	CPoint* tacke = new CPoint(n);

	for (int i = 0; i < n; i++)
	{
		tacke[i] = CPoint(cx + r * cos(ugao + rotAngle), cy + r * sin(ugao + rotAngle));
		ugao += alfa;
	}

	pDC->Polygon(tacke, n);
}
// CLab1PripremaPokusaj2View drawing

void CLab1PripremaPokusaj2View::OnDraw(CDC* pDC)
{
	CLab1PripremaPokusaj2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(500, 500);
	//pDC->SetWindowOrg(0, 0);
	pDC->SetViewportExt(500, 500);

	if (toggleGrid)
	{
		DWORD wBits[25] = { 0xffffffff,
		0x80000001,0x80000001,	0x80000001 ,0x80000001,
		0x80000001 ,0x80000001,	0x80000001 ,0x80000001,
		0x80000001,0x80000001,	0x80000001 ,0x80000001,
		0x80000001 ,0x80000001,	0x80000001 ,0x80000001,
		0x80000001,0x80000001,	0x80000001 ,0x80000001,
		0x80000001 ,0x80000001,0x80000001,
		0xffffffff
		};
		CBitmap brushBMP;
		brushBMP.CreateBitmap(25, 25, 1, 1, wBits);

		CBrush brush;
		brush.CreatePatternBrush(&brushBMP);
		CBrush* pOldBrush = pDC->SelectObject(&brush);
		pDC->Rectangle(0, 0, 500, 500);
		pDC->SelectObject(pOldBrush);
	}


	//pDC->SetBkColor(RGB(221, 221, 221));

	CPen* olovkaNull = new CPen(PS_NULL, 1, RGB(0, 0, 0));
	CBrush* cetkaNull = new CBrush(RGB(221, 221, 221));
	CPen* staraOlovkaNull = pDC->SelectObject(olovkaNull);
	CBrush* staraCetkaNull = pDC->SelectObject(cetkaNull);
	pDC->Rectangle(0, 0, 500, 500);




	CPen* olovka = new CPen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* olovkaTanka = new CPen(PS_SOLID, 3, RGB(255, 0, 0));

	CBrush* cetkaCrvena = new CBrush(RGB(255, 0, 0));
	CBrush* cetkaLjubicasta = new CBrush(RGB(153, 0, 204));
	CBrush* cetkaRoze = new CBrush(RGB(255, 153, 204));
	CBrush* cetkaZuta = new CBrush(RGB(255, 255, 0));
	CBrush* cetkaZelena = new CBrush(RGB(50, 205, 50));
	CBrush* cetkaNarandzasta = new CBrush(RGB(255, 153, 51));
	CBrush* cetkaPlava = new CBrush(HS_CROSS, RGB(102, 153, 255));

	CPoint tackeCrvenogTrougla[] = { CPoint(175,100),CPoint(250,25),CPoint(325,100) };
	CPoint tackeParalelograma[] = { CPoint(175,100),CPoint(325,100),CPoint(400,175),CPoint(250,175) };
	CPoint tackeRomba[] = { CPoint(175,100),CPoint(250,175),CPoint(175,250),CPoint(100,175) };

	CPoint tackeZutogTrougla[] = { CPoint(250,175),CPoint(250,325),CPoint(175,250) };
	CPoint tackeZelenogTrougla[] = { CPoint(250,175),CPoint(400,175),CPoint(250,325) };
	CPoint tackeNarandzastogTrougla[] = { CPoint(250,325),CPoint(400,175),CPoint(400,475) };
	CPoint tackeRozeTrougla[] = { CPoint(100,175),CPoint(250,325),CPoint(100,475) };

	CPen* staraOlovka = pDC->SelectObject(olovka);
	CBrush* staraCetkaCrvena = pDC->SelectObject(cetkaCrvena);



	pDC->Polygon(tackeCrvenogTrougla, 3);
	CBrush* staraPlavaCetka = pDC->SelectObject(cetkaPlava);
	pDC->Polygon(tackeParalelograma, 4);
	CBrush* staraLjubicastaCetka = pDC->SelectObject(cetkaLjubicasta);
	pDC->Polygon(tackeRomba, 4);

	CBrush* staraZutaCetka = pDC->SelectObject(cetkaZuta);
	pDC->Polygon(tackeZutogTrougla, 3);
	pDC->SelectObject(olovkaTanka);
	DrawRegularPolygon(pDC, 220, 250, 15, 6, 0.7);
	pDC->SelectObject(olovka);

	CBrush* staraZelenaCetka = pDC->SelectObject(cetkaZelena);
	pDC->Polygon(tackeZelenogTrougla, 3);
	pDC->SelectObject(olovkaTanka);
	DrawRegularPolygon(pDC, 300, 220, 25, 5, 0);
	pDC->SelectObject(olovka);

	CBrush* staraRozeCetka = pDC->SelectObject(cetkaRoze);
	pDC->Polygon(tackeRozeTrougla, 3);
	pDC->SelectObject(olovkaTanka);
	DrawRegularPolygon(pDC, 175, 320, 40, 8, 0);
	pDC->SelectObject(olovka);


	CBrush* staraNarandzastaCetka = pDC->SelectObject(cetkaNarandzasta);
	pDC->Polygon(tackeNarandzastogTrougla, 3);

	CPen* staraOlovkaTanka = pDC->SelectObject(olovkaTanka);

	DrawRegularPolygon(pDC, 325, 325, 40, 6, 0);


	pDC->SelectObject(staraOlovka);

	olovka->DeleteObject();
	cetkaCrvena->DeleteObject();

	// TODO: add draw code for native data here
}


// CLab1PripremaPokusaj2View printing

BOOL CLab1PripremaPokusaj2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab1PripremaPokusaj2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab1PripremaPokusaj2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab1PripremaPokusaj2View diagnostics

#ifdef _DEBUG
void CLab1PripremaPokusaj2View::AssertValid() const
{
	CView::AssertValid();
}

void CLab1PripremaPokusaj2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab1PripremaPokusaj2Doc* CLab1PripremaPokusaj2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab1PripremaPokusaj2Doc)));
	return (CLab1PripremaPokusaj2Doc*)m_pDocument;
}
#endif //_DEBUG


// CLab1PripremaPokusaj2View message handlers

void CLab1PripremaPokusaj2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	int pom = (char)nChar;
	if (nChar == (int)'l')
	{
		toggleGrid = !toggleGrid;
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
