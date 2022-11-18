// Lab3_Priprema_Pokusaj2View.cpp : implementation of the CLab3PripremaPokusaj2View class
//
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab3_Priprema_Pokusaj2.h"
#endif

#include "Lab3_Priprema_Pokusaj2Doc.h"
#include "Lab3_Priprema_Pokusaj2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab3PripremaPokusaj2View

IMPLEMENT_DYNCREATE(CLab3PripremaPokusaj2View, CView)

BEGIN_MESSAGE_MAP(CLab3PripremaPokusaj2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLab3PripremaPokusaj2View construction/destruction

CLab3PripremaPokusaj2View::CLab3PripremaPokusaj2View() noexcept
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

CLab3PripremaPokusaj2View::~CLab3PripremaPokusaj2View()
{
}

BOOL CLab3PripremaPokusaj2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLab3PripremaPokusaj2View drawing
void CLab3PripremaPokusaj2View::Translate(CDC* pDC, float dX, float dY, bool rightMultiply)
{
	XFORM xform = { 1,0,0,1,dX,dY };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab3PripremaPokusaj2View::Scale(CDC* pDC, float sX, float sY, bool rightMultiply)
{
	XFORM xform = { sX,0,0,sY,0,0 };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab3PripremaPokusaj2View::Rotate(CDC* pDC, float angle, bool rightMultiply)
{
	float pi = 3.141592;
	angle = angle * pi / 180;
	XFORM xform = { cos(angle),sin(angle),-sin(angle),cos(angle),0,0 };
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab3PripremaPokusaj2View::Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply)
{
	XFORM xform = { 0,0,0,0,0,0 };
	xform.eM11 = mx ? -1 : 1;
	xform.eM22 = my ? -1 : 1;
	DWORD mode = rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY;
	pDC->ModifyWorldTransform(&xform, mode);
}
void CLab3PripremaPokusaj2View::PribaviSliku(CDC* pDC, int i, bool blueFilter)
{
	CDC* memDC = new CDC();
	memDC->CreateCompatibleDC(pDC);

	CBitmap* slika = new CBitmap();
	CBitmap* maska = new CBitmap();

	slika->CreateBitmap(Slike[i].Width(), Slike[i].Height(), 1, 32, Slike[i].GetDIBBits());
	maska->CreateBitmap(256, 256, 1, 1, NULL);

	//pravljenje sive slike
	BITMAP sivaSlika;
	slika->GetBitmap(&sivaSlika);
	byte* bits = new byte[sivaSlika.bmWidthBytes * sivaSlika.bmHeight];
	slika->GetBitmapBits(sivaSlika.bmWidthBytes * sivaSlika.bmHeight, bits);
	for (int i = 0; i < sivaSlika.bmWidthBytes * sivaSlika.bmHeight; i += 4)
	{
		if (!blueFilter)
		{
			if (bits[i] == 0 && bits[i + 1] == 255 && bits[i + 2] == 0)continue; //zelena boja pozadine
			byte gr = 64 + (bits[i] + bits[i + 1] + bits[i + 2]) / 3;
			if (gr > 255) gr = 255;
			bits[i] = gr;
			bits[i + 1] = gr;
			bits[i + 2] = gr;
		}
		else
		{
			if (bits[i] == 0 && bits[i + 1] == 255 && bits[i + 2] == 0)continue;
			bits[i + 1] = 0;
			bits[i + 2] = 0;
		}
		
	}
	slika->SetBitmapBits(sivaSlika.bmWidthBytes * sivaSlika.bmHeight, bits);
	delete[] bits;

	CDC* srcDC = new CDC();
	srcDC->CreateCompatibleDC(pDC);
	CDC* dstDC = new CDC();
	dstDC->CreateCompatibleDC(pDC);

	CBitmap* OldSrcBmp = srcDC->SelectObject(slika);
	CBitmap* OldDstBmp = dstDC->SelectObject(maska);

	COLORREF clrTopLeft = srcDC->GetPixel(0, 0);
	COLORREF clrSaveBK = srcDC->SetBkColor(clrTopLeft);
	dstDC->BitBlt(0, 0, 256, 256, srcDC, 0, 0, SRCCOPY);

	COLORREF clrSaveDstText = srcDC->SetTextColor(RGB(255, 255, 255));
	srcDC->SetBkColor(RGB(0, 0, 0));
	srcDC->BitBlt(0, 0, 256, 256, dstDC, 0, 0, SRCAND);

	dstDC->SetTextColor(clrSaveDstText);
	srcDC->SetBkColor(clrSaveBK);
	dstDC->SelectObject(OldDstBmp);
	srcDC->SelectObject(OldSrcBmp);

	CBitmap* bmpOldT = memDC->SelectObject(maska);
	pDC->BitBlt(-128, -128, 256, 256, memDC, 0, 0, SRCAND);

	memDC->SelectObject(slika);
	pDC->BitBlt(-128, -128, 256, 256, memDC, 0, 0, SRCPAINT);

	memDC->SelectObject(bmpOldT);
	delete memDC;
	delete srcDC;
	delete dstDC;
}
void CLab3PripremaPokusaj2View::NacrtajSliku(CDC* pDC)
{
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	XFORM oldTransform;
	pDC->GetWorldTransform(&oldTransform);

	Translate(pDC, 128, 128, false);
	Mirror(pDC, true, false, false);
	Rotate(pDC, 205,false);
	PribaviSliku(pDC, 0, false); //prvi deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 115, 278, false);
	Mirror(pDC, true, false, false);
	Rotate(pDC, 107, false);
	PribaviSliku(pDC, 7, false); //drugi deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 116, 417, false);
	Mirror(pDC, true, false, false);
	Rotate(pDC, 19, false);
	PribaviSliku(pDC, 2, false); //treci deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 280, 124, false);
	Mirror(pDC, true, false, false);
	Rotate(pDC, -125, false);
	PribaviSliku(pDC, 5, false); //cetvrti deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 264, 270, false);
	Mirror(pDC, false, true, false);
	Rotate(pDC, -122, false);
	PribaviSliku(pDC, 8, false); //peti deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 266, 428, false);
	Mirror(pDC, false, true, false);
	Rotate(pDC, -66.5, false);
	PribaviSliku(pDC, 4, true); //sesti deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 430, 117, false);
	Mirror(pDC, true, false, false);
	Rotate(pDC, -76, false);
	PribaviSliku(pDC, 3, false); //sedmi deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 415, 270, false);
	Mirror(pDC, true, false, false);
	Rotate(pDC, 72, false);
	PribaviSliku(pDC, 1, false); //osmi deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	Translate(pDC, 423, 428, false);
	Mirror(pDC, false, true, false);
	Rotate(pDC, -18.5, false);
	PribaviSliku(pDC, 6, false); //deveti deo slagalice
	pDC->SetWorldTransform(&oldTransform);

	pDC->SetGraphicsMode(prevMode);
}
void CLab3PripremaPokusaj2View::OnDraw(CDC* pDC)
{
	CLab3PripremaPokusaj2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);
	CDC* memDC = new CDC();
	memDC->CreateCompatibleDC(pDC);
	
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	memDC->SelectObject(&bmp);
	memDC->Rectangle(0, 0, rect.Width(), rect.Height());
	
	NacrtajSliku(memDC);
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), memDC, 0, 0, SRCCOPY);
	
	memDC->DeleteDC();
}


// CLab3PripremaPokusaj2View printing

BOOL CLab3PripremaPokusaj2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab3PripremaPokusaj2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab3PripremaPokusaj2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab3PripremaPokusaj2View diagnostics

#ifdef _DEBUG
void CLab3PripremaPokusaj2View::AssertValid() const
{
	CView::AssertValid();
}

void CLab3PripremaPokusaj2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab3PripremaPokusaj2Doc* CLab3PripremaPokusaj2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab3PripremaPokusaj2Doc)));
	return (CLab3PripremaPokusaj2Doc*)m_pDocument;
}
#endif //_DEBUG


// CLab3PripremaPokusaj2View message handlers
