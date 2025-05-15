#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


// write your function here
void bubbleSortLinkedList(Node *head) {
    int swapped;
    Node *ptr, *lastSorted = NULL;
    
    do {
        swapped = 0;
        ptr = head;
        
        while (ptr->next != lastSorted) {
            if(ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while (swapped);
}

int main() {
    Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 5);
    insertNode(&head, 1);
    insertNode(&head, 4);
    insertNode(&head, 2);
    insertNode(&head, 8);

    printf("Original Linked List: ");
    printList(head);

    // Sort the linked list
    bubbleSortLinkedList(head);

    printf("Sorted Linked List: ");
    printList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}

