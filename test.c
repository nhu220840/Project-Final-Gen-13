#include <stdio.h>
#include <string.h>
#include <math.h>

void compareAge(char date1[], char date2[]){  
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

    for(int i = 0; i < n1 - 1; i++){
        printf("%s\n", tmp1[i]);
    }

    for(int i = n1 - 1; i >= 0; i--){
        if(strcmp(tmp1[i], tmp2[i]) < 0){
            return 1;
        }
    }
    return 0;
}


int main(){
    // printf("%d", compareAge("22/8/2004", "15/2/2004"));
    compareAge("22/8/2004", "15/2/2004");
}