#include <stdio.h>
#include <omp.h>

int func(int k)
{
  int i = -1;
  #pragma omp task shared(i)
  {
    int id = omp_get_thread_num();
    i = id;
    printf("thread id = %d k = %d\n", id, k);
  }
  #pragma omp taskwait
  return i;
}


int main()
{
  #pragma omp parallel
  {
    #pragma omp master
    {
      printf("[%d]", omp_get_thread_num());
      #pragma omp task
      {
        printf("A%d", omp_get_thread_num());
      }
      #pragma omp task
      {
        printf("B%d", omp_get_thread_num());
      }
      #pragma omp taskwait
      #pragma omp task
      {
        printf("C%d", omp_get_thread_num());
      }
      printf("<%d>", omp_get_thread_num());
    }
  }
  printf("=======================\n\n");
  return 0;
}
