/* 408420902 */
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int i;
    int k = 0;
    int new_arr[5][5];
    int arr[25];
    int check[52] = {0};
    int sum = 0;

    int j=0;
    while (j < 25){
        arr[j] = (rand() % 25) + 1;  //1~25
            if(check[arr[j]-1] == 0){
                check[arr[j]-1] = 1;
                j++;
        }
    }
    /*save arry*/
    while(k < 25){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                new_arr[i][j] = arr[k];
                k++;
            }
        }
    }
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%2d\t", new_arr[i][j]);
        }
        printf("\n");
    }
    i=0;
    j=0;
    for(;i <= 4;){
        for(;j <= 4;){
            if((i == 4 && j==3) || (i == 3 && j==4)){
                break;
            }
            if(i==4){
                printf("right %d\n", new_arr[i][j+1]);
                sum += new_arr[i][j+1];
                j++;
            }
            else if(j == 4){
                printf("down  %d\n", new_arr[i+1][j]);
                sum += new_arr[i+1][j];
                i++;
            }
            else if(new_arr[i+1][j] > new_arr[i][j+1]){
                printf("right %d\n", new_arr[i][j+1]);
                sum += new_arr[i][j+1];
                j++;
            }
            else{
                printf("down  %d\n", new_arr[i+1][j]);
                sum += new_arr[i+1][j];
                i++;
            }
        }
        if((i == 4 && j==3) || (i == 3 && j==4)){
            break;
        }
    }
    printf("finish!\n");
    printf("step is %d", sum);//caculate sum
    return 0;
}

