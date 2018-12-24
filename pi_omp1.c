#include <omp.h>
#include <stdio.h>
static long num_steps = 100000000;
#define NUM_THREADS 1 
#define PAD 8 
int main ()
{
  double step = 1.0 / (double)num_steps;
  double wtime = omp_get_wtime ();
  double sum[NUM_THREADS][PAD];
  int num_threads = NUM_THREADS;
  #pragma omp parallel num_threads(NUM_THREADS)
  {
    int ID = omp_get_thread_num ();
    if (ID == 0) {
      num_threads = omp_get_num_threads();
    }
    int i;
    double x;
    for (sum[ID][0] = 0, i = ID; i < num_steps; i = i + num_threads) {
      x = (i + 0.5) * step;
      sum[ID][0] += 4.0 / (1.0 + x * x);
    }
  }
  int i;
  double pi;
  for (pi = 0, i = 0; i < num_threads; ++i) {  
    pi += step * sum[i][0];
  }
  wtime = omp_get_wtime () - wtime;
  printf ("pi = %g wtime = %g true num threads %d\n", pi, wtime, num_threads);   
  return 0;
}


