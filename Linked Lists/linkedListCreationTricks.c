#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    int numOfNodes;
}Node;

Node* createNode(int num);
Node* addNode(Node** head, int num);
void displayNodes(Node* head);
Node* insertAtBeginning(Node** head, int num);


Node* createNode(int num){
    Node* head = malloc (sizeof(Node));
    if (head == NULL){
        printf("Memory alloc failed ");
        exit(1);
    }

    head->data = num;
    head->next = NULL;
    return head;
}

Node* addNode(Node** head, int num){  //insert at end bro
    Node* newNode = createNode(num);
    Node* temp = *head;
 
    if (*head == NULL){
        *head = newNode;
        return *head;
    }

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode; 

    return *head;
}

void displayNodes(Node* head){
    Node* temp = head;

    while (temp != NULL){
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", head->numOfNodes);

}

Node* insertAtBeginning(Node** head, int num){
    Node* newNode = createNode(num);

    if (*head == NULL){
        *head = newNode;
        return *head;
    }

    newNode->next = *head;
    *head = newNode;

   
return *head;

}
int main (){

    int size;
    Node* head = NULL;
    int num;

    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    getchar();

    
    for (int i = 0; i < size; i++){
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &num);

        head = addNode (&head, num);
    }

    printf("Data entered in the list:\n");
    displayNodes(head);


    printf("Enter the data to insert at the beginning of the list: ");
    scanf("%d", &num);

    head = insertAtBeginning(&head, num);

    printf("Data entered in the list after insertion:\n");
    displayNodes(head);
    return 0;


}