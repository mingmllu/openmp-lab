#include <omp.h>
#include <stdio.h>

int main()
{
  int x = 0;
  #pragma omp parallel
  {
    #pragma omp task
    {
//      ++x;
      int id = omp_get_thread_num();
      printf("task[%d] x = %d\n", id, ++x);
    }
  }
}
