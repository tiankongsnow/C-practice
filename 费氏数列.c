/*0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233...*/
#include <stdio.h>
/*Iterative Algorithm*/
long long Fbnl(long N){
    long a1 = 0;
    long a2 = 1;
    long a3 = N;
    for (int i = 1; i <N; i++){
        a3 = a2 + a1;
        a1 = a2;
        a2 = a3;
    }
    return a3;
}
/*Recursive Algorithm*/
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
    printf("please input the pos(0~91):");
    while(scanf("%d", &n) != EOF){
        if(n>92){
            break;
        }
        long tmp = Fbnl(n);
        long tmp1 = Fbn2(n);
        printf("Iterative algorithm/ the number of pos %d is %ld\n", n, tmp);
        printf("Recursive algorithm/ the number of pos %d is %ld", n, tmp1);

        printf("\n");
    }
}
