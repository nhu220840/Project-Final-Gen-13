#include "FindTheOldestStudent.h"
#include <string.h>
#include <stdlib.h>

int compareAge(char date1[], char date2[]){  
    char *d1 = strtok(date1, " ");
    char tmp1[100][100];
    int n1 = 0;
    while(d1 != NULL){
        strcpy(tmp1[n1], d1);
        n1++;
        d1 = strtok(NULL, "/. ");
    }

    char *d2 = strtok(date2, "/. ");
    char tmp2[100][100];
    int n2 = 0;
    while(d2 != NULL){
        strcpy(tmp2[n2], d2);
        n2++;
        d2 = strtok(NULL, "/. ");
    }

    for(int i = n1 - 1; i >= 0; i--){
        int num1 = atoi(tmp1[i]);
        int num2 = atoi(tmp2[i]);
        if(num1 < num2){
            return 1;
        }
    }
    return 0;
}


Student findOldestStudent(Student arr[], int num){
    Student oldestStudent = arr[0];

    for(int i = 0; i < num; i++){
        if(compareAge(arr[i].birthdate, oldestStudent.birthdate) > 0){
            oldestStudent = arr[i];
        }
    }
    return oldestStudent;
}