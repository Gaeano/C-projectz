#include <stdio.h>
#include <stdlib.h>
#include "arrayListFunctions.h"

#ifndef LINKEDLLISTSFUNCTIONS_H
#define LINKEDLLISTSFUNCTIONS_H

typedef struct Node {
    Arraylist* list;
    struct Node* next;
}Node;


Node* createNode(){
    int data;
    int initialCapacity = 2;
    Node* head = (Node*) malloc (sizeof(Node));
    if (head == NULL){
        printf("memory alloc failed for node");
        exit(1);
    }

    head->list = createList(initialCapacity);

    while (1){
        printf("Enter data(-1 to stop): ");
        scanf("%d", &data);
        if (data == -1){
            break;
        }

        
        head->list = insertData(head->list, data);
    }

    head->next = NULL;

    return head;
}

Node* insertNode (Node* head){

    Node* newNode = createNode();

    newNode->next = head;

    return newNode;

}

void displayNode (Node* head){
    Node* temp = head;

    int i = 1;
    while (temp != NULL){
        printf("Node %d (Sum: %d)-> ", i, temp->list->sum);
        for (int j = 0; j < temp->list->count; j++){
            printf("%d, ", temp->list->array[j]);
        }

        printf("\n");
        temp = temp->next;
        i++;
    }
}

Node* sortList(Node* head){

    Node* Lptr = NULL;
    Node* cur; 
    int swapped = 1;
    
    while (swapped == 1){
        cur = head;
        swapped = 0;
        while (cur->next != Lptr){
            if (cur->list->sum < cur->next->list->sum){
                Arraylist* temp2 = cur->list;
                cur->list = cur->next->list;
                cur->next->list= temp2;
                swapped = 1;
            }
            cur = cur->next;
        }
        Lptr = cur;
    
    }
    return head;
    
        
    }
#endif
