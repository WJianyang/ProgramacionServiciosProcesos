#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p1, p2, p3, p4, p6;
  
  int pid_P1, pid_P2;
  
  printf("Soy P1(%d) y mi padre es %d\t\n",getpid(),getppid());
  pid_P1 = getpid();
  p1 = fork();

  if (p1 == 0 )
  {     
   printf("Soy el P2(%d) y mi padre es P1(%d)\t\n",getpid(),getppid());
   pid_P2 = getpid();
   p2 = fork();
   
   if(p2 == 0)
   {
      printf("Soy el P3(%d) y mi padre es P1(%d)\t\n",getpid(),getppid());
      int pid_abuelo = getppid();
      p3 = fork();
      
      if(p3 == 0)
      {
       printf("Soy el P5(%d), mi padre es P3(%d) y mi abuelo es P2(%d)\t\n",getpid(),getppid(),pid_abuelo);
      }
      else
      {
       wait(NULL);
      }
   }
   else
   {
    wait(NULL);
    
    p4 = fork();
    
    if(p4 == 0)
    {
     printf("Soy el P4(%d) y mi padre es P2(%d)\t\n",getpid(),getppid());
     int pid_abuelo = getppid();
     p6 = fork();
     
     if(p6 == 0)
     {
      printf("Soy el P6(%d), mi padre es P4(%d) y mi abuelo es P2(%d)\t\n",getpid(),getppid(),pid_abuelo);
     }
     else
     {
      wait(NULL);
     }
    }
    else
    {
     wait(NULL);    
    }
   }
  }
  else
  { 
   wait(NULL);     
  }
 
}
