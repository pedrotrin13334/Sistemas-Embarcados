#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int fd[2];
int filho()
{ int i = 0;
  while(i <10)
  { 
  	read(fd[0],&i,sizeof(i));
  	printf("%d ",i);
  	
  }
  return 0;
}
int main()
{ int i = 0;
  pid_t child;
  pipe(fd);
  child = fork();
  		if(child == 0)
  		{
  		  filho();
  		}
  		else
  		{
  		while(i<10)
  		{
  		 i++;
  		
  		 write(fd[1],&i,sizeof(i));
  		 sleep(1);
  		 }
  		}
  		wait(NULL);
  		return 0;
}

