#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    FILE * input;
    input = fopen("password.txt", "r");//open file
    int num1[7];
    int i;
   // int C = 1000000;
    int num2[7];//最后输出的值;
    /*连续输入输出*/
    while((fscanf(input, "%d", &num)) != EOF){
          //这个方法有问题
          //for(i = 0; i < 7;  i++){
              //num1[i] = (num / C) % 10;
              //C/=10;
          //}
        /*得到每一位数字*/
        num1[0] = (int)num/1000000;
        num1[1] = (int)(num-num1[0]*1000000)/100000;
        num1[2] = (int)(num-num1[0]*1000000-num1[1]*100000)/10000;
        num1[3] = (int)(num-num1[0]*1000000-num1[1]*100000-num1[2]*10000)/1000;
        num1[4] = (int)(num-num1[0]*1000000-num1[1]*100000-num1[2]*10000-num1[3]*1000)/100;
        num1[5] = (int)(num-num1[0]*1000000-num1[1]*100000-num1[2]*10000-num1[3]*1000-num1[4]*100)/10;
        num1[6] = (int)(num-num1[0]*1000000-num1[1]*100000-num1[2]*10000-num1[3]*1000-num1[4]*100-num1[5]*10);
        for(i = 0; i<7; i++){
           num2[i]=num1[i]+3;
           if(num2[i]>=10){
                num2[i]=num2[i]%10;//大一10 就取个位数
           }
        }
        for(i = 0; i < 7; i++){
            printf("%d", num2[i]);//输出
        }
        printf("\n");
    }
}
