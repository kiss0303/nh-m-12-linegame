#pragma once
class Tron
{
public:
	int x1, y1, d;
	int r, g, b;
	Tron();
	Tron(int mx1, int my1, int d, int mr, int mg, int mb);
	void vehinh(CClientDC* pdc);
	void thietlapgiatri(int mx1, int my1, int d, int giatri);
};

