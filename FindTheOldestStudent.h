#ifndef FindTheOldestStudent_h
#define FindTheOldestStudent_h

#include "main.h"

extern int n;
extern Student arr[1005];

void replaceCharsWithSpace(char date[]);
int compareAge(char date1[], char date2[]);
Student findOldestStudent(Student arr[], int num);

#endif

