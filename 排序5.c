/*快速排序 Quick Sort*/
#include<stdio.h>

void QuickSort(int arr[], int maxlen, int begin, int end){  
    int i, j;  
    if (begin < end){  
        i = begin + 1;  
        j = end;        
        while (i < j){  
            if(arr[i] > arr[begin]){  
                swap(&arr[i], &arr[j]); 
                j--;  
            } 
            else{  
                i++; 
            }  
        }  
        if(arr[i] >= arr[begin]){  
            i--;  
        }  
        swap(&arr[begin], &arr[i]);      
        QuickSort(arr, maxlen, begin, i);  
        QuickSort(arr, maxlen, j, end);  
    }  
}  
 
void swap(int *a, int *b)    
{  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
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
    QuickSort(arr, len, 0, len-1);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
