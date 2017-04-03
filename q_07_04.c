#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{ int fd[2];
pipe(fd);
char buf1[257],buf2[257];
pid_t pid = fork();
if(pid == 0)
{ 
  printf("nome de usuario: ");  
  scanf("%s",buf1); 
write(fd[1],buf1,sizeof(buf1));
}
else
{

read(fd[0],buf2,258);
printf("%s\n",buf2);
}
return 0;
}
