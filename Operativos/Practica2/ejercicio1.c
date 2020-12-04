#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int i,n;
unsigned long long fact = 1;



pthread_t thread1,thread2,thmain;
pthread_attr_t attr;

unsigned long long factorial(int a){
  for (i = 1; i <= a; ++i) {
            fact *= i;
        }
        return fact;
}



void *func1 (void *arg){
    printf("Soy el thread y estoy ejecutando func1 \n");
    printf("El factorial de %d = %llu\n",5,factorial(5));
    sleep(4);
    printf("Soy el thread 1 termino \n");
    fact=1;
    pthread_exit(NULL);
}

void *func2 (void *arg){
    int err;
    printf("Soy el thread2 y estoy ejecutando factorial2 \n");

    if(err = pthread_join(thread1, NULL)){//El thread1 explota
      printf("Error al esperar al thread1");

    }else{
      printf("Soy el thread2, thread 1 ha terminado y ejecuto factorial2 \n");
          printf("El factorial de %d = %llu \n",3,factorial(3));
      sleep(2);
    }

    pthread_exit(NULL);
}

pthread_mutex_t my_lock;


int main(void) {
  printf("Hello World\n");

  thmain =pthread_self();

  pthread_attr_init(&attr);

  printf("Soy la funcion main y voy a lanzar los threads\n");

  pthread_mutex_init(&my_lock, NULL);
  pthread_mutex_lock(&my_lock);
  pthread_create(&thread1, &attr, func1, NULL);
  pthread_mutex_unlock(&my_lock);

  pthread_create(&thread2, &attr, func2, NULL);

  printf("Soy la funcion main: he lanzado los threads y termino\n");

  pthread_exit(NULL);

}
