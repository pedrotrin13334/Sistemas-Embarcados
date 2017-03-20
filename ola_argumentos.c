#include<stdio.h>
int main(int argc, char** argv)
{
printf("Argumentos: ");
for(int i=1; i<=(argc-1);i++)
{
 printf("%s ",argv[i]);
}
return 0;
}
