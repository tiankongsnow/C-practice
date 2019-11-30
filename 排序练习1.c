/* bubble sort */
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

    int j=0;
    while (j < 25){
        arr[j] = (rand() % 51) + 150;  //150~200
        if (check[arr[j]-150] == 0){
            check[arr[j]-150] = 1;
            j++;
        }
    }
    printf("randon numbers is:\n");
    for(i = 0; i < 25; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("\n");

    bubble(arr, 25);
    printf("sorting numbers is:\n");
    for(i = 0; i < 25; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("\n");

    while(k < 25){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                new_arr[i][j] = arr[k];
                k++;
            }
        }
    }

    printf("gratuation:\n");
    for(i = 4; i >= 0; i--){
        for(j = 4; j >= 0; j--){
            printf("%d ", new_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void bubble(int arr[], int n){
    int i , j;
    int temp;
    for(i=0; i<n-1; i++){
        //每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
        for(j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){   //小到大排序
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
