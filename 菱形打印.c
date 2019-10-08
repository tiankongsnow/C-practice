#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 0; //输入行数
    int i = 0;//控制行数
    int m = 0;//空格数
    int z = 0;//星号数
    while(scanf("%d",&n) != EOF){
        if(n % 2==0){
            n=(n-1)/2;
        }
        else{
            n=n/2;
        }
        for(i = 1; i<= n+1; i++){//上部分
        /*刚开始为行数一半（取整）个空格，
        空格数随行数递减因此减i，
        又因为要保证第一次空格数正确加1调整*/
            for(m = 1; m <= n-i+1; m++){ 
                printf(" ");
            }
            for(z = 1; z<=(2*i-1); z++){//星号数按奇数增长
                printf("*");
            }
            printf("\n");
        }
        for(i = 1; i<=n; i++){
            for(m = 1; m <= i; m++){//空格数递增
                printf(" ");
            }
        /*星号数奇数递减 取n=6；
        2*6-1，2*6-3，2*6-5递减*/
            for(z = 1; z<=(2*n-(2*i-1)); z++){
                printf("*");
            }
        printf("\n");
        }
    }   
}
