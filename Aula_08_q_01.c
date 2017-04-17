#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int numero = 0;
int flag = 0 ;
void* teste()
{ while(1)
  {
    if(flag == 1)
    {
      printf("%d\n",numero);
      flag = 0;
    }
    else if( flag == 2)
    {
      return 0;
    }

  }
}
int main(int argc, char const *argv[]) {
  pthread_t mythread;
  pthread_create(&mythread,NULL,teste,NULL);
  while(1)
  {
    sleep(1);
    numero++;
    flag = 1;
    if(numero == 11)
    { flag = 2;
      break;
    }
  }
  return 0;
}
