#ifndef FindTheYoungestStudent_h
#define FindTheYoungestStudent_h

#include "main.h"
#include "FindTheOldestStudent.h"

extern int n;
extern Student arr[1005];

int compareAgeSmaller(char date1[], char date2[]);
Student findYoungestStudent(Student arr[], int num);


#endif

