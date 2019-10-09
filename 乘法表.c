#include<stdio.h>
#include<stdlib.h>
int main(){
    int x, y;
    int i, j;
    while(scanf("%d %d", &x, &y) != EOF){
        //printf("\n");
        printf("*\t");
        for(i = 1; i < y+1; i++){
            printf("%d\t", i);
        }
            printf("\n");
        for(i=1;i<=x;i++) {
            printf("%d\t", i);
            for(j=1;j<=y;j++){
                printf("%d\t", i*j);// %2d 控制宽度为两个字符，且右对齐；如果改为 %-2d 则为左对齐
            }
        printf("\n");
        }
    }
}
