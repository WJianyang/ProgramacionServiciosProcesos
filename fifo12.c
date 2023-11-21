#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 



int main(void)
{
  int fp, nLeido, r = 1, p;
 
  p=mkfifo("FIFO2", S_IFIFO|0666);//permiso de lectura y escritura
  
   fp = open("FIFO1", 0);  
   printf("Leyendo informacion del pipe FIFO1...\n");
   read(fp, &nLeido, sizeof(int));
   
   for(int x = nLeido; x > 0; x--){
            r = r * x;
   }
   fp = open("FIFO2", 1);
   write(fp, &r, sizeof(int));
   printf("Mandando información al pipe FIFO2...\n");
   close(fp);  
  remove("FIFO2");
  return(0);
}