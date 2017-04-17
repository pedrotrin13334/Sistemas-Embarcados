#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
long int v[50000];
clock_t start,end;
int m[4];
long int maior[4],maior_todos = 0;
void* act(void *args)
{  int *pnt = args;
  int i = *pnt;
  for(int k = i*12500; k <= (i+1)*12500; k++)
  {
     if(maior[i] < v[k])
     {
         maior[i] = v[k];
     }
  }
  pthread_exit(NULL);
  return NULL;
}
int main(int argc, char const *argv[]) {
start = clock();
srand(/*time(NULL)*/ 30);
  for (int i = 0; i<50000;i++)
  {  v[i] = rand();
  }
  pthread_t mythread[4];
  for(int i=0;i<4;i++)
  { m[i] = i;
  pthread_create(&mythread[i],NULL,act,&m[i]);
  pthread_join(mythread[i],NULL);
  }
  for(int i = 0; i<4 ;i++)
  {
    if(maior_todos < maior[i])
    {
      maior_todos =maior[i];
    }
  }
  end = clock();
  printf("%ld\n %f\n",maior_todos,((double)end-start)/CLOCKS_PER_SEC);
  return 0;
}
