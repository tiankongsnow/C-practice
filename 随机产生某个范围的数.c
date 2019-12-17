#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int num1;
    int num2;
    num1 = rand() % 30 + 1; //(0~29)+1
    num2 = rand() % 29 + 1; //(0~29)+1
    printf("一班的幸运同学: %d\n", num1);
    printf("二班的幸运同学: %d\n", num2);
}
