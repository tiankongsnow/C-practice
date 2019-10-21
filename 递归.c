#include<stdio.h>

long f(long n){
    if(1 == n){
        return 1;
    }
    else{
        return f(n-1) * n;
        // return n + f(n-1);这个是累加
    }
    /*用for循环实现累加
    long s = 0;
    int i ;
    for(i = 1; i<=n; i++){
        s+=i;
        return s;
    }
    */


}
int main(){
    printf("%d\n", f(6));
    return 0;
}
