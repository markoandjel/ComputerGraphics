
// Lab3_Priprema_Pokusaj2Doc.h : interface of the CLab3PripremaPokusaj2Doc class
//


#pragma once


class CLab3PripremaPokusaj2Doc : public CDocument
{
protected: // create from serialization only
	CLab3PripremaPokusaj2Doc() noexcept;
	DECLARE_DYNCREATE(CLab3PripremaPokusaj2Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CLab3PripremaPokusaj2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
