#include <omp.h>
#include <stdio.h>

int main()
{
  int x = 0;
  #pragma omp parallel
  {
   #pragma omp single
   {
    #pragma omp task
    {
      ++x;
      int id = omp_get_thread_num();
      printf("task1 %d id %d\n", x, id);
    }
    #pragma omp task
    {
      ++x;
      int id = omp_get_thread_num();
      printf("task2 %d id %d\n", x, id);
    }
   }
  }
}
