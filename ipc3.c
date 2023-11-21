
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
        close(fd[0]);
        
        int n, x = 0;
        
        while(x < 2){
          n = rand() % 49 + 1;
          x++;
          write(fd[1],&n, sizeof(int));
        }
        close(fd[1]);

    } else {
    wait(NULL);
        close(fd[1]);
        int num[2];
        int s, r, m, n, x = 0;
        double d;
        while(x < 2){
          read(fd[0], &n, sizeof(int));
          num[x] = n;
          x++;
        }
        s = num[0] + num[1];
        r = num[0] - num[1];
        m = num[0] * num[1];
        d = num[0] / num[1];
        printf("%d + %d = %d\n",num[0],num[1],s);
        printf("%d - %d = %d\n",num[0],num[1],r);
        printf("%d * %d = %d\n",num[0],num[1],m);
        printf("%d / %d = %f\n",num[0],num[1],d);
        close(fd[0]);
        
    }
}