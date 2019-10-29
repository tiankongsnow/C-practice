#include <stdio.h>
/*迭代*/
long long Fbnl(long N){
    long a1 = 0;
    long a2 = 1;
    long a3 = N;
    for (int i = 1; i <N; i++){
        a3 = a2 + a1;
        a1= a2;
        a2 = a3;
    }
    return a3;
}
/*递归*/
long long Fbn2(long n){
     if (n <= 0){
         return 0 ;
     }
     else if (n <= 2){
         return 1 ;    //递归终止条件
     }
     else{
         return Fbn2(n-1) + Fbn2(n-2) ;    //递归
     }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n>92){
            break;
        }
        long tmp = Fbnl(n);
        long tmp1 = Fbn2(n);
        printf("迭代算法 %ld\n", tmp);
        printf("递归算法 %ld", tmp1);

        printf("\n");
    }
}
