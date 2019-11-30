/* selection sort */
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

    SelectionSort(arr, 25);
    printf("sorting numbers is:\n");
    for(i = 0; i < 25; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("\n");
    /*save num*/
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
/*selection sort*/
void SelectionSort(int arr[], int size){
    int i, j, index, tmp;
    for(i = 0; i < size - 1; i++){
        index = i; //纪录下标
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[index]){
                index = j;
            }
        }
        tmp = arr[index];
        arr[index] = arr[i];
        arr[i] = tmp;
    }
}

