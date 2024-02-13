#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"
#include "FindTheOldestStudent.h"
#include "FindTheYoungestStudent.h"

// gcc FindTheOldestStudent.c FindTheYoungestStudent.c ProjectFinal.c -o program
// gcc .\FindTheOldestStudent.c .\FindTheYoungestStudent.c .\ProjectFinal.c -o program
// gcc ./FindTheOldestStudent.c ./FindTheYoungestStudent.c ./ProjectFinal.c -o program


int n;
Student arr[1005];
char foundID[100];

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
    fprintf(f, "LIST OF STUDENTS B1\n\n");
    fprintf(f, "%-10s | %-20s | %-10s | %-10s | %-10s | %-20s | %-10s |\n", "Student ID", "Full name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    for(int i = 0; i < n; i++){
        fprintf(f, "%-10s | %-20s | %-10s | %-10.2lf | %-10.2lf | %-20.2lf | %-10.2lf |\n", arr[i].studentID, arr[i].fullname, arr[i].birthdate, arr[i].Algebra, arr[i].Calculus, arr[i].BasicProgramming, arr[i].GPA);
    }
    fclose(f);
}

                //Task 5: Process grades:
Student getHighestGPA(Student arr[], int num){
    Student maxGPAStudent = arr[0];
    for(int i = 1; i < num; i++){
        if(arr[i].GPA > maxGPAStudent.GPA)
            maxGPAStudent = arr[i];
    }
    return maxGPAStudent;
}

Student getLowestGPA(Student arr[], int num){
    Student minGPAStudent = arr[0];
    for(int i = 1; i < num; i++){
        if(arr[i].GPA < minGPAStudent.GPA)
            minGPAStudent = arr[i];
    }
    return minGPAStudent;
}

Student getHighestBPGrade(Student arr[], int num){
    Student maxBPGrade = arr[0];
    for(int i = 1; i < num; i++){
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

                //Task 7: Find the oldest student
void printOldestStudent(){
    printf("The oldest student is: %s\n", findOldestStudent(arr, n).fullname);
    printf("Student ID: %s\n", findOldestStudent(arr, n).studentID);
    printf("Birthdate: %s\n\n", findOldestStudent(arr, n).birthdate);
}
                //Task 8: Find the youngest student
void printYoungestStudent(){
    printf("The youngest student is: %s\n", findYoungestStudent(arr, n).fullname);
    printf("Student ID: %s\n", findYoungestStudent(arr, n).studentID);
    printf("Birthdate: %s\n\n", findYoungestStudent(arr, n).birthdate);
}
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
    if(found == 0)  printf("No matching ID found\n");
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

void printSortedList(){
    sortByGPA(arr, n);
    printf("The sorted list is:\n");
    printAsTable();
}


int main(){
    numberStudent();
    enter();
    while(1){
        printf("-------------------------------------------------------------------------------------------\n");
        printf("| 1. Print student list as a table to screen                                              |\n");
        printf("| 2. Print student list as a table to a text file                                         |\n");
        printf("| 3. Print the student having highest GPA, lowest GPA and highest Basic Programing grade  |\n");
        printf("| 4. Print out student lastName                                                           |\n");
        printf("| 5. Print the oldest student                                                             |\n");
        printf("| 6. Print the youngest student                                                           |\n");
        printf("| 7. Search for student information by ID                                                 |\n");
        printf("| 8. Sort the student list by GPA in descending order                                     |\n");
        printf("| 0. Exit                                                                                 |\n");
        printf("-------------------------------------------------------------------------------------------\n");

        printf("Enter your choice: ");
        int choice; scanf("%d", &choice);
        
        if(choice == 1){
            printAsTable();
        }
        else if(choice == 2){
            printToTextFile();
            printf("Printed to file!!!");
        }
        else if(choice == 3){
            processGrade();
        }
        else if(choice == 4){
            printLastName();
        }
        else if(choice == 5){
            printOldestStudent();
        }
        else if(choice == 6){
            printYoungestStudent();
        }
        else if(choice == 7){
            searchByID(arr, n, foundID);
        }
        else if(choice == 8){
            printSortedList();
        }
        else{
            printf("Exit!!!");
            return 0;
        }
    }
    return 0;
}