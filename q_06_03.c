#include<stdio.h>
#include<unistd.h>
int main(int argc,char **argv)
{ int i;
for(i = 1;i<= argc -1;i++)
{ 
pid_t pid = fork();
if(pid == 0)
{
 printf("filho executando %d %s\n",i,argv[i]); 
 execlp(argv[i],argv[i],NULL); 
}
else
{
 printf("pai %d\n",getpid());
}

}
return 0;
}
