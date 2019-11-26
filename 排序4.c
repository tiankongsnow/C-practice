/*希尔排序 Shell Sort 简单插入排序的改进版 缩小增量排序*/
#include<stdio.h>

void ShellSort(int arr[], int size){ 

    int i, j, tmp, increment;  
    for(increment = size/ 2; increment > 0; increment /= 2) {    
        for(i = increment; i < size; i++) {  
            tmp = arr[i];  
            j = i - increment; 
            while(j >= 0 && tmp < arr[j]) {  
                arr[j + increment] = arr[j];
                j -= increment; 
            }  
            arr[j + increment] = tmp;
        }  
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
    ShellSort(arr, len);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
