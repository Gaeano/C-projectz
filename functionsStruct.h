#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char** array;
    int length;
    int count;
}ArrayList;


ArrayList* createArray(int initialSize);
void addBook(ArrayList* AL, char* bookName);
void getBook(char* book);
void freeBook(ArrayList* Al);



ArrayList* createArray(int initialSize){
    ArrayList* Al = malloc (sizeof(ArrayList));
    if (Al == NULL){
        printf("memoru alloc failed");
        exit(1);
    }
    
    Al->array = malloc (initialSize * sizeof(char*));
    
    if (Al->array == NULL){
        printf("Alloc Failed\n");
        exit(1);
    }
    
    Al->length = initialSize;
    Al->count = 0;

    return Al;
}

void addBook(ArrayList* AL, char* bookName){
    if (AL->count == AL->length){
        AL->length *= 2;
        AL->array = realloc (AL->array, AL->length * sizeof(char*));
        if (AL->array == NULL){
            printf("realloc failed");
        }
    }
    
    AL->array[AL->count] = strdup(bookName);
    AL->count++;
    
}

void getBook(char* book){
    printf("%s\n", book);
}

void freeBook(ArrayList* Al){
    for (int i = 0; i < Al->count; i++){
        free(Al->array[i]);
    }
    free(Al->array);
    free(Al);
}