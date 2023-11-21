#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int fd[2];
    char buffer[30];
    pid_t pid;

    pipe(fd);

    pid = fork();

    if (pid == 0) {
        close(fd[1]);
        int suma = 0;

        while (1) {
            if (read(fd[0], buffer, sizeof(buffer)) <= 0) {
            printf("%s",&buffer);
                break;
            }

           
            int numero = atoi(buffer);
            printf("%d ", numero);
            suma += numero;
             

        }

        printf("\nSuma: %d\n", suma);
    } else {
        close(fd[0]);

        do {
            printf("Numero a sumar: ");
            scanf("%s", buffer);
            write(fd[1], buffer, sizeof(buffer));
        } while (buffer[0] != '+');

        close(fd[1]);
        wait(NULL);
    }
}