#include <stdio.h>
#include <stdlib.h>

int fun_1(int num);
int fun_2(int num);
int fun_3(float Num);
int fun_4(float Num);

int main(){

    int num = 1234;
    float Num=1.234;

    fun_1(num);
    fun_2(num);
    fun_3(Num);
    fun_4(Num);
}

int fun_1(int num){
    int num_1, num_2, num_3, num_4;

    num_1 = num / 1000 ;
    num_2 = (num % 1000) / 100 ;
    num_3 = (num % 100) /10;
    num_4 = (num % 10) /1;

    printf("方法1: %d\t%d\t%d\t%d\n", num_1, num_2, num_3, num_4); //1  2   3   4
    return 0;
}

int fun_2(int num){
    int i;
    int NUM[4];
    int C = 1000;

    for(i=0;i<4;i++){
        NUM[i] = ( num / C ) % 10; //取出了每位数如3214; 依次num/C=3,32,321,3214,因为是int型
        C/=10;
    }
    printf("方法2: ");
    for(i=0; i<4; i++){
        printf("%d\t", NUM[i]);
    }
    printf("\n");
    return 0;
}

int fun_3(float Num){
    int answer1, answer2, answer3;

    answer1 = ((int)(Num * 10)) % 10; //2
    answer2 = ((int)(Num * 100)) % 10; //3
    answer3 = ((int)(Num * 1000)) % 10; //4

    printf("方法3: %d\t%d\t%d\n", answer1, answer2, answer3);
    return 0;
}

int fun_4(float Num){
    int i;
    int answer[3];
    int c = 10;

    for(i=0;i<3;i++){
        answer[i] = (int)(Num * c) % 10;//2, 3, 4
        c*=10;
    }
    printf("方法4: ");
    for(i=0; i<3; i++){
        printf("%d\t", answer[i]);
    }
    printf("\n");
    return 0;
}
