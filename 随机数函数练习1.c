/*引入头文件函数*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*定义主函数*/
int main(){
    /*定义变量*/
    int yourNum;
    int cpNum;
    int a1,a2,a3,a4;
    int b1,b2,b3,b4;
    srand(time(NULL));
    printf("input your number:");
    scanf("%d",&yourNum);
    /*随机取数*/
    cpNum=(rand()% 8998)+1000;
    /*取出每位数字*/
    a1=(int)yourNum/1000;
    a2=(int)(yourNum-a1*1000)/100;
    a3=(int)(yourNum-a1*1000-a2*100)/10;
    a4=(int)(yourNum-a1*1000-a2*100-a3*10);
    b1=(int)cpNum/1000;
    b2=(int)(cpNum-b1*1000)/100;
    b3=(int)(cpNum-b1*1000-b2*100)/10;
    b4=(int)(cpNum-b1*1000-b2*100-b3*10);
    /*判断是否中奖*/
    if(yourNum == cpNum){
        printf("the cp number is: %d\n", cpNum);
        printf("恭喜中大奖");
    }
    else if((a1==b1&&a2==b2&&a3==b3&&a4!=b4)||(a1==b1&&a2==b2&&a3!=b3&&a4==b4)||(a1==b1&&a2!=b2&&a3==b3&&a4==b4)||(a1!=b1&&a2==b2&&a3==b3&&a4==b4)){
        printf("the cp number is: %d\n", cpNum);
        printf("恭喜中二奖");
    }
    else if(a1!=b1&&a2!=b2&&a3!=b3&&a4!=b4){
        printf("the cp number is: %d\n", cpNum);
        printf("恭喜中特别奖");
    }
    else{
        printf("the cp number is: %d\n", cpNum);
        printf("没中奖");
    }
    return 0;
}
