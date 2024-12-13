#include "pch.h"
#include "Hcn.h"

Hcn::Hcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	giatri = 0;
	trangthai = 0;
}

Hcn::Hcn(int mx1, int my1, int mx2, int my2, int mgiatri)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
	giatri = mgiatri;
	trangthai = 0;
}

void Hcn::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}

int Hcn::kttonghinh(CPoint p)
{
	int kq = 0;
	if (x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2)
		kq = 1;
	return kq;
}
