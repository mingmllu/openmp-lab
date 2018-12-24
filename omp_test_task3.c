#include <stdio.h>
#include <omp.h>

int main()
{
  #pragma omp parallel 
  {
    #pragma omp single
    {
      int i;
      for (i = 0; i < 20; ++i) {
        printf("[%d]\n", omp_get_thread_num());
        #pragma omp task firstprivate(i)
        {
          printf("i = %d thread num = %d\n", i, omp_get_thread_num());
        }
      }
    }
  }
  printf("=======================\n\n");
  return 0;
}
