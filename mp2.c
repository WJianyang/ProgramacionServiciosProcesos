#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
  pid_t pid_padre, pid_nieto;
  
  pid_padre = fork();
  
  if(pid_padre == 0){
    pid_nieto = fork();
    if(pid_nieto == 0){
      printf("Soy el proceso P3, mi PID es %d y el PID de mi padre es %d\n",getpid(),getppid());
    }
    else{
      wait(NULL);
      printf("Soy el proceso P2, mi PID es %d y el PID de mi padre es %d\n",getpid(),getppid());
    }
  }
  else{
    wait(NULL);
    printf("Soy el proceso P1, mi PID es %d y el PID de mi hijo es %d\n",getpid(),pid_padre);
  }
}
