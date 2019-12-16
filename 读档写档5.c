#include<stdio.h>
int main(){
    FILE * output;
    int num1;
    int num2;
    output = fopen("testout6.txt", "a"); //会自动产生新的文件 add 追加 不会覆盖
    scanf("%d %d", &num1, &num2);//控制台输入
    fprintf(output, "%d %d\n", num1, num2); //txt中显示
    fclose(output);
}
