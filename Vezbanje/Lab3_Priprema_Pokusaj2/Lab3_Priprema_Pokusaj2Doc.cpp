
// Lab3_Priprema_Pokusaj2Doc.cpp : implementation of the CLab3PripremaPokusaj2Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab3_Priprema_Pokusaj2.h"
#endif

#include "Lab3_Priprema_Pokusaj2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLab3PripremaPokusaj2Doc

IMPLEMENT_DYNCREATE(CLab3PripremaPokusaj2Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab3PripremaPokusaj2Doc, CDocument)
END_MESSAGE_MAP()


// CLab3PripremaPokusaj2Doc construction/destruction

CLab3PripremaPokusaj2Doc::CLab3PripremaPokusaj2Doc() noexcept
{
	// TODO: add one-time construction code here

}

CLab3PripremaPokusaj2Doc::~CLab3PripremaPokusaj2Doc()
{
}

BOOL CLab3PripremaPokusaj2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CLab3PripremaPokusaj2Doc serialization

void CLab3PripremaPokusaj2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CLab3PripremaPokusaj2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CLab3PripremaPokusaj2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLab3PripremaPokusaj2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLab3PripremaPokusaj2Doc diagnostics

#ifdef _DEBUG
void CLab3PripremaPokusaj2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab3PripremaPokusaj2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLab3PripremaPokusaj2Doc commands
