#include<stdio.h>
int main(){
    FILE * input;
    FILE * output;
    int num1;
    int num2;
    input = fopen("testin1.txt", "r"); // 不会自动产生新文件 read,只会读一行
    output = fopen("testout2.txt", "w"); //会自动产生新的文件 write
    while(fscanf(input, "%d %d", &num1, &num2) != EOF){ //连续读取input，每次读一行
        fprintf(output, "%d %d\n", num1, num2); //在output中显示
    }
    fclose(input);
    fclose(output);
}
