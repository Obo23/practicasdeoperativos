#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
    pid_t pid;
    int x,y;
 
    for(x=1;x<=4;x++)
    {
        pid=fork(); 
        if(pid)
        {
        sleep(2);
        }
        else
        {
            printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
            sleep(2);
            if(x==1 || x==2)
            {
                for(y=1;y<=2;y++)
                {
                    pid=fork();
                    if(pid)
                    {
                        sleep(2);
                    }
                    else
                    {
                        printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
                        sleep(2);
                        if(y==2){
                            pid=fork();
                            if(pid)
                            {
                                sleep(2);
                            }
                        }
                    }
                }
            }
            else if(x==3)
            {
                pid=fork();
                if(pid)
                {
                    sleep(2);
                }
                else
                {
                    printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
                    sleep(2);
                }
            }
            exit(0);
        }
    }
    return 0;
}