#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 


int main()
{
  int fp, nAleatorio, p, r;
  
  p=mkfifo("PIPE02", S_IFIFO|0666);
  
  nAleatorio = rand() % 10 + 1;
  fp = open("PIPE02", 1);
  printf("Mandando información al pipe PIPE02...\n");
  write(fp,&nAleatorio, sizeof(int));
  printf("Esperando información del pipe PIPE02...\n");
  
  fp = open("PIPE02", 0);
  read(fp, &r, sizeof(int));
  printf("Leyendo informacion del pipe PIPE02...\n");
  printf("El factorial de %d es %d\n",nAleatorio,r);
  close(fp);   
  remove("PIPE02");
  return 0; 
}