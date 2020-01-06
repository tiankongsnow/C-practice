/* 首轮开始时先印出九宫格图形，最初格子上皆为0；
玩家的记号是1；计算机是2
由玩家先输入下的位置，输入时都是输入坐标
*已经填入记号的地方不可以再填入记号!!*
玩家与计算机持续轮流直到有一方先连成一条线为止

联机后请找出没有下过地方的格子(记号为0)
计算周围八格的数字加总，并印出来。
若原本记号为1或2的位置则填0就好。*/
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j;
    int pi, pj;
    int ci, cj;
    int arr[3][3] = {0};
    srand(time(NULL));

    /* show initial table */
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    while(1){
        /* player choose, not to repeat positions */
        while(1){
            printf("\nPlayer input: ");
            scanf("%d %d", &pi,&pj);
            if(arr[pi][pj] == 0){ // 未用过的位置玩家才能使用
                arr[pi][pj] = 1;
                break;
            }
            else{
                printf("\nerror");
            }
        }

        /* computer choose, not to repeat positions */
        while(1){
            ci = rand() % 3;//0~2
            cj = rand() % 3;
            if(arr[ci][cj] != 0){ // 该位置已经被使用再随机产生一次
                ci = rand() % 3;
                cj = rand() % 3;
            }
            else{
                arr[ci][cj] = 2;
                printf("Computer input: %d %d\n", ci, cj);
                break;
            }
        }

        /* show current table */
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        /* Determine if it is connected */
        if(arr[0][0]==1 && arr[0][1]==1 && arr[0][2]==1) {printf("\nplayer win!"); break;}
        if(arr[1][0]==1 && arr[1][1]==1 && arr[1][2]==1) {printf("\nplayer win!"); break;}
        if(arr[2][0]==1 && arr[2][1]==1 && arr[2][2]==1) {printf("\nplayer win!"); break;}
        if(arr[0][0]==1 && arr[1][0]==1 && arr[2][0]==1) {printf("\nplayer win!"); break;}
        if(arr[0][1]==1 && arr[1][1]==1 && arr[2][1]==1) {printf("\nplayer win!"); break;}
        if(arr[0][2]==1 && arr[1][2]==1 && arr[2][2]==1) {printf("\nplayer win!"); break;}
        if(arr[0][0]==1 && arr[1][1]==1 && arr[2][2]==1) {printf("\nplayer win!"); break;}
        if(arr[2][0]==1 && arr[1][1]==1 && arr[0][2]==1) {printf("\nplayer win!"); break;}

        if(arr[0][0]==2 && arr[0][1]==2 && arr[0][2]==2) {printf("\ncomputer win"); break;}
        if(arr[1][0]==2 && arr[1][1]==2 && arr[1][2]==2) {printf("\ncomputer win"); break;}
        if(arr[2][0]==2 && arr[2][1]==2 && arr[2][2]==2) {printf("\ncomputer win"); break;}
        if(arr[0][0]==2 && arr[1][0]==2 && arr[2][0]==2) {printf("\ncomputer win"); break;}
        if(arr[0][1]==2 && arr[1][1]==2 && arr[2][1]==2) {printf("\ncomputer win"); break;}
        if(arr[0][2]==2 && arr[1][2]==2 && arr[2][2]==2) {printf("\ncomputer win"); break;}
        if(arr[0][0]==2 && arr[1][1]==2 && arr[2][2]==2) {printf("\ncomputer win"); break;}
        if(arr[2][0]==2 && arr[1][1]==2 && arr[0][2]==2) {printf("\ncomputer win"); break;}
    }

    /* Calculate nearby values */
    printf("\n");
    int sum[i][j];
    for(i = 0; i < 3; i++){
        for(j = 0, sum[i][j] = 0; j < 3; j++, sum[i][j] = 0){
            if(j > 0){
                printf(" ");
            }
            if(arr[i][j]){                      //the grid is (1或者2)
                printf("0");
            }
            else{                               //the grid is (0)
                if(i > 0){ //there is the upper grid 边边角角的部分
                    sum[i][j] += arr[i-1][j];
                }                        
                if(i < 3-1){  //there is the lower grid
                    sum[i][j] += arr[i+1][j];
                }                     
                if(j > 0){ //there is the left grid  边边角角的部分
                    sum[i][j] += arr[i][j-1];
                }                      
                if(j < 3-1){ //there is the right grid
                    sum[i][j] += arr[i][j+1];
                }                    
                if(i > 0 && j > 0){ //there is the upper left grid
                    sum[i][j] += arr[i-1][j-1];
                }               
                if(i > 0 && j < 3-1){ //there is the upper right grid
                    sum[i][j] += arr[i-1][j+1];
                }             
                if(i < 3-1 && j > 0){ //there is the lower left grid
                    sum[i][j] += arr[i+1][j-1];
                }           
                if(i < 3-1 && j < 3-1){ //there is the lower right grid
                    sum[i][j] += arr[i+1][j+1];
                }         
                printf("%d", sum[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
