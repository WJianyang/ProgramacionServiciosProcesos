#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 


int main()
{
  int fp, nLeido, r = 1, p;
  
  fp = open("PIPE02", 0);
  printf("Leyendo informacion del pipe PIPE02...\n");
  read(fp, &nLeido, sizeof(int));
  close(fp);
  for(int x = nLeido; x > 0; x--){
            r = r * x;
  }
  printf("%d %d",nLeido,r);
  
  fp = open("PIPE02", 1);
  write(fp, &r, sizeof(int));
  printf("Mandando información al pipe PIPE02...\n");
  close(fp);
  return 0; 
}