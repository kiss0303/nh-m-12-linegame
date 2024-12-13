#pragma once
class Hcn
{

public:
	int x1, y1, x2, y2;
	int giatri;
	int trangthai;
	Hcn();
	Hcn(int mx1, int my1, int mx2, int my2, int mgiatr);
	void vehinh(CClientDC* pdc);
	int kttonghinh(CPoint p);
};

