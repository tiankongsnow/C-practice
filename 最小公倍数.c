#include<stdio.h>
#include<stdlib.h>
int main(){
    long long a, b;
    long long c, m, n;
    while(scanf("%lld" "%lld", &a, &b)!=EOF){
        if(a==0 && b==0){
            break;
        }
        m=a;
        n=b;
        while(b!=0){  /* 余数不为0，继续相除，直到余数为0 */ 
            c=a%b; 
            a=b;  //最大公因数   最小公倍数=两整数的乘积÷最大公约数
            b=c;
        }
        printf("最大公约数:%lld\n", a);
        printf("最小公倍数:%lld\n", m*n/a);
    }
}
