#include <iostream>
#include <cmath>
#include <fstream>

double Tsup = 0.8;         //周期
double Sx = 0.3, Sy = 0.2; //歩幅
double x = 0, y = 0, Px = 0, Py = 0, t = 0, Tc = 0, dx = 0, dy = 0, xvar = 0, yvar = 0, pPx, pPy, proPx = 0, proPy = 0;
double dxvar = 0, dyvar = 0, C, S;
double prox = 0, proy = 0, prodx = 0, prody = 0;
double T = 0, n = 0, g = 9.8, Zc = 0.8;
double a = 10, b = 1;
double dt = 4.0 / 1000.0;
double num_step = 4;

double
sss();

int main()
{
    sss();
    return 0;
}

double sss()
{
    std::ofstream data("data.dat");
    double xi = 0, yi = 0, dxi = 0, dyi = 0;
    for (float i = 1; i < num_step + 1; i++)
    {
        Tc = sqrt(Zc / g);
        //std::cout << Tc;
        // std::cout << S;

        for (double step = 0; step < Tsup; step += dt, t += dt)
        {
            C = std::cosh(step / Tc);
            S = std::sinh(step / Tc);
            // std::cout << S;
            x = (xi - proPx) * C + Tc * dxi * S + proPx;
            y = (yi - proPy) * C + Tc * dyi * S + proPy;
            data << x << " " << y << std::endl;

            dx = (xi - proPx) / Tc * S + dxi * C;
            dy = (yi - proPy) / Tc * S + dyi * C;
            //data << dx << " " << dy << std::endl;
            //std::cout << dx << "," << dy << std::endl;
        }
        xi = x;
        yi = y;
        dxi = dx;
        dyi = dy;

        T = T + Tsup;
        //std::cout << T << std::endl;
        pPx = proPx;
        pPy = proPy;
        n = n + 1;

        Px = pPx + Sx;
        Py = pPy + std::pow(-1, n) * Sy;

        //std::cout << Px << "," << Py << std::endl;

        xvar = Sx / 2;
        yvar = std::pow(-1, n) * Sy / 2;
        //std::cout << xvar << "," << yvar << std::endl;

        dxvar = (C - 1) / (Tc * S) * xvar;
        dyvar = (C - 1) / (Tc * S) * yvar;
        //std::cout << dxvar << "," << dyvar << std::endl;

        //目標
        prox = Px + xvar;
        prodx = dxvar;
        proy = Py + yvar;
        prody = dyvar;
        //std::cout << prodx << "," << prody << std::endl;

        //評価式
        float D = a * (C - 1) * (C - 1) + b * (S / Tc) * (S / Tc);
        proPx = -a * (C - 1) / D * (prox - C * x - Tc * S * dx) - b * S / (Tc * D) * (dx - S / Tc * x - C * dx);
        proPy = -a * (C - 1) / D * (proy - C * y - Tc * S * dy) - b * S / (Tc * D) * (dy - S / Tc * y - C * dy);
    }
    //std::cout << proPx;
}