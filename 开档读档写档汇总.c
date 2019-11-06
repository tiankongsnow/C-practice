#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * output;
    FILE * input;
    output = fopen("test1.txt", "r");//开档读档
    int i;
    int num[4];
    for(i = 0; i < 4; i++){
        fscanf(output, "%d", &num[i]);//读入
    }
    for(i=0; i<4; i++){
        printf("%d ", num[i]);//输出到控制台
    }

    input = fopen("test2.txt", "w");开档写档
    for( i = 0; i< 4; i++){
        fprintf(input, "%d ", num[i]);//写档
    }
    fclose(output);
    fclose(input);//关档
}
