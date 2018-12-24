#include <omp.h>
#include <stdio.h>
static long num_steps = 100000000;
#define NUM_THREADS 4 
int main ()
{
  double step = 1.0 / (double)num_steps;
  double wtime = omp_get_wtime ();
  double pi = 0;
  int num_threads = NUM_THREADS;
  #pragma omp parallel num_threads(NUM_THREADS)
  {
    int ID = omp_get_thread_num ();
    if (ID == 0) {
      num_threads = omp_get_num_threads();
    }
    int i;
    double x;
    double y;
    for (y = 0, i = ID; i < num_steps; i = i + num_threads) {
      x = (i + 0.5) * step;
      y += 4.0 / (1.0 + x * x);
    }
    y *= step;
    #pragma omp atomic
      pi += y;
  }
  wtime = omp_get_wtime () - wtime;
  printf ("pi = %g wtime = %g true num threads %d\n", pi, wtime, num_threads);   
  return 0;
}


