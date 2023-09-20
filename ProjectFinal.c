#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"
//#include "FindTheOldestStudent.h"

                //Task 1: Enter student number
void numberStudent(){
    printf("Enter student number: ");
    scanf("%d", &n);
}

                //Task 2: Enter students' information
Student enterInformation(){
    Student x;
    printf("Enter studentID: ");
    gets(x.studentID);
    printf("Enter your full name: ");
    gets(x.fullname);
    printf("Enter your birthdate: ");
    gets(x.birthdate);
    printf("Enter Algebra, Calculus, Basic Programming grades respectively: ");
    scanf("%lf %lf %lf", &x.Algebra, &x.Calculus, &x.BasicProgramming);
    x.GPA = (x.Algebra + x.Calculus + x.BasicProgramming) / 3.0;
    return x;
}

void enter(){
    for(int i = 0; i < n; i++){
        getchar();
        printf("Enter information of student %d:\n", i + 1);
        arr[i] = enterInformation();
        printf("\n");
    }
}

                //Task 3: Print student list as a table to screen
void printTask3(Student x){
    printf("Full name: %s\n", x.fullname);
    printf("Student ID: %s\n", x.studentID);
    printf("Birthdate: %s\n", x.birthdate);
    printf("GPA: %.2lf\n\n", x.GPA);
}

                // Task 4: Print student list as a table to a text file
// void printTask4(){
    
// }

                //Task 5: Process grades:
Student getHighestGPA(Student arr[], int num){
    Student maxGPAStudent = arr[0];
    for(int i = 0; i < num; i++){
        if(arr[i].GPA > maxGPAStudent.GPA)
            maxGPAStudent = arr[i];
    }
    return maxGPAStudent;
}

Student getLowestGPA(Student arr[], int num){
    Student minGPAStudent = arr[0];
    for(int i = 0; i < num; i++){
        if(arr[i].GPA < minGPAStudent.GPA)
            minGPAStudent = arr[i];
    }
    return minGPAStudent;
}

Student getHighestBPGrade(Student arr[], int num){
    Student maxBPGrade = arr[0];
    for(int i = 0; i < num; i++){
        if(arr[i].BasicProgramming > maxBPGrade.BasicProgramming)
            maxBPGrade = arr[i];
    }
    return maxBPGrade;
}

void processGrade(){
    printf("Student have highest GPA is: %s\n", getHighestGPA(arr, n).fullname);
    printf("Student ID: %s\n", getHighestGPA(arr, n).studentID);
    printf("GPA: %.2lf\n\n", getHighestGPA(arr, n).GPA);
    printf("Student have lowest GPA is: %s\n", getLowestGPA(arr, n).fullname);
    printf("Student ID: %s\n", getLowestGPA(arr, n).studentID);
    printf("GPA: %.2lf\n\n", getLowestGPA(arr, n).GPA);
    printf("Student have highest Basic Programming grade is: %s\n", getHighestBPGrade(arr, n).fullname);
    printf("Student ID: %s\n", getHighestBPGrade(arr, n).studentID);
    printf("Grade of Basic Programming: %.2lf\n\n", getHighestBPGrade(arr, n).BasicProgramming);
} 

                //Task 6: Print out student lastName
void printLastName(){
    for(int i = 0; i < n; i++){
        char fullName[100];
        strcpy(fullName, arr[i].fullname);
        char *name = strtok(fullName, " ");
        printf("Last name of student %s is: %s\n", arr[i].fullname, name);
    }
    printf("\n");
}

// void printOldestStudent(){
//     printf("The oldest student is: %s\n", findOldestStudent(arr, n).fullname);
//     printf("Student ID: %d\n", findOldestStudent(arr, n).studentID);
//     printf("Birthdate: %s\n\n", findOldestStudent(arr, n).birthdate);
// }

                //Task 9: Search by StudentID
void searchByID(Student arr[], int num, char studentID[]){
    int found = 0;
    for(int i = 0; i < num; i++){
        if(strcmp(studentID, arr[i].studentID) == 0){
            printTask3(arr[i]);
            found = 1;
            break;
        }
    }
    if(found == 0)  printf("There is no matched ID\n");
}

                //Task 10: Sort the student list by GPA int descending order 

void run(){
    numberStudent();
    enter();
    processGrade();
    printLastName();

    //printOldestStudent();
    searchByID(arr, n, "5");
    
}

int main(){
    run();
    
}