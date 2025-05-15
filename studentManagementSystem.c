#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student {
    char name[50];
    int studentID;
    float gpa;
    struct Student* next;
} Student;

// write your functions here

Student* createStudent (char name[], int studentID, float gpa);
Student* insertStudent(Student* head, char name[], int studentID, float gpa);
Student* deleteStudent(Student* head, int studentID);
void displayStudents(Student* head);
void searchStudentByName(Student *head, char searchName[]);
void freeList(Student* head);

Student* createStudent (char name[], int studentID, float gpa){
    Student* newStudent = malloc (sizeof(Student));
    if (newStudent == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    
    
    strcpy (newStudent->name, name);
    newStudent->studentID = studentID;
    newStudent->gpa = gpa;
    
    newStudent->next = NULL;
    
    return newStudent;
}
Student* insertStudent(Student* head, char name[], int studentID, float gpa){
    
    Student* newNode = createStudent(name, studentID, gpa);
    newNode->next = head;
    
    head = newNode;
    
    return head;
    
}

Student* deleteStudent(Student* head, int studentID){
    Student* temp = head;
    Student* prev = NULL;
    
    if (temp != NULL && temp->studentID == studentID){ //first node
        head = temp->next;
        free(temp);
        return head;
    }
    
   while (temp != NULL && temp->studentID != studentID){
       prev = temp;
       temp = temp->next;
   }
   
   prev->next = temp->next;
   free(temp);
    return head;
}

void displayStudents(Student* head){
    printf("Student List:\n");
    Student* temp = head;
    while (temp->next != NULL){
        printf("Name: %s, ID: %d, GPA: %.2f\n", temp->name, temp->studentID, temp->gpa);
        temp = temp->next;
    }
}

void searchStudentByName(Student *head, char searchName[]){
    Student* temp = head;
    
    
    while (temp->next != NULL){
        if (strcmp(temp->name, searchName) == 0){
            printf("Student found:\n");
            printf("Name: %s, ID: %d, GPA: %.2f\n", temp->name, temp->studentID, temp->gpa);
            break;
        } else {
            temp = temp->next;
        }
    }
    
}

void freeList(Student* head){
    Student* temp;
    
    while (head !=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // complete the main function

int choice;
Student* head = malloc (sizeof(Student));
if (head == NULL){
    printf("memory alloc for head failed");
    exit(1);
}

char name[50];
int studentID;
float gpa;
int count;
while (1){
    printf("\nStudent Management System:\n");
    printf("1. Enroll Student\n2. Remove Student\n3. Display Students\n4. Search Student\n5. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice){
        case 1: //enroll Student
        printf("Enter student name: ");
        scanf("%[^\n]s", name);
        getchar();
        
        printf("Enter student ID: ");
        scanf("%d", &studentID);
        
        printf("Enter student GPA: ");
        scanf("%f", &gpa);
        head = insertStudent(head, name, studentID, gpa);
        count++;
        break;
        
        case 2: //delete Student
        printf("Enter student ID to remove: ");
        scanf("%d", &studentID);
        getchar();
        
        head = deleteStudent(head, studentID);
        count++;
        printf("Student with ID %d removed.\n", studentID);
        break;
        
        case 3:
        displayStudents(head);
        count++;
        break;
        
        case 4: // search studentID
        printf("Enter student name to search: ");
        scanf("%[^\n]s", name);
        count++;
        searchStudentByName(head, name);
        break;
        
        case 5:
        freeList(head);
        count++;
        if (count == 4){
            printf("Exiting program.");
        }
        exit(1);
        break;
    }
}

    return 0;
}