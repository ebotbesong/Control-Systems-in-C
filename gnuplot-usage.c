#include <stdio.h>
#include <stdlib.h>

int main(void)
{

FILE *f;//pointer to a file
int i;
f = fopen("BoosterData.dat","w");// creating a file in the write mode

/*check whether it is opened or not*/

if (f == NULL)
{
printf("unable to open file");
return 0;
}

/* if the file is  opened now then  we write the results of   following     program to tht file*/

for (i=1;i<10000;i++)

{

fprintf(f,"%d %d\n",i,i*i);


}

fclose(f);




  FILE *pipe_gp = popen("gnuplot -p", "w");

 // fputs("set terminal pn\n", pipe_gp);
  fputs("set xlabel date\n",pipe_gp);
  fputs("plot  'BoosterData.dat' u 1:2 title 'data1'\n", pipe_gp);
  pclose(pipe_gp);
  return 0;
}
