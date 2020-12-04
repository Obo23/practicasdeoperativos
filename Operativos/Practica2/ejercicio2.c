#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>  
#include <stdio.h> 
#define MAX_FILE_NAME 100 

pthread_t tid[1];
int counter;
pthread_mutex_t lock;
  
void* contar() 
{ 
    FILE* fp; 
  
    // Character counter (result) 
    int count = 0; 
  
    char filename[MAX_FILE_NAME]; 
  
    // To store a character read from file 
    char c; 
  
    // Get file name from user. 
    // The file should be either in current folder 
    // or complete path should be provided 
    printf("Enter file name: "); 
    scanf("%s", filename); 
  
    // Open the file 
    fp = fopen(filename, "r"); 
  
    // Check if file exists 
    if (fp == NULL) { 
        printf("Could not open file %s", 
               filename); 
        return 0; 
    } 
    printf("Job started\n", counter);
    // Extract characters from file 
    // and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if(c=='a' || c=='A')
        // Increment count for this character 
            count = count + 1; 
  
    // Close the file 
    fclose(fp); 

    printf("Job finished, counting a's \n", counter);

    // Print the count of characters 
    printf("The file %s has %d characters\n ", 
           filename, count); 
  
    return 0; 
}
int main(void){
    int i = 0;
    int err;
    
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 1)
    {
        err = pthread_create(&(tid[i]), NULL, &contar, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
    printf("Voy a hacer el join de 1 que es la tarea\n");
    pthread_join(tid[0], NULL);
    printf("Voy a destruir el mutex\n");
    pthread_mutex_destroy(&lock);

    return 0;
}
