#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYLISTFUNCTIONS_H
#define ARRAYLISTFUNCTIONS_H

typedef struct ArrayList{
    int *array;
    int count;
    int sum;
    int length;
}Arraylist;


Arraylist* createList (int initialCapacity){
    Arraylist* list = malloc (sizeof(Arraylist));
    if (list == NULL){
        printf("memry alloc failed");
        exit(1);
    }

    list->array = malloc (initialCapacity * sizeof(int));
    if (list->array == NULL){
        printf("array memory alloc failed");
        exit(1);
    }

    list->length = initialCapacity; 
    list->count = 0;
    list->sum = 0;
    return list;

}

Arraylist* insertData(Arraylist* list, int data){
    if (list->count == list->length){
        list->length  *= 2;

        list->array = realloc (list->array, list->length * sizeof(int));
        if (list->array == NULL){
            printf("realloc failed");
            exit (1);
        }
    }

   list->array[list->count] = data;
    list->count++;
    list->sum += data;

    return list;
}




#endif