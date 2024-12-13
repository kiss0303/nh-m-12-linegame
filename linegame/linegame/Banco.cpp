#include "pch.h"
#include "Banco.h"

Banco::Banco()
{
    dk = 0;
    diem = 0;
    thang = 0;
   
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < R; j++)
        {
            bc[i][j] = Hcn(XD + j * L, YD + i * L, XD + (j + 1) * L, YD + (i + 1) * L, -1);
            oc[i][j] = Tron();
        }
    }
    octiep = Tron();
    giatritiep = 0;
}

void Banco::vehinh(CClientDC* pdc)
{
    CString strdiem, strstart, strstop;
    strdiem.Format(_T("Point:%d"), diem);
    strstart.Format(_T("Space to start game"));
    strstop.Format(_T("Game over"));
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < R; j++)
        {
            bc[i][j].vehinh(pdc);
            oc[i][j].vehinh(pdc);
        }
    }

    octiep.vehinh(pdc);

    if (dk == 0 && thang == 0)
    {
        pdc->TextOutW(XD + L * 2, YD + D * L / 2, strstart);
    }
    if (thang == 1)
    {
        pdc->TextOutW(XD + L * 2, YD + D * L / 2, strstop);
    }

    pdc->TextOutW(XD, YD / 2, strdiem);
}

void Banco::batdau()
{
    if (dk == 1)
        return;

    dk = 1;
    diem = 0;
    thang = 0; // Reset trạng thái game
    ditiep();
}

void Banco::bamchuot(CClientDC* pdc, CPoint p)
{
    if (dk == 0)
        return;

    int mangi[5] = { -1, -1, -1, -1, -1 };
    int mangj[5] = { -1, -1, -1, -1, -1 };
    int dabam = 0;

    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (bc[i][j].kttonghinh(p) == 1 && bc[i][j].trangthai == 0)
            {
                oc[i][j].thietlapgiatri(XD + L * j + 5, YD + L * i + 5, L - 10, giatritiep);
                bc[i][j].giatri = giatritiep;
                bc[i][j].trangthai = 1;
                dabam = 1;
                mangi[0] = i;
                mangj[0] = j;
                break;
            }
        }
        if (dabam == 1)
            break;
    }

    int mi = 1;
    if (dabam == 1)
    {
        for (int i = 0; i < D; i++)
        {
            for (int j = 0; j < R; j++)
            {
                if (bc[i][j].giatri != -1 && bc[i][j].trangthai == 0)
                {
                    oc[i][j].thietlapgiatri(XD + L * j + 5, YD + L * i + 5, L - 10, bc[i][j].giatri);
                    bc[i][j].trangthai = 1;
                    mangi[mi] = i;
                    mangj[mi] = j;
                    mi++;
                }
            }
        }

        vehinh(pdc);
        Sleep(50);
        tinhdiem(mangi, mangj);
        if (ditiep() == 0)
        {
            thang = 1;
            dk = 0;
        }
    }

    vehinh(pdc);
}

int Banco::ditiep()
{
    int dem = 0;
    int mangi[R * D], mangj[R * D], n = 0;

    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (bc[i][j].giatri == -1)
            {
                mangi[n] = i;
                mangj[n] = j;
                ++n;
            }
        }
    }

    while (dem < 4 && dem < n)
    {
        int t = rand() % n;
        int i = mangi[t];
        int j = mangj[t];
        int val = rand() % 5;

        bc[i][j].giatri = val;
        oc[i][j].thietlapgiatri(XD + j * L + L / 2 - 5, YD + i * L + L / 2 - 5, 10, val);
        dem++;
    }

    int t = rand() % 5;
    octiep.thietlapgiatri(XD + L * R / 2, YD / 2 - L / 2, L, t);
    giatritiep = t;

    return dem;
}

int Banco::tinhdiem(int mangi[], int mangj[])
{
    for (int i = 0; i < 5; i++)
    {
        kiemtrathang(mangi[i], mangj[i]);
        kiemtrangang(mangi[i], mangj[i]);
        kiemtracheo1(mangi[i], mangj[i]);
        kiemtracheo2(mangi[i], mangj[i]);
    }

    return 0;
}

void Banco::kiemtrathang(int mi, int mj)
{
    if (mi < 0 || mj < 0 || mi >= D || mj >= R)
        return;

    int dem = 0;

    for (int i = mi - 1; i >= 0 && bc[i][mj].giatri == bc[mi][mj].giatri && bc[i][mj].trangthai == 1; i--)
        dem++;
    for (int i = mi + 1; i < D && bc[i][mj].giatri == bc[mi][mj].giatri && bc[i][mj].trangthai == 1; i++)
        dem++;

    if (dem >= 4)
    {
        diem += dem * 2;
        for (int i = mi - 1; i >= 0 && bc[i][mj].giatri == bc[mi][mj].giatri && bc[i][mj].trangthai == 1; i--)
            xoaO(i, mj);
        for (int i = mi + 1; i < D && bc[i][mj].giatri == bc[mi][mj].giatri && bc[i][mj].trangthai == 1;i++)
            xoaO(i, mj);
        xoaO(mi, mj);
    }
}

void Banco::kiemtrangang(int mi, int mj)
{
    if (mi < 0 || mj < 0 || mi >= D || mj >= R)
        return;
    int dem = 0;
    for (int j = mj - 1; j >= 0 && bc[mi][j].giatri == bc[mi][mj].giatri && bc[mi][j].trangthai == 1; j--)
        dem++;
    for (int j = mj + 1; j < R && bc[mi][j].giatri == bc[mi][mj].giatri && bc[mi][j].trangthai == 1; j++)
        dem++;
    if (dem >= 4)
    {
        diem += dem * 2;
        for (int j = mj - 1; j >= 0 && bc[mi][j].giatri == bc[mi][mj].giatri && bc[mi][j].trangthai == 1; j--)
            xoaO(mi, j);
        for (int j = mj + 1; j < R && bc[mi][j].giatri == bc[mi][mj].giatri && bc[mi][j].trangthai == 1; j++)
            xoaO(mi, j);
        xoaO(mi, mj);
    }
}

void Banco::kiemtracheo1(int mi, int mj)
{
    if (mi < 0 || mj < 0 || mi > D || mj > R)
        return;
    int dem = 0;
    for (int i = mi - 1, j = mj - 1; i >= 0 && j >= 0 && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i--, j--)
        dem++;
    for (int i = mi + 1, j = mj + 1; i < D && j < R && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i++, j++)
        dem++;

    if (dem >= 4)
    {
        diem += dem * 2;
        for (int i = mi - 1, j = mj - 1; i >= 0 && j >= 0 && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i--, j--)
            xoaO(i, j);
        for (int i = mi + 1, j = mj + 1; i < D && j < R && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i++, j++)
            xoaO(i, j);
        xoaO(mi, mj);
    }
}

void Banco::kiemtracheo2(int mi, int mj)
{
    if (mi < 0 || mj < 0 || mi > D || mj > R)
        return;
    int dem = 0;
    for (int i = mi - 1, j = mj + 1; i >= 0 && j < R && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i--, j++)
        dem++;
    for (int i = mi + 1, j = mj - 1; i < D && j >= 0 && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i++, j--)
        dem++;

    if (dem >= 4)
    {
        diem += dem * 2;
        for (int i = mi - 1, j = mj + 1; i >= 0 && j < R && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1; i--,j++)
            xoaO(i, j);
        for (int i = mi + 1, j = mj - 1; i < D && j >= 0 && bc[i][j].giatri == bc[mi][mj].giatri && bc[i][j].trangthai == 1;i++,j--)
            xoaO(i, j);
        xoaO(mi, mj);
    }
}

void Banco::xoaO(int i, int j)
{
    bc[i][j].giatri = -1;
    bc[i][j].trangthai = 0;
    oc[i][j].thietlapgiatri(0, 0, 0, 0);
}
