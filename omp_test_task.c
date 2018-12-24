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
  #pragma omp single
  {
    #pragma omp task
    {
      #pragma omp task
      {
        #pragma omp task
        {
          printf("C1");
        }
        printf("B1");
      }
      #pragma omp task
      {
        #pragma omp task
        {
          printf("C2");
        }
        printf("B2");
      }
      #pragma omp taskwait
      printf("A");
      #pragma omp task
      {
        #pragma omp task
        {
          printf("C3");
        }
        printf("B3");
      }
    }
    //int rv = 10000;
    //int rv = func(id);
    //printf("rv = %d  thread num = %d\n", rv, id);
    //printf("---- the last line of parallel region\n");
  }
  printf("=======================\n\n");
  return 0;
}
