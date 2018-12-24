#include <omp.h>
#include <stdio.h>


int fib(int n)
{
  int x, y;
  if (n < 2) {
    return n;
  }
  #pragma omp task shared(x)
  {
    x = fib(n-1);
  }
  #pragma omp task shared(y)
  {
    y = fib(n-2);
  }
  #pragma omp taskwait
  return (x + y); 
}

int main()
{
  double wtime = omp_get_wtime();
  int F;
  #pragma omp parallel
  {
    #pragma omp master
      F = fib(30);
  }
  wtime = omp_get_wtime() - wtime;
  printf("Fibonacci number = %d wtime %g\n", F, wtime); 
  return 0;
}
