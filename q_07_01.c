#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{ int fd[2];
pipe(fd);
pid_t pid = fork();
char buf[257];
if(pid == 0)
{
 write(fd[1],"olar,estou aqui pai",sizeof("olar,estou aqui pai"));
}
else
{
read(fd[0],buf,257);
printf("%s\n",buf);
}
return 0;
}
