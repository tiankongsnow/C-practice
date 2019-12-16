#include<stdio.h>
int main(){
    FILE * input;
    FILE * output;
    int num1;
    int num2;
    input = fopen("testin.txt", "r"); // 不会自动产生新文件 read,每一次只会读一行 需要自己建立档案
    output = fopen("testout.txt", "w"); //会自动产生新的文件 write
    fscanf(input, "%d %d", &num1, &num2);
    fprintf(output, "%d %d\n", num1, num2);
    fclose(input);
    fclose(output);
}
