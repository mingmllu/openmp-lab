#include <omp.h>
#include <stdio.h>

int main()
{
  #pragma omp parallel num_threads(2)
  {
    #pragma omp single
    {
      printf("A ");
      #pragma omp task
      {
        printf("Race ");
      }
      #pragma omp task
      {
        printf("Car ");
      }
      #pragma omp taskwait
      printf("is fun to watch !");
    }
  }
  printf("\n");
  return 0;

}


