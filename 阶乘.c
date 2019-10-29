#include<stdio.h>
/*递归*/
long f_recursion(long n){
    if(1 == n){
        return 1;
    }
    else{
        return f_recursion(n-1) * n;
        // return n + f_recursion(n-1);这个是累加
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
/*迭代*/
long f_iteration(long n){
    long result = 1;
    while(n>1){
        result *= n;
        n--;
    }
    return result;
}

int main(){
    printf("递归求法 %ld\n", f_recursion(6));
    printf("迭代求法 %ld\n", f_iteration(6));

    return 0;
}
