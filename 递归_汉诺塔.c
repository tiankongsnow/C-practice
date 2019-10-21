#include<stdio.h>

void hannuota(int N, char A, char B, char C){
    if(1 == N){
        printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", N, A, C);
    }
    else{
        hannuota(N-1, A, C, B);
        printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", N-1, A, C);
        hannuota(N-1, B, A, C);
    }
}

int main(){

    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    int n;
    printf("请输入要移动的盘子个数: ");
    scanf("%d", &n);

    hannuota(n, ch1, ch2, ch3);
    return 0;
}
