#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functionsStruct.h"

int main (){
    int initialSize = 5;

    ArrayList* list = createArray(initialSize);
    
    char bookName[50];
    
    printf("Books in library:\n");
    
    for (int i = 0; i < initialSize; i++){
        printf("%d: ", i+1);
        fgets(bookName, sizeof(bookName), stdin);
        bookName[strcspn(bookName, "\n")] = '\0';
        addBook(list, bookName);
    }
    
    int choice;
  
    
int toni;
     int i = 0;
    while (1){
    printf("\nadd more?\n 1 = yes, 2 = no, 3 = exit\n");
    scanf("%d", &choice);
    getchar();
    
            switch(choice){
            case 1:
          
            while (1){
              
                i++;
            printf("%d: ", list->count+1);
            fgets(bookName, sizeof(bookName), stdin);
            bookName[strcspn(bookName, "\n")] = '\0';
            addBook(list, bookName);
            
            printf("Add more? 1 = yes ,  0 = no\nchoice: ");
            scanf("%d", &toni);
            getchar();
                if (toni == 0){
                    break;
                } 
            
            }
            
            break;
            
            case 2:
            for (int i = 0 ; i < list->count;i++){
            printf("%d: ", i+1);
            getBook(list->array[i]);
            }
            break;

            case 3:
            freeBook(list);
            exit(1);
            break;
            
            default:
            printf("wrong choice >:(");
            break;
        }
   

}

    
    
   
    
    return 0;
}
