/*Find prime number*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   int n;
    printf("请输入个数:");
    scanf("%d", &n);
    int number[n]; //prime
    int i, j, total=0, max=0, min=32767;
    printf("请输入%d个数:", n);
    for(i = 0 ; i < n; i++){
        scanf("%d",&number[i]);
    }
    printf("prime number :");
    for(i = 0 ; i < n; i++){
        /*Printf the file information*/
        for(j = 2 ; j <= (number[i]-1) ; j++){
            if(number[i] % j == 0){//被整除 不是质数
                break;//break跳回最外层for
            }
        }
        if(j >= number[i]){
            printf("%d ",number[i]);
            /*Calculate the number of primes*/
            total++;
            /*Find the maximum and minimum number of primes*/
            if(number[i] > max){
                max = number[i];
            }
            if(number[i] < min){
                min = number[i];
            }
        }
    }
    printf("\nmax prime number : %d",max);
    printf("\nmin prime number : %d",min);
    printf("\ntotal prime number : %d\n",total);
    return 0;
}
