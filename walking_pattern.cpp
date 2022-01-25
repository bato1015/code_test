#include <iostream>
#include <cmath>

float Tsup = 0.33;
float Sx = 0.3, Sy = 0.2, x = 0, y = 0, Px = 0, Py = 0, t = 0, Tc = 0, dx = 0, dy = 0, xvar = 0, yvar = 0, pPx, pPy, proPx = 0, proPy = 0;
float dxvar = 0, dyvar = 0, C, S;
float prox = 0, proy = 0, prodx = 0, prody = 0;
float T = 0, n = 0, g = 9.8, Zc = 0.2;
float a = 10, b = 1;

float sss();

int main()
{
    sss();
    return 0;
}

float sss()
{
    for (float i = 0; i < 5; i++)
    {
        Tc = sqrt(Zc / g);
        //std::cout << Tc;
        C = std::cosh(Tsup / Tc);
        S = std::sinh(Tsup / Tc);
        // std::cout << S;

        x = (x - proPx) * C + Tc * dx * S + proPx;
        y = (y - proPy) * C + Tc * dy * S + proPy;
        std::cout << x << "," << y << std::endl;

        dx = (x - proPx) / Tc * S + dx * C;
        dy = (y - proPy) / Tc * S + dy * C;
        //std::cout << dx << "," << dy << std::endl;

        T = T + Tsup;
        //std::cout << T << std::endl;
        pPx = Px;
        pPy = Py;
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
    }
    //std::cout << proPx;
}