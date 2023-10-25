#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){

     int fd[2]; 
     time_t hora;
     char *fecha ;
     time(&hora);
     fecha = ctime(&hora) ;
     char buffer[30];
     pid_t pid;
    
     pipe(fd); 
     
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]);
                printf("Soy el proceso hijo con pid %d \n",getpid());
                read(fd[0], buffer, 20); 
                printf("Fecha/hora: %s\n",buffer);
     
     }
     
     else
     
     {
                close(fd[0]);
                
                write(fd[1],fecha, 20);  
                wait(NULL);
    
     }
     
        
}
