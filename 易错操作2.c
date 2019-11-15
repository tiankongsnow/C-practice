#include <stdio.h>
int main(){
    int num, i, flag = 0;
    while(scanf("%d", &num) != EOF){
        if(num == 1 || num == 0){
            break;
        }
        for(i = 2; i <= num-1; i++){
            if(num % i == 0){// 符合该条件不是质数
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("is_prime\n");
        }
        else{
            printf("is_not_prime\n");
        }
        flag = 0; //记得要归位啊！！！！！！
    }
}
