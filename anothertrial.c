/*
* Gnuplot Call
*
* Copyright (c) 2009 Tony Saad <remineur@gmail.com>
* (Written by Tony Saad <remineur@gmail.com>)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void plotResults(double* xData, double* yData, int dataSize);
int main() {
 int i = 0;
 int nIntervals = 100;
 double intervalSize = 1.0;
 double stepSize = intervalSize/nIntervals;
 double* xData = (double*) malloc((nIntervals+1)*sizeof(double));
 double* yData = (double*) malloc((nIntervals+1)*sizeof(double));
 xData[0] = 0.0;
 double x0 = 0.0;
 for (i = 0; i < nIntervals; i++) {
 x0 = xData[i];
 xData[i+1] = x0 + stepSize;
 }
 for (i = 0; i <= nIntervals; i++) {
 x0 = xData[i];
 yData[i] = sin(x0)*cos(10*x0);
 }
 plotResults(xData,yData,nIntervals);
 return 0;
}
void plotResults(double* xData, double* yData, int dataSize) {
 FILE *gnuplotPipe,*tempDataFile;
 char *tempDataFileName;
 double x,y;
 int i;
 tempDataFileName = "tempData";
 gnuplotPipe = popen("c:\\gnuplot\\bin\\pgnuplot -persist","w");
 if (gnuplotPipe) {
 fprintf(gnuplotPipe,"plot \"%s\" with lines\n",tempDataFileName);
 fflush(gnuplotPipe);
 tempDataFile = fopen(tempDataFileName,"w");
 for (i=0; i <= dataSize; i++) {
 x = xData[i];
 y = yData[i];
 fprintf(tempDataFile,"%lf %lf\n",x,y);
 }
 fclose(tempDataFile);
 printf("press enter to continue...");
 getchar();
 remove(tempDataFileName);
 fprintf(gnuplotPipe,"exit \n");
 } else {
 printf("gnuplot not found...");
 }
}
