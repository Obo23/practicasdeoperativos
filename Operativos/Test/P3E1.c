#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 512

int main(int argc, char **argv)
{
    int p[2], readbytes;
    char buffer[SIZE];
    pipe(p);

    pid_t childpid, childpid2;
    int status, status2;
    int i;
    int numeros[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    if (childpid == -1 || childpid2 == -1)
    {
        perror("fork no puede crear el hijo\n");
        exit(1);
    }
    else
    {
        if (childpid = fork() == 0)
        {
            close(p[0]); /* cerramos el lado de lectura del pipe */
            strcpy(buffer, "Soy el hijo impar y voy a hacer los cuadrados impares\n");
            for (i = 0; i < 20; i++)
            {
                if (i % 2 == 0)
                {
                    numeros[i] = i * i;
                    printf("Hijo %d: ", getpid());
                    printf("%d\n", numeros[i]);
                }
            }
            write(p[1], buffer, strlen(buffer));
            close(p[1]);
        }
        else
        {
            if (childpid2 = fork() == 0)
            {
                close(p[0]);
                
                for (i = 0; i < 20; i++)
                {
                    if (i % 2 == 1)
                    {
                        numeros[i] = i * i;
                        printf("Hijo %d: ", getpid());
                        printf("%d\n", numeros[i]);
                    }
                }
                strcpy(buffer, "Soy el hijo impar y voy a hacer los cuadrados impares\n");
                write(p[1], buffer, strlen(buffer));
                close(p[1]);
            }
            else
            {
                close(p[1]); /* cerramos el lado de escritura del pipe */
                printf("Soy el padre y esto me llega por la tuberia:\n");
                while ((readbytes = read(p[0], buffer, 1)) > 0)
                    write(1, buffer, readbytes);
                close(p[0]);
            }
        }
    }
    waitpid(childpid, NULL, 0);
    waitpid(childpid2, NULL, 0);
    exit(0);
}
