#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 100
 
int main()
{   int i;
    int len;
    char input[MAX_STRING_LENGTH];
    while(scanf("%c", input) != EOF){
        len = strlen(input);
        for(i = 0; i < len; i++){
            if(input[i]!='\n')
            input[i]-=5; //K is 5
            //printf("%d\n",input[i]);
            printf("%c",input[i]);
        }
    }
}
