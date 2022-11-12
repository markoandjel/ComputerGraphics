
// Lab2ProbaView.cpp : implementation of the CLab2ProbaView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab2Proba.h"
#endif

#include "Lab2ProbaDoc.h"
#include "Lab2ProbaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab2ProbaView

IMPLEMENT_DYNCREATE(CLab2ProbaView, CView)

BEGIN_MESSAGE_MAP(CLab2ProbaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLab2ProbaView construction/destruction

CLab2ProbaView::CLab2ProbaView() noexcept
{
	// TODO: add construction code here

}

CLab2ProbaView::~CLab2ProbaView()
{
}

BOOL CLab2ProbaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab2ProbaView drawing

void CLab2ProbaView::OnDraw(CDC* pDC)
{
	CLab2ProbaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	#pragma region OdsecanjePomocuRegiona
	 /*

	CString Text= CString("qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm");
	CRgn tmpRgn, compundRgn, rectRgn, eclipseRgn, polyRgn, * oldRgn;
	rectRgn.CreateRectRgn(100, 10, 300, 300);
	eclipseRgn.CreateEllipticRgn(10, 100, 400, 200);
	CPoint tacke[] = { {425,225},{400,275},{325,275},{375,300},{350,375},
		{425,325},{475,375},{450,300},{525,275},{450,275} };
	polyRgn.CreatePolygonRgn(tacke, 10, WINDING);
	tmpRgn.CreateRectRgn(0, 0, 0, 0);
	compundRgn.CreateRectRgn(0, 0, 0, 0);
	tmpRgn.CombineRgn(&rectRgn, &eclipseRgn, RGN_XOR);
	compundRgn.CombineRgn(&tmpRgn, &polyRgn, RGN_OR);

	CRect rect;
	pDC->GetClipBox(&rect);
	int rgnType = pDC->SelectClipRgn(&compundRgn);
	pDC->SetTextAlign(TA_LEFT | TA_TOP);
	for (int i = 0; i < 400; i += 15)
		pDC->TextOut(0, i, Text);
	//pDC->SelectClipRgn(&rectRgn);
	*/
	#pragma endregion	

	#pragma region IspunaProizviljneOblasti 
	/*
	CBrush rbrush(RGB(255, 0, 0));
	CBrush* pOldBrush = pDC->SelectObject(&rbrush);
	CPen cpen(PS_SOLID, 3, RGB(0, 0, 255));
	CPen* oldPen = pDC->SelectObject(&cpen);
	int count =2;
	DWORD num[] = { 3,3 };
	POINT pts[] = { {100,200},{200,100},{300,200},{100,100},{200,200},{300,100} };

	//pDC->Polyline(&pts[0], 3);
	//pDC->Polyline(&pts[3], 3);

	pDC->PolyPolyline(pts, num, count);


	pDC->FloodFill(200, 150, RGB(0, 0, 255));
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(oldPen);
	*/
	#pragma endregion

	#pragma region Metafajlovi
	/*
	CString WMFname = CString("metafile.wmf");
	double pi = 3.1415926535897932384626433832795;
	CMetaFileDC MetaDC;
	LPCTSTR ime =LPCTSTR("Proba.wmf");
	MetaDC.Create(ime);
	HMETAFILE MF, NewMF;
	int x = 300, y = 200;
	MetaDC.MoveTo(x, y);
	double step = 0;
	for (double angle = 0; angle <= 10 * 2 * pi; angle += step) {
		double r = 180 * angle / (10 * 2 * pi);
		step = 3 / (r + 1);
		x = (int)(300.0 + r * cos(angle + step) + 0.5);
		y = (int)(200.0 - r * sin(angle + step) + 0.5);
		MetaDC.LineTo(x, y);
	}
	MF = MetaDC.Close();
	NewMF =
		CopyMetaFile(MF, WMFname.GetBuffer(WMFname.GetLength()));
	DeleteMetaFile(MF);
	DeleteMetaFile(NewMF);
	MetaDC.DeleteDC();
	HMETAFILE Meta =
		GetMetaFile(WMFname.GetBuffer(WMFname.GetLength()));
	PlayMetaFile(pDC->m_hDC, Meta);
	DeleteMetaFile(Meta);
	*/
#pragma endregion

	#pragma region Putanje
	/*
	pDC->BeginPath();
	pDC->Rectangle(20, 20, 50, 50);
	pDC->Ellipse(CRect(60, 60, 480, 180));
	pDC->EndPath();

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	CPen* oldPen = pDC->SelectObject(&pen);
	CBrush brush;
	brush.CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 255));
	CBrush* oldBrush = pDC->SelectObject(&brush);
	//pDC->StrokePath();
	//pDC->FillPath();

	pDC->StrokeAndFillPath();
	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);
	*/

	
	#pragma endregion 

	#pragma region Transformacije
	/*
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	DWORD dw = GetLastError();
	XFORM Xform, XformOld;
	double pi = 3.141592;
	Xform.eM11 = cos(pi/7.0);
	Xform.eM12 = sin(pi / 7.0);
	Xform.eM21 = -sin(pi / 7.0);
	Xform.eM22 = cos(pi/7.0);
	Xform.eDx = (float)0.0;
	Xform.eDy = (float)0.0;
	BOOL b = pDC->GetWorldTransform(&XformOld);
	b = pDC->SetWorldTransform(&Xform);
	Xform.eM11 = 1.0;
	Xform.eM12 = 0.0;
	Xform.eM21 = 0.0;
	Xform.eM22 = 1.0;
	Xform.eDx = -75.0;
	Xform.eDy = -75.0;
	b = pDC->ModifyWorldTransform(&Xform, MWT_RIGHTMULTIPLY);
	pDC->Rectangle(50, 50, 100, 100);
	
	dw = GetLastError();
	b = pDC->SetWorldTransform(&XformOld);
	pDC->SetGraphicsMode(prevMode);
	*/
	
	#pragma endregion

	#pragma region TextOutPrimer

	/*CFont font;
	font.CreateFont(20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CString("Arila"));
	CFont* oldFont = pDC->SelectObject(&font);
	pDC->TextOutW(50, 50, CString("Probni tekst"));
	*/
	#pragma endregion

	#pragma region PostavljanjeTransformacije
	CRect rcClient;
	GetClientRect(rcClient);
	COLORREF clrOld = pDC->SetTextColor(RGB(0,0,0));
	int nOldMode = pDC->SetBkMode(TRANSPARENT);
	CString szMsg = CString(" ...Help! I'm Spinning and I can't get up!");
	CFont fntRotate;
	for (int nDegrees = 0; nDegrees < 3600; nDegrees += 200)
	{
		LOGFONT m_logFont;
		m_logFont.lfEscapement = nDegrees;
		fntRotate.CreateFontIndirect(&m_logFont);
		CFont* pOldFont = pDC->SelectObject(&fntRotate);
		pDC->TextOut(rcClient.Width() / 2,
			rcClient.Height() / 2, szMsg);
		pDC->SelectObject(pOldFont);
		fntRotate.DeleteObject();
	}
	pDC->SetTextColor(clrOld);
	pDC->SetBkMode(nOldMode);

	#pragma endregion
}


// CLab2ProbaView printing

BOOL CLab2ProbaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab2ProbaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab2ProbaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab2ProbaView diagnostics

#ifdef _DEBUG
void CLab2ProbaView::AssertValid() const
{
	CView::AssertValid();
}

void CLab2ProbaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab2ProbaDoc* CLab2ProbaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab2ProbaDoc)));
	return (CLab2ProbaDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab2ProbaView message handlers
