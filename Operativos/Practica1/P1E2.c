#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main (void)
{
    pid_t childpid,childpid2;
    int status, status2;
    int i;
    int numeros[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    if(childpid == -1 || childpid2 == -1){
        perror("fork no puede crear el hijo\n");
        exit(1);
    }
    else
    {
        if(childpid = fork()==0)
        {
            printf("Soy el hijo(PID %d) y voy a hacer los cuadrados pares\n",getpid());
            for(i=0;i<20;i++)
            {
                if(i%2==0)
                {
                    numeros[i] = i*i;
                    printf ("Hijo %d: ",getpid());
                    printf("%d\n",numeros[i]);
                }
            }
        }
        else
        {
            if(childpid2 = fork() == 0)
            {
                printf("Soy el hijo(PID %d) y voy a hacer los cuadrados impares\n",getpid());
                for(i=0;i<20;i++)
                {   
                    if(i%2==1)
                    {
                        numeros[i] = i*i;
                        printf ("Hijo %d: ",getpid());
                        printf("%d\n",numeros[i]);
                    }
                }   
            }
            else
            {
                printf("Soy el padre (PID %d)\n",getpid());
            }
        }
    }
}
