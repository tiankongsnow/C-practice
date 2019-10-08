/*定义头文件函数*/
#include<stdio.h>
/*主函数*/
int main(){
    /*定义变量*/
    int year;
    /*while循环，EOF 连续输入输出*/
    while(scanf("%d", &year) != EOF) {
            /*算法*/
         if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
             printf("Leap year!\n");
         }
         else{
             printf("Common year!\n");
         }
    }
}
