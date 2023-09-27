#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
  pid_t pid_hijo1, pid_hijo2;
  
  pid_hijo1 = fork();
  
  if(pid_hijo1 == 0){
    printf("Soy el proceso P2\n");
    printf("Me voy a dormir 10 segundos...\n");
    sleep(10);
    printf("Despierto\n");
  }
  else{
    pid_hijo2=fork();
    if(pid_hijo2 == 0){
      printf("Soy el proceso P3, mi PID es %d y el PID de mi padre es %d\n",getpid(),getppid());
    }
    else{
      pid_hijo1 = wait(NULL);
      pid_hijo2 = wait(NULL);
      printf("Soy el proceso P1 y soy el padre de P2 y P3\n");
    }
    
  }
}
