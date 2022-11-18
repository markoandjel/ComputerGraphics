
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
	alfa = 0;
	beta = 0;
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
	float pi = 3.141592;
	angle = angle * pi / 180;
	XFORM xform = { cos(angle),sin(angle),-sin(angle),cos(angle),0,0};
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}

void crtajSaksiju(CDC* pDC)
{
	CBrush* cetka = new CBrush(RGB(222, 148, 0));
	CBrush* staraCetka = pDC->SelectObject(cetka);

	POINT tackeTrapezoida[4] = { {210,498},{200,450 },{300,450},{290,498} };
	POINT tackePravougaonika[4] = { {190,450},{190,430},{310,430},{310,450} };
	pDC->Polygon(tackePravougaonika, 4);
	pDC->Polygon(tackeTrapezoida, 4);
	//pDC->Polygon(tacke, 4);
	pDC->SelectObject(staraCetka);
	cetka->DeleteObject();
}


void crtajKaktus(CDC* pDC,int x,int y)
{
	HENHMETAFILE mf=GetEnhMetaFile(CString("cactus_part.emf"));
	ENHMETAHEADER header;
	GetEnhMetaFileHeader(mf, sizeof(ENHMETAHEADER), &header);
	int width = header.rclBounds.right - header.rclBounds.left;
	int height = header.rclBounds.bottom - header.rclBounds.top;
	pDC->PlayMetaFile(mf, CRect(-height/x,-width/y,height/x,width/y));
	DeleteEnhMetaFile(mf);
}

void crtajSvetliKaktus(CDC* pDC,int x, int y)
{
	HENHMETAFILE mf = GetEnhMetaFile(CString("cactus_part_light.emf"));
	ENHMETAHEADER header;
	GetEnhMetaFileHeader(mf, sizeof(ENHMETAHEADER), &header);
	int width = header.rclBounds.right - header.rclBounds.left;
	int height = header.rclBounds.bottom - header.rclBounds.top;
	pDC->PlayMetaFile(mf, CRect(- height / x, - width / y,  height / x,width / y));
	DeleteEnhMetaFile(mf);
}

void crtajKrug(CDC* pDC)
{
	CBrush* cetka = new CBrush(RGB(0, 204,0));
	CBrush* staraCetka = pDC->SelectObject(cetka);
	int radius = 12;
	pDC->Ellipse(-radius,-radius,radius,radius);
	pDC->SelectObject(staraCetka);
	cetka->DeleteObject();
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

void CLab2PripremaView::Napisitekst(CDC* pDC, CString text)
{
	CFont font, * oldFont;
	font.CreateFontW(1.1 * 25, 15, -1800, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, CString("Arial"));

	oldFont = pDC->SelectObject(&font);
	int oldMode = pDC->SetBkMode(TRANSPARENT);
	int oldColor = pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOutW((int)(10 + 25 * 19), (int)(10 + 25*19), text);
	pDC->SetTextColor(RGB(255, 255, 0));
	pDC->TextOutW((int)(10 + 25 * 19 - 2), (int)(10 + 25*19 - 2), text);

	pDC->SetTextColor(oldColor);
	pDC->SetBkMode(oldMode);
	pDC->SelectObject(oldFont);
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
	float pi = 3.141592;
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	DWORD dw = GetLastError();
	drawCanvas(pDC);

	XFORM saveForm,xformOld,globalForm,desnaGrana;
	pDC->GetWorldTransform(&xformOld);
	Translate(pDC, 250, 500,false);
	Scale(pDC, 1, -1,false);
	pDC->GetWorldTransform(&globalForm);
	Translate(pDC, 0, 75, false);
	crtajKrug(pDC);

	Rotate(pDC, alfa, false);
	Translate(pDC, 0, 45, false);
	crtajSvetliKaktus(pDC,6,5);

	Translate(pDC, 0, 45, false);
	crtajKrug(pDC);

	pDC->GetWorldTransform(&saveForm);

	Translate(pDC, 0, 40, false);
	crtajKaktus(pDC, 18, 6);

	pDC->SetWorldTransform(&saveForm);
	pDC->GetWorldTransform(&desnaGrana);

	Translate(pDC, -30, 30, false);
	Rotate(pDC, 45, false);
	crtajKaktus(pDC, 18, 6);

	pDC->SetWorldTransform(&saveForm);

	Translate(pDC, 30, 30, false);
	Rotate(pDC, -45, false);
	crtajKaktus(pDC, 18, 6);
	pDC->SetWorldTransform(&saveForm);

	Translate(pDC,-60,60, false);
	crtajKrug(pDC);
	pDC->GetWorldTransform(&saveForm);

	Translate(pDC,0,40,false);
	crtajKaktus(pDC, 12, 6);
	pDC->SetWorldTransform(&saveForm);

	Translate(pDC, -40, 0, false);
	Rotate(pDC, 90, false);
	crtajKaktus(pDC, 12, 6);
	pDC->SetWorldTransform(&saveForm);

	Translate(pDC,0,82,false);
	crtajKrug(pDC);
	Translate(pDC, 0, 40, false);
	crtajKaktus(pDC, 7, 6);

	pDC->SetWorldTransform(&desnaGrana);
	Translate(pDC, 60, 60, false);
	crtajKrug(pDC);
	pDC->GetWorldTransform(&desnaGrana);
	
	Rotate(pDC, beta, false);
	Translate(pDC, 0, 40, false);
	crtajSvetliKaktus(pDC, 10, 6);

	pDC->SetWorldTransform(&desnaGrana);
	Translate(pDC, 40, 0, false);
	Rotate(pDC, 90, false);
	crtajKaktus(pDC, 12, 6);

	pDC->SetWorldTransform(&desnaGrana);
	Translate(pDC, 82, 0, false);
	crtajKrug(pDC);

	pDC->GetWorldTransform(&desnaGrana);
	Translate(pDC, 30, 30, false);
	Rotate(pDC, -45, false);
	crtajKaktus(pDC, 12, 6);

	pDC->SetWorldTransform(&desnaGrana);

	Translate(pDC, 30, -30, false);
	Rotate(pDC, 45, false);
	crtajKaktus(pDC, 12, 6);

	pDC->SetWorldTransform(&xformOld);
	crtajSaksiju(pDC);
	

	/*
	* //prvi nivo
	pDC->GetWorldTransform(&xformOld);
	pDC->SetWorldTransform(&xform);
	Rotate(pDC, alfa, true);
	Translate(pDC, 250, 380, true);
	Scale(pDC, 0.3, 0.37,false);
	crtajSvetliKaktus(pDC);
	pDC->SetWorldTransform(&xformOld);

	crtajKrug(pDC, CPoint(250, 425));
	

	//drugi nivo kaktus u sredini
	pDC->GetWorldTransform(&xformOld);
	pDC->SetWorldTransform(&xform);
	Translate(pDC, 250, 290, false);
	Scale(pDC, 0.11, 0.4, false);
	crtajKaktus(pDC);
	pDC->SetWorldTransform(&xformOld);

	//drugi nivo kaktus u sredini desni
	pDC->GetWorldTransform(&xformOld);
	pDC->SetWorldTransform(&xform);
	Rotate(pDC, 45, false);
	Scale(pDC, 0.11, 0.4, false);
	Translate(pDC, 285, 300, true);
	crtajKaktus(pDC);
	pDC->SetWorldTransform(&xformOld);

	//drugi nivo kaktus u sredini levi
	pDC->GetWorldTransform(&xformOld);
	pDC->SetWorldTransform(&xform);
	Rotate(pDC, -45, false);
	Scale(pDC, 0.11, 0.4, false);
	Translate(pDC, 215, 300, true);
	crtajKaktus(pDC);
	pDC->SetWorldTransform(&xformOld);

	crtajKrug(pDC, CPoint(250, 335));
	*/

	

	/*->GetWorldTransform(&xformOld);
	pDC->SetWorldTransform(&xform);
	Rotate(pDC, -45, false);
	Scale(pDC, 0.11, 0.4, false);
	Translate(pDC, 215, 300, true);
	crtajKaktus(pDC);
	pDC->SetWorldTransform(&xformOld);*/

	pDC->SetGraphicsMode(prevMode);
	
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
	Napisitekst(pDC, CString("Marko Andjelkovic 17541"));
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
	int korak = 3;
	if (nChar == 'G')
		grid = !grid;
	else if (nChar == 'A')
		alfa += korak;
	else if (nChar == 'D')
		alfa -= korak;
	else if (nChar == 'Q')
		beta += korak;
	else if (nChar == 'E')
		beta -= korak;
	
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
