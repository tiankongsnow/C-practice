#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int comp(int); //define function

int main(){
    srand(time(NULL));
    int num; //rand computer num
    num = (rand()% 1000) + 1;  //1~1000
    printf("computer num is %d\n", num);
    comp(num); //use function
    return 0;
}

int comp(int computer_num){
    int i; //round
    int player_num;
    int low_num = 1;  //low num
    int top_num = 1000;  //top num
    for(i = 1; ;){

        printf("round %d\n", i);
        printf("please guess a number from %d ~ %d:", low_num, top_num);
        scanf("%d", &player_num);
        /*compare num*/
        if((player_num < 1)||(player_num > 1000)){
            printf("input error\n");
        }
        else{
            if(player_num > computer_num){
                top_num = player_num;
                //printf("please guess a number from %d~%d:", low_num, top_num);
                printf("it is too high\n");
                i++;
            }
            else if(player_num < computer_num){
                low_num = player_num;
                //printf("please guess a number from %d~%d:", low_num, top_num);
                printf("it is too low\n");
                i++;
            }
            else{
                printf("you win\n");
                printf("you take %d round\n", i);
                break;
            }
        }
    }
    system("pause");
    return 0;
}
