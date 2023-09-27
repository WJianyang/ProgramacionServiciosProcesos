#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
  pid_t pid_hijo;
  
  pid_hijo = fork();
  
  if(pid_hijo == 0){
    printf("Soy Jianyang y estoy en el proceso hijo\n");
  }
  else{
    wait(NULL);
    printf("Soy el proceso padre, mi PID es %d y el PID de mi hijo es %d\n",getpid(),pid_hijo);
  }
}
