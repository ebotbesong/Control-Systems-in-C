#include <math.h>
#include <stdio.h>
#define TMAX (1.0)
#define H (0.0001)
#define K (0.0302)
#define J (0.0000142)
#define R (0.299)
#define L (0.0000823)
void func(double *y, double u, double t, double *f1);

double main()
{
    FILE *data, *gnp;
    char *data_file;
    double t, f1[3], u = 24.0;
    double y[3] = {0.0, 0.0, 0.0};

    data_file = "oirakadai.dat";
    data = fopen(data_file, "w");

    for(t = 0.0; t < TMAX; t += H)
    {
        fprintf(data, "%f %f %f %f\n", t, y[0], y[1], y[2]);
        func(y, u, t, f1);
        y[0] += H * f1[0];
        y[1] += H * f1[1];
        y[2] += H * f1[2];
    }
    fclose(data);

    gnp = popen("gnuplot -persist","w");
    fprintf(gnp, "set xrange [0:1]\n");
    fprintf(gnp, "set yrange [0:800]\n");
    fprintf(gnp, "plot \"%s\" using 1:2 with lines linetype 1 title \"theta\"\n", data_file);
    pclose(gnp);

    return 0;
}

void func(double *y, double u, double t, double *f1)
{
    double A[3][3] =
    {
        {0.0, 1.0, 0.0},
        {0.0, 1.0, K/J},
        {0.0, -K/L, -R/L}

    };
    double B[3] = {0.0, 0.0, 1/L};

    f1[0] = A[0][0]*y[0] + A[0][1]*y[1] + A[0][2]*y[2] + B[0]*u;
    f1[1] = A[1][0]*y[0] + A[1][1]*y[1] + A[1][2]*y[2] + B[1]*u;
    f1[2] = A[2][0]*y[0] + A[2][1]*y[1] + A[2][2]*y[2] + B[2]*u;
}
