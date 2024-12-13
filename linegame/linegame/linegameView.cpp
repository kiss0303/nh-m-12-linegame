
// linegameView.cpp : implementation of the ClinegameView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "linegame.h"
#endif

#include "linegameDoc.h"
#include "linegameView.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClinegameView

IMPLEMENT_DYNCREATE(ClinegameView, CView)

BEGIN_MESSAGE_MAP(ClinegameView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// ClinegameView construction/destruction

ClinegameView::ClinegameView() noexcept
{
	// TODO: add construction code here
	banco = Banco();

}

ClinegameView::~ClinegameView()
{
}

BOOL ClinegameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ClinegameView drawing

void ClinegameView::OnDraw(CDC* /*pDC*/)
{
	ClinegameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	banco.vehinh(&pdc);
}

void ClinegameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ClinegameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ClinegameView diagnostics

#ifdef _DEBUG
void ClinegameView::AssertValid() const
{
	CView::AssertValid();
}

void ClinegameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ClinegameDoc* ClinegameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClinegameDoc)));
	return (ClinegameDoc*)m_pDocument;
}
#endif //_DEBUG


// ClinegameView message handlers


void ClinegameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 32)
	{
		banco.batdau();
		PlayBackgroundMusic();
		CClientDC pdc(this);
		banco.vehinh(&pdc);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void ClinegameView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	banco.bamchuot(&pdc, point);
	CView::OnLButtonUp(nFlags, point);
}

void ClinegameView::PlayBackgroundMusic()
{
	// Đường dẫn tới tệp nhạc WAV
	PlaySound(_T("D:\\linegame\\music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void ClinegameView::StopBackgroundMusic()
{
	PlaySound(NULL, 0, 0); // Dừng nhạc
}

