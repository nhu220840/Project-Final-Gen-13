#ifndef Main_h
#define Main_h
                
typedef struct{
    char studentID[100];
    char fullname[100];
    char birthdate[100];
    double Algebra, Calculus, BasicProgramming;
    double GPA;
} Student;

extern int n;
extern Student arr[1005];
extern char foundID[100];

void numberStudent();
Student enterInformation();
void enter();
Student getHighestGPA(Student arr[], int num);
Student getLowestGPA(Student arr[], int num);
Student getHighestBPGrade(Student arr[], int num);
void processGrade();
void printLastName();
void printOldestStudent();
void printYoungestStudent();
void search(Student arr[], int num, char studentID[]);
void searchByID();
void sortByGPA(Student arr[], int num);
void printAfterSort();
void run();

#endif
