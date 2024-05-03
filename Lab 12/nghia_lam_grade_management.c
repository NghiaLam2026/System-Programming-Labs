#include <stdio.h>

#define MAX_STUDENTS 50
#define SUBJECTS 5

typedef struct {
    char name[50];
    int rollNo;
    float marks[SUBJECTS];
    float total; 
    float average; 
} Student;

void inputStudentData(Student* students, int count);
void calculateStatistics(Student* students, int count);
void printStudentData(const Student* student);
void printClassStatistics(const Student* students, int count);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount;

    printf("Enter total number of students in class (max 50): ");
    scanf("%d", &studentCount);

    if(studentCount < 1 || studentCount > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    inputStudentData(students, studentCount);
    calculateStatistics(students, studentCount);

    return 0;
}

void inputStudentData(Student* students, int count) {
    for(int i = 0; i < count; ++i) {
        printf("\nEnter data for student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);

        for(int j = 0; j < SUBJECTS; ++j) {
            do {
                printf("Marks for subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
                if(students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                    printf("Invalid marks. Please enter a value between 0 and 100.\n");
                }
            } while(students[i].marks[j] < 0 || students[i].marks[j] > 100);
        }
    }
}

void calculateStatistics(Student* students, int count) {
    float classAverage = 0;
    float highestAverage = 0.0; // Initially set to lowest possible average
    float lowestAverage = 100.0; // Initially set to highest possible average
    int highestIndex = 0; // Index of student with the highest average
    int lowestIndex = 0; // Index of student with the lowest average

    for(int i = 0; i < count; ++i) {
        students[i].total = 0;
        for(int j = 0; j < SUBJECTS; ++j) {
            students[i].total += students[i].marks[j];
        }
        students[i].average = students[i].total / SUBJECTS;
        classAverage += students[i].average;

        // Check if current student has the highest or lowest average
        if(students[i].average > highestAverage) {
            highestAverage = students[i].average;
            highestIndex = i;
        }
        if(students[i].average < lowestAverage) {
            lowestAverage = students[i].average;
            lowestIndex = i;
        }
    }

    classAverage /= count;

    // After calculating the statistics for all students, print them
    printClassStatistics(students, count);
    printf("\nClass Average: %.2f\n", classAverage);

    // Print the student with the highest average
    printf("Highest Average: %s (Roll No: %d) with %.2f\n", students[highestIndex].name, students[highestIndex].rollNo, highestAverage);

    // Print the student with the lowest average
    printf("Lowest Average: %s (Roll No: %d) with %.2f\n", students[lowestIndex].name, students[lowestIndex].rollNo, lowestAverage);
}


void printClassStatistics(const Student* students, int count) {
    printf("\n%-20s %-10s", "Name", "Roll No");
    for(int i = 1; i <= SUBJECTS; ++i) {
        printf("Subject%d ", i); 
    }
    printf("%-7s %-7s\n", "Total", "Average");

    for(int i = 0; i < count; ++i) {
        printStudentData(&students[i]);
    }
}

void printStudentData(const Student* student) {
    printf("%-20s %-10d", student->name, student->rollNo);
    for(int j = 0; j < SUBJECTS; ++j) {
        printf("%-8.2f ", student->marks[j]); 
    }
    printf("%-7.2f %-7.2f\n", student->total, student->average); 
}




