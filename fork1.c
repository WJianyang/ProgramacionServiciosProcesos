#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
  pid_t pid_hijo1, pid_hijo2, pid_nieto;
  
  pid_hijo1 = fork();
  
  if(pid_hijo1 == 0){
    if(getpid()%2==0){
      printf("Soy P2, mi PID es %d y el de mi padre es %d\n",getpid(),getppid());
    }
    else{
      printf("Soy P2 y mi PID es %d\n",getpid());
    }
  }
  else{
    wait(NULL);
    pid_hijo2=fork();
    if(pid_hijo2 == 0){
      pid_nieto=fork();
      if(pid_nieto==0){
        if(getpid()%2==0){
          printf("Soy P4, mi PID es %d y el de mi padre es %d\n",getpid(),getppid());
      	}
      	else{
          printf("Soy P4 y mi PID es %d\n",getpid());
      	}
      }
      else{
      	wait(NULL);
        if(getpid()%2==0){
          printf("Soy P3, mi PID es %d y el de mi padre es %d\n",getpid(),getppid());
        }
        else{
          printf("Soy P3 y mi PID es %d\n",getpid());
        }
      }
    }
    else{
      wait(NULL);
      printf("Soy el proceso padre, mi PID es %d\n",getpid());
    }
    
  }
}
