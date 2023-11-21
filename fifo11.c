#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 


int main()
{
  int fp, nAleatorio, p, r, unlink;
  
  p=mkfifo("FIFO1", S_IFIFO|0666);
  
  nAleatorio = rand() % 10 + 1;
  fp = open("FIFO1", 1);
  printf("Mandando información al pipe FIFO1...\n");
  write(fp,&nAleatorio, sizeof(int));
  printf("Esperando información del pipe FIFO2...\n");
  
  fp = open("FIFO2", 0);
  read(fp, &r, sizeof(int));
  printf("Leyendo informacion del pipe FIFO2...\n");
  printf("El factorial de %d es %d\n",nAleatorio,r);
  close(fp);   
  remove("FIFO1");
  return 0; 
}