#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int fd[2], fd1[2];
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    pid_t pid;

    pipe(fd);
    pipe(fd1);

    pid = fork();

    if (pid == 0) {
    	close(fd[0]);
        close(fd1[1]);
        int dni, r;
        printf("Introduce el numero tu dni: ");
        scanf("%d",&dni);
        write(fd[1], &dni, sizeof(int));
        read(fd1[0], &r, sizeof(int));
        printf("La letra del nif es %c\n",letra[r]);
        close(fd[1]);
        close(fd1[0]);
        

    } else {
        
        close(fd[1]);
        close(fd1[0]);
        int dni, resto;
        read(fd[0], &dni, sizeof(int));
        resto = dni % 23;
        write(fd1[1], &resto, sizeof(int));
        close(fd[0]);
        close(fd1[1]);
        wait(NULL);
    }
}