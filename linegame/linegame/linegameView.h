
// linegameView.h : interface of the ClinegameView class
//

#pragma once
#include "Banco.h"

class ClinegameView : public CView
{
protected: // create from serialization only
	ClinegameView() noexcept;
	DECLARE_DYNCREATE(ClinegameView)

// Attributes
public:
	ClinegameDoc* GetDocument() const;

// Operations
public:
	Banco banco;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~ClinegameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int batdaugame();
	void PlayBackgroundMusic();
	void StopBackgroundMusic();
};

#ifndef _DEBUG  // debug version in linegameView.cpp
inline ClinegameDoc* ClinegameView::GetDocument() const
   { return reinterpret_cast<ClinegameDoc*>(m_pDocument); }
#endif

