#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define   max    100
bool isnum(char str[], int len);

int main(){
    char str[max] = {'\0'};
    int len;
    while(scanf("%s", str) != EOF){
        len = strlen(str);
        if(isnum(str, len)){
            printf("全为数字 %d\n", atoi(str));
        }
        else{
            printf("不全为数字\n");
        }
    }
}

bool isnum(char *str, int len){
    int j;
    for(j = 0; j < len; j++){
        if(str[j] >= 48 && str[j] <=57){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
