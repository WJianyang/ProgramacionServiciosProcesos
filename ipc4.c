#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int fd[2], fd1[2];
    char buffer[30];
    pid_t pid;

    pipe(fd);
    pipe(fd1);

    pid = fork();

    if (pid == 0) {
        close(fd[1]);
        close(fd1[0]);
        int n, f = 1;
        read(fd[0], &n, sizeof(int));
        printf("El proceso padre genera el numero %d en el pipe1\n",n);
        
          for(int x = n; x > 0; x--){
            f = f * x;
          }
        write(fd1[1], &f, sizeof(int));
        close(fd[0]);
        close(fd1[1]);

    } else {
        
        close(fd[0]);
        close(fd1[1]);
        int nAleatorio;
        nAleatorio = rand() % 10 + 1;
        write(fd[1], &nAleatorio, sizeof(int));
        wait(NULL);
        int r;
        read(fd1[0],&r, sizeof(int));
        printf("El factorial calculado por el proceso hijo: %d != %d\n",nAleatorio,r);
        close(fd[1]);
        close(fd1[0]);
    }
}