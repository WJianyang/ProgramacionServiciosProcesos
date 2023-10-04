#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p2, p3, p4;
  int sP1P2, sP2P3, sP3P4;
  
  printf("Soy el padre, mi PID es %d y mi padre es %d\n",getpid(),getppid());
  
  p2 = fork();

  if (p2 == 0 )
  {     
     printf("Soy el P2, mi PID es %d y mi padre es %d\n",getpid(),getppid());
     sP1P2 = getpid() + getppid();
     printf("La suma de P2 y P1 es %d\n",sP1P2);
     
     p3 = fork();
     
     if(p3 == 0)
     {
      printf("Soy el P3, mi PID es %d y mi padre es %d\n",getpid(),getppid());
      sP2P3 = getpid() + getppid();
      printf("La suma de P3 y P2 es %d\n",sP2P3);
      
      p4 = fork();
      if(p4 == 0)
      {
       printf("Soy el P4, mi PID es %d y mi padre es %d\n",getpid(),getppid());
       sP3P4 = getpid() + getppid();
       printf("La suma de P4 y P3 es %d\n",sP3P4);
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
  else
  { 
   wait(NULL);     
  }
   exit(0);
}
