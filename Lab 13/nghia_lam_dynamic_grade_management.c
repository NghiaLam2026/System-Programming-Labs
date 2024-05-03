#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define NUM_SUBJECTS 5

// Student structure as a linked list node
typedef struct Student {
    char name[MAX_NAME_LEN];
    int roll_number;
    int grades[NUM_SUBJECTS];
    int total_marks;
    float average_marks;
    struct Student *next;
} Student;

// Function declarations
Student* create_student();
void calculate_grades(Student *student);
void add_student(Student **head);
void display_students(Student *head);
void display_statistics(Student *head);
void free_student_list(Student *head);

int main() {
    Student *head = NULL;
    char choice;

    do {
        add_student(&head);
        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    display_students(head);
    display_statistics(head);
    free_student_list(head);

    return 0;
}

Student* create_student() {
    Student *newStudent = (Student*)malloc(sizeof(Student));
    if(newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter student name: ");
    scanf("%49s", newStudent->name); 
    printf("Enter roll number: ");
    scanf("%d", &newStudent->roll_number);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%d", &newStudent->grades[i]);
    }

    calculate_grades(newStudent);
    newStudent->next = NULL;

    return newStudent;
}

void calculate_grades(Student *student) {
    student->total_marks = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student->total_marks += student->grades[i];
    }
    student->average_marks = (float)student->total_marks / NUM_SUBJECTS;
}

void add_student(Student **head) {
    Student *newStudent = create_student();
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void display_students(Student *head) {
    printf("\n%-20s %-12s %-20s %-12s %-15s\n", "Name", "Roll Number", "Subject Marks", "Total Marks", "Average Marks");
    printf("--------------------------------------------------------------------------------\n");
    Student *temp = head;
    while (temp != NULL) {
        printf("%-20s %-12d ", temp->name, temp->roll_number);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("%-3d ", temp->grades[i]);
        }
        printf(" %-12d %-15.2f\n", temp->total_marks, temp->average_marks);
        temp = temp->next;
    }
}


void display_statistics(Student *head) {
    if (head == NULL) return;

    int count = 0;
    float classTotalAverage = 0, maxAverage = 0, minAverage = 100;
    Student *temp = head, *maxStudent = NULL, *minStudent = NULL;
    while (temp != NULL) {
        classTotalAverage += temp->average_marks;
        if (temp->average_marks > maxAverage) {
            maxAverage = temp->average_marks;
            maxStudent = temp;
        }
        if (temp->average_marks < minAverage) {
            minAverage = temp->average_marks;
            minStudent = temp;
        }
        temp = temp->next;
        count++;
    }
    classTotalAverage /= count;

    printf("\nClass Average: %.2f\n", classTotalAverage);
    if (maxStudent != NULL) {
        printf("Highest Average Grade: %s with %.2f\n", maxStudent->name, maxStudent->average_marks);
    }
    if (minStudent != NULL) {
        printf("Lowest Average Grade: %s with %.2f\n", minStudent->name, minStudent->average_marks);
    }
}

void free_student_list(Student *head) {
    Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
