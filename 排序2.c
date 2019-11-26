/*选择排序 Selection Sort */
#include<stdio.h>
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
int main(){
    int i;
    int len;
    printf("input the len of arr:");
    scanf("%d", &len);
    int arr[len];
    for(i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    SelectionSort(arr, len);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
