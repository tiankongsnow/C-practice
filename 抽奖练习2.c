/*该代码未完成,只是取出了每位数*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int Ynum, Cnum,i,C=1000;
    int j = 0;
    int Y_num[4], C_num[4];
    srand(time(NULL));
    Cnum=(rand()%9000)+1000;//随机取数

    printf("The computer number is %d\n",Cnum);
    printf("Enter your number:");
    scanf("%d",&Ynum);

    for(i=0;i<4;i++)
    {
        C_num[i] = (Cnum/C)%10; //取出了每位数如3214; 依次Cnum/C=3,32,321,3214,因为是int型
        Y_num[i] = (Ynum/C)%10;
        C/=10;
    }
}
