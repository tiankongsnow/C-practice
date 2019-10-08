/*定义头文件函数*/
#include<stdio.h>
#include<stdlib.h>
/*主函数*/
int main(){
    /*定义变量*/
    float num;
    float a;
    int b;
    int c;
    int d;
    int sum;

    while(scanf("%f", &num) != EOF) {
            /*算法*/
         a= num - (int)num;
         b=a*10-(a*10-(int)(a*10));
         c=(a*10-(int)(a*10))*10 - ((a*10-(int)(a*10))*10-(int)((a*10-(int)(a*10))*10));
         d=((a*10-(int)(a*10))*10-(int)((a*10-(int)(a*10))*10))*10;
         sum = b+c+d;
         printf("sum is %d\n",sum);
         system("pause");
         return 0;
    }
}
