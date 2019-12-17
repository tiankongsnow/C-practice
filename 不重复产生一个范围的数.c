#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int num[30];
    int check[30] = {0};
    int j = 0;
    int i = 0;
    while(i < 30){
        num[i] = rand() % 30 + 1; //(0~29)+1 = 1~30
        if(check[num[i] - 1] == 0){ //检查不重复
            check[num[i] - 1] = 1;
            i++;
        }
    }
    while(j < 30){
        printf("num[%d] = %d\n",j, num[j]);
        j++;
    }
}
