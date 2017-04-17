#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <unistd.h>
long int v[50000];
clock_t start,end;
long int maior = 0;
int main(int argc, char const *argv[]) {
start = clock();
srand(/*time(NULL)*/30);
  for (int i = 0; i<50000;i++)
  {  v[i] = rand();
  }
  for (int i = 0; i<50000;i++)
  {  if(maior < v[i])
    {
      maior = v[i];
    }
  }
  end = clock();
  printf("%ld\n %f\n",maior,((double)end-start)/CLOCKS_PER_SEC);
  return 0;
}
