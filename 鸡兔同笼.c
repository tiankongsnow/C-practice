/*引入头文件函数*/
#include<stdio.h>
#include<stdlib.h>
/*主函数*/
int main()
{
    double Asum;//animal sum
    double Fsum;//foot sum
    double chook;//鸡
    double rabbit;//兔
    /*输入输出*/
    printf("Asum:");
    scanf("%lf",&Asum);
    printf("Fsum:");
    scanf("%lf",&Fsum);
     /*算法*/
    rabbit = (Fsum-2*Asum)/2;
    chook = (4*Asum-Fsum)/2;
     /*输出结果*/
    printf("the num of rabbit is:%f\n",rabbit);
    printf("the num of chook is:%f\n",chook);
    system("pause");
    return 0;


}
