#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"
#include "FindTheOldestStudent.h"

                //Task 1: Enter student number
void numberStudent(){
    printf("Enter student number: ");
    scanf("%d", &n);
}

                //Task 2: Enter students' information
Student enterInformation(){
    Student x;
    printf("Enter Student ID: ");
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
void printToScr(Student x){
    printf("%-10s | %-20s | %-10s | %-10s | %-10s | %-20s | %-10s |\n", "Student ID", "Full name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    printf("%-10s | %-20s | %-10s | %-10.2lf | %-10.2lf | %-20.2lf | %-10.2lf |\n", x.studentID, x.fullname, x.birthdate, x.Algebra, x.Calculus, x.BasicProgramming, x.GPA);
    printf("\n");
}

void printAsTable(){
    printf("%-10s | %-20s | %-10s | %-10s | %-10s | %-20s | %-10s |\n", "Student ID", "Full name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    for(int i = 0; i < n; i++){
        printf("%-10s | %-20s | %-10s | %-10.2lf | %-10.2lf | %-20.2lf | %-10.2lf |\n", arr[i].studentID, arr[i].fullname, arr[i].birthdate, arr[i].Algebra, arr[i].Calculus, arr[i].BasicProgramming, arr[i].GPA);
    }
    printf("\n");
}

                // Task 4: Print student list as a table to a text file
void printToTextFile(){
    FILE *f;
    f = fopen("List_of_Students.txt", "w");
    printf("LIST OF STUDENTS B1\n\n");
    fprintf(f, "%-10s | %-20s | %-10s | %-10s | %-10s | %-20s | %-10s |\n", "Student ID", "Full name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    for(int i = 0; i < n; i++){
        fprintf(f, "%-10s | %-20s | %-10s | %-10.2lf | %-10.2lf | %-20.2lf | %-10.2lf |\n", arr[i].studentID, arr[i].fullname, arr[i].birthdate, arr[i].Algebra, arr[i].Calculus, arr[i].BasicProgramming, arr[i].GPA);
    }
    fclose(f);
}

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
    printf("Student has highest GPA is: %s\n", getHighestGPA(arr, n).fullname);
    printf("Student ID: %s\n", getHighestGPA(arr, n).studentID);
    printf("GPA: %.2lf\n\n", getHighestGPA(arr, n).GPA);
    printf("Student has lowest GPA is: %s\n", getLowestGPA(arr, n).fullname);
    printf("Student ID: %s\n", getLowestGPA(arr, n).studentID);
    printf("GPA: %.2lf\n\n", getLowestGPA(arr, n).GPA);
    printf("Student has highest Basic Programming grade is: %s\n", getHighestBPGrade(arr, n).fullname);
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
void search(Student arr[], int num, char studentID[]){
    int found = 0;
    for(int i = 0; i < num; i++){
        if(strcmp(studentID, arr[i].studentID) == 0){
            printToScr(arr[i]);
            found = 1;
            break;
        }
    }
    if(found == 0)  printf("There is no matched ID\n");
}

void searchByID(){
    printf("Enter ID: ");
    scanf("%s", &foundID);
    search(arr, n, foundID);
}

                //Task 10: Sort the student list by GPA int descending order 
void sortByGPA(Student arr[], int num){
    for(int i = 0; i < num - 1; i++){
        int min_pos = i; 
        for(int j = i + 1; j < num; j++){
            if(arr[j].GPA < arr[min_pos].GPA){
                min_pos = j;
            }
        }
        float tmp = arr[i].GPA;
        arr[i].GPA = arr[min_pos].GPA;
        arr[min_pos].GPA = tmp;
    }
}

void printAfterSort(){
    sortByGPA(arr, n);
    printAsTable();
}

void run(){
    numberStudent();
    enter();
    printAsTable();
    printToTextFile();
    processGrade();
    printLastName();

    //printOldestStudent();
    searchByID(arr, n, foundID);
    printAfterSort();
    
}

int main(){
    run();
    
}