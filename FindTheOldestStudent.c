#include "FindTheOldestStudent.h"
#include <string.h>
#include <stdlib.h>

void replaceCharsWithSpace(char date[]){
    for(int i = 0; i < strlen(date); i++) {
        if (date[i] == '/' || date[i] == '.'){
            date[i] = ' ';
        }
    }
}

int compareAge(char date1[], char date2[]){
    char date1Copy[100], date2Copy[100];
    strcpy(date1Copy, date1);
    strcpy(date2Copy, date2);

    replaceCharsWithSpace(date1Copy);
    replaceCharsWithSpace(date2Copy);

    char *d1 = strtok(date1Copy, " ");
    int tmp1[3];
    int n1 = 0;
    while(d1 != NULL){
        int date = atoi(d1);
        tmp1[n1] = date;
        n1++;
        d1 = strtok(NULL, " ");
    }

    char *d2 = strtok(date2Copy, " ");
    int tmp2[3];
    int n2 = 0;
    while(d2 != NULL){
        int date = atoi(d2);
        tmp2[n2] = date;
        n2++;
        d2 = strtok(NULL, " ");
    }
    
    for(int i = 2; i >= 0; i--){
        if(tmp1[i] > tmp2[i])
            return 0;
        else if(tmp1[i] < tmp2[i])
            return 1;
    }
    return 0;
}

Student findOldestStudent(Student arr[], int num){
    Student oldestStudent = arr[0];

    for(int i = 1; i < num; i++){
        if(compareAge(arr[i].birthdate, oldestStudent.birthdate) > 0){
            oldestStudent = arr[i];
        }
    }
    return oldestStudent;
}