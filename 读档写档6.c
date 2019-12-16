#include<stdio.h>
int main(){
    FILE * input;
    FILE * output;
    int num1;
    int num2;
    input = fopen("testin5.txt", "r"); // 不会自动产生新文件 read,只会读一行
    output = fopen("testout5.txt", "a"); //会自动产生新的文件 add 只会追加 不会覆盖
    while(fscanf(input, "%d %d", &num1, &num2) != EOF){ //连续读取input，每次读一行
        fprintf(output, "%d %d\n", num1, num2); //在output中显示
    }
    fclose(input);
    fclose(output);
}
