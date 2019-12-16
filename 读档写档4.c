#include<stdio.h>
int main(){
    FILE * output;
    int num1;
    int num2;
    output = fopen("testout4.txt", "w"); //会自动产生新的文件 write
    while(scanf("%d %d", &num1, &num2) != EOF){ //控制台连续输入
        fprintf(output, "%d %d\n", num1, num2); //txt中显示
    }
    fclose(output);
}
