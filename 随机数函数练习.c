/*引入头文件函数*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*主函数*/
int main(){
    /*定义变量*/
    int money;
    int tMoney;
    srand(time(NULL));
    /*取随机数*/
    money = (rand()% 1000)+666;
    printf("you get the money:%d\n",money);
    /*判断*/
    if(money<=3000){
        tMoney=(int)money*(1+0.1);
        printf("you get the total money:%d\n",tMoney);
    }
    else if(3000<money<=5000){
        tMoney=(int)money*(1+0.2);
        printf("you get the total money:%d\n",tMoney);
    }
    else if(money>5000){
        tMoney=(int)money*(1+0.5);
        printf("you get the total money:%d\n",tMoney);
    }
    else{
        printf("you get the total money:%d\n",money);
    }
    system("pause");
    return 0;
}
