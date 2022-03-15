//#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    float rk4(float xin, float xold, float tau, float dt);
    FILE *fp1;
    float R, C, tau, t, dt, vo, i, Vcc;

    R = 1000.0;
    C = 0.0001;
    Vcc = 10.0;
    tau = R * C;
    dt = 0.001;
    vo = 0.0;

    fp1 = fopen("d:\\C program\\data2.csv", "w");
    for(t = 0.0; t < 1.0; t += dt);
     {
         vo = rk4(Vcc, vo, tau, dt);
         i = (Vcc - vo)/R;
         fprintf(fp1, "%f,%f,%f\n", t, vo, i);
     }
    fclose(fp1);
    return 0;
}

float rk4(float xin, float xold, float tau, float dt)
{
    float k1, k2, k3, k4, xout;

    k1 = dt * (xin - xold) / tau;
    k2 = dt * (xin - (xold + k1 /2.0)) / tau;
    k3 = dt * (xin - (xold + k2 /2.0)) / tau;
    k4 = dt * (xin - (xold + k3)) / tau;

    xout = xold + (k1 + 2.0 * k2 + 2.0 * k3 + k4) /6.0;
    return(xout);
}

