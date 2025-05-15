#include <stdio.h>
#include <stdlib.h>

#define NUM_GRADES 5


typedef struct Student {
    char name[50];
    int studentID;
    float grades[NUM_GRADES];
}Student;



Student* addStudent(Student *list, int* size, int* arraySize, char name[], int ID);
void displayStudent(Student *list, float average);
float calculateAverage(Student *list);
Student* updateGrade(Student *list, int ID, int size);


Student* addStudent(Student *list, int* size, int* arraySize, char name[], int ID){
    if (*size == *arraySize){
        *arraySize *= 2;

        list = realloc (list, *arraySize * sizeof(Student));
        if (list == NULL){
            printf("realloc failed");
            exit(1);
        }
    }

    list[*size].studentID = ID;
    strcpy( list[*size].name, name);

    printf("Enter grades for Student %d:\n", *size+1);
    for (int i = 0; i < NUM_GRADES; i++){
        printf("Enter grade %d: ", i+1);
        scanf("%f", &list[*size].grades[i]);
    }

    (*size)++;


    return list;
}

void displayStudent(Student *list, float average){

    printf("Name: %s, ID = %d, Grades = ", list->name, list->studentID);
    
    for (int i = 0; i < NUM_GRADES; i++){
        printf("%.2f ", list->grades[i]);
    }
    printf("Average: %.2f\n", average);

    
}

float calculateAverage(Student *list){
    float sum = 0.0;
    float average= 0.0;
    for (int i = 0 ; i < NUM_GRADES; i++){
        sum += list->grades[i];
    }

    average = sum / NUM_GRADES;

    return average;


}

Student* updateGrade(Student *list, int ID, int size){

for (int i = 0 ; i < size; i++){
    if (list[i].studentID == ID){
        printf("Enter new grades:\n");
        for (int j = 0; j < NUM_GRADES; j++){
            printf("Enter grade %d: ", j+1);
            scanf("%f", &list[i].grades[j]);
        }
        return list;
    }

    
}
    printf("no student with id found\n");
    return list;

}

int main (){

    int size = 0;
    int arraySize = 5;
    float average;
    Student* list = malloc (arraySize * sizeof(Student));
    if (list == NULL){
        printf("memory alloc failed");
        exit(1);
    }

     list = addStudent(list, &size, &arraySize, "Alice Johnson", 101);
     list = addStudent(list, &size, &arraySize, "Bob Smith", 102);
     list = addStudent(list, &size, &arraySize, "Carol Davis", 103);

     printf("\n");
    for (int i = 0 ; i < size; i++){
        printf("Student %d: ", i+1);
        average = calculateAverage(&list[i]);
        displayStudent(&list[i], average);
    }
    printf("\n");
    list = updateGrade(list, 102, size);
    printf("After updating Bob's grades:\n");
    for (int i = 0 ; i < size; i++){
        printf("Student %d: ", i+1);
        average = calculateAverage(&list[i]);
        displayStudent(&list[i], average);
    }

    return 0;

}
