#include "pch.h"
#include "Tron.h"

Tron::Tron()
{
	x1 = 0;
	y1 = 0;
	d = 0;
	r = 0;
	g = 0;
	b = 0;
}

Tron::Tron(int mx1, int my1, int md, int mr, int mg, int mb)
{
	x1 = mx1;
	y1 = my1;
	d = md;
	r = mr;
	g = mg;
	b = mb;
}

void Tron::vehinh(CClientDC* pdc)
{
	CBrush* newb = new CBrush(RGB(r, g, b));
	CBrush* oldb;
	oldb = pdc->SelectObject(newb);
	pdc->Ellipse(x1, y1, x1 + d, y1 + d);
	pdc->SelectObject(oldb);
	delete newb;
}

void Tron::thietlapgiatri(int mx1, int my1, int md, int giatri)
{
	x1 = mx1;
	y1 = my1;
	d = md;
	if (giatri == 0)//mau do
	{
		r = 255;
		g = 0;
		b = 0;
	}
	else if (giatri == 1)
		{
			g = 255;
			r = 0;
			b = 0;
		}
		else if (giatri == 2)
			{
				g = 0;
				r = 0;
				b = 255;
			}
			else if (giatri == 3)
				{
					g = 0;
					r = 255;
					b = 255;
				}
				else if (giatri == 4)
					{
						g = 255;
						r = 255;
						b = 0;
					}
}

