#pragma once
#include "Tron.h"
#include "Hcn.h"
#define R 15
#define D 15
#define XD 100
#define YD 100
#define L 50
class Banco
{
public:
	int dk, diem, thang;
	Hcn bc[R][D];
	Tron oc[R][D];
	Tron octiep;
	int giatritiep;
	Banco();
	void vehinh(CClientDC* pdc);
	void batdau();
	void bamchuot(CClientDC* pdc, CPoint p);
	int  ditiep();
	int  tinhdiem(int mangi[], int mangj[]);
	void kiemtrathang(int mi, int mj);
	void kiemtrangang(int mi, int mj);
	void kiemtracheo1(int mi, int mj);
	void kiemtracheo2(int mi, int mj);
	void xoaO(int i, int j);
};

