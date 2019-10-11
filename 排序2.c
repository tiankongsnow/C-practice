#include<stdio.h>
int selection(int arr[], int n){
    int i, j, temp;
    int min = 9999;
    int index;//位置下标
    for(i=0;i<n;i++){
        index =i;
        min = arr[i];    //最小值
        for(j=i; j<n; j++){
            if(min>arr[j]){
                index = j;    //找最小值
                min = arr[j];
            }
        }
        if(index != i){
            temp = arr[i];
            arr[i]=arr[index];
            arr[index] = temp;//从小到大
        }
    }
    return 0;
}

int main(){
    int i;
    int len;
    printf("输入数组长度:");
    scanf("%d", &len);
    int arr[len] ;
    for(i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    selection(arr, len);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
