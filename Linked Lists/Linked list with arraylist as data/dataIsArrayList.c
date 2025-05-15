#include <stdio.h>
#include <stdlib.h>
#include "arrayListFunctions.h"
#include "linkedListFunctions.h"



int main (){
    int choice;
    int data;
    Node* head  = NULL;

    while (1){
        printf("VIDEO GAME HIGH SCORES\n");
        printf("1. Insert score in an array\n");
        printf("2. Remove Score\n");
        printf("3. Display Score\n"); //sort the score
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
            head = insertNode(head);
                

            break;

            case 2:
            

            break;

            case 3:
            head = sortList(head);
            printf("--SCORES--\n");
            displayNode(head);
            break;
            default:
            printf("Wrong choice try again\n");
            break;


        }


    }

}

