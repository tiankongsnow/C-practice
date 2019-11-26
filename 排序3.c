/*插入排序 Insertion Sort 直接插入排序*/

#include<stdio.h>
int insert(int arr[], int n){   //从小到大排序
    int i;
    int j;
    int temp;
    for(i=1; i<n; i++){               //执行n-1趟插入
        temp=arr[i];                 //将要插入的数暂存到temp
        j=i-1;
        while(j>=0 && temp<arr[j]){   //找出temp的插入位置
            arr[j+1] = arr[j];
            j--;
        }                                           //将a[j]后移，再将j减1
        arr[j+1] = temp;                    //将temp插入到指定位置
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
    insert(arr, len);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
