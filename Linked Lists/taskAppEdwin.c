//This file is read-only and cannot be edited.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Task* toDoList = NULL;
    int choice;
    char description[100];
    int priority;

    while (1) {
        printf("\\nTo-Do List Menu:\\n");
        printf("1. Add Task\\n");
        printf("2. Delete Task\\n");
        printf("3. Display Tasks\\n");
        printf("4. Exit\\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\\n")] = '\\0'; // Remove newline

                printf("Enter task priority: ");
                scanf("%d", &priority);
                getchar(); // Consume newline
                toDoList = insertTask(toDoList, description, priority);
                break;
            case 2:
                printf("Enter task description to delete: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\\n")] = '\\0'; // Remove newline
                toDoList = deleteTask(toDoList, description);
                break;
            case 3:
                displayTasks(toDoList);
                break;
            case 4:
                freeList(toDoList);
                return 0;
            default:
                printf("Invalid choice. Please try again.\\n");
        }
    }
}

typedef struct Task {
    char description[100];
    int priority;
    struct Task* next;
} Task;

// write functions here
Task* createTask(const char* description, int priority);
Task* insertTask(Task *head, const char* description, int priority);
Task* deleteTask(Task* head, const char* description);
void displayTasks(Task* head);
void freeList(Task* head);


Task* createTask(const char* description, int priority){
    Task* newTask = malloc (sizeof(Task));
    if (newTask == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    
    strcpy(newTask->description, description);
    
    newTask->priority = priority;
    
    newTask->next = NULL;
    
    return newTask;
}

Task* insertTask(Task *head, const char* description, int priority){
    Task* newTask = createTask(description, priority);
    
    
    if (head == NULL||newTask->priority > head->priority){
        newTask->next = head;
        head = newTask;
        return newTask;
    }  
        
        Task* temp = head;
        
        while (temp->next != NULL && temp->next->priority >= newTask->priority) {
            temp = temp->next;
        }
        
        newTask->next = temp->next;
        temp->next = newTask;
        
        
    
    return head;
}

Task* deleteTask(Task* head, const char* description){
    if (head == NULL){
        return NULL;
    }
    Task* temp2 = NULL;
    Task *temp = head;
    
    if (strcmp(description, head->description) == 0){
        head = temp->next;
        free(temp);
        return head;
    } else {
        while (temp != NULL && strcmp(description, temp->description) != 0){
            temp2 = temp;
            temp = temp->next;
        }
        
        if (temp !=NULL){
            temp2->next = temp->next;
            free(temp);
        } else {
            printf("Task '%s' not found.\n", description);
        }
        
       
        return head;
    } 
    
}

void displayTasks(Task* head){
    Task* temp = head;
    if (head == NULL){
        printf("To do list is empty\n");
    } else {
         printf("To-Do List:\n");
         while (temp != NULL){
            
             printf("Priority: %d, Description: %s\n", temp->priority, temp->description);
             temp = temp->next;
         }
    }
}

void freeList(Task* head){
    Task* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
            
    }
}
