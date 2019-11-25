/*递归和常规方法找数组中最大值*/
#include<stdio.h>
#include<time.h>

int max(int arr[], int n){
    if (n >= 1){
        if (max(arr,n-1) < arr[n]){
            return arr[n];
        }
        else {
            return max(arr, n-1);
        }
    }
    else{
        return arr[n];
    }
}

int loop(int arr[], int n){
    int i;
    int max = arr[0];
    for(i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}
int main(){

    clock_t begin1, end1;
    clock_t begin2, end2;
    double cost1, cost2;

    int i;
    int n;
    int MAX1;
    int MAX2;
    /*input the number of arry*/
    scanf("%d", &n);
    int arr[n];

    /*input n number in arry*/
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    begin1 = clock();
    MAX1 = max(arr, n-1);
    printf("the max of recu way is %d\n", MAX1);
    end1 = clock();

    cost1 = (double)(end1 - begin1)/CLOCKS_PER_SEC;//计算运行时间
    printf("the running time of recu is %lf secs\n", cost1);


    begin2 = clock();
    MAX2 = loop(arr, n);
    printf("the max of loop way is %d\n", MAX2);
    end2 = clock();

    cost2 = (double)(end2 - begin2)/CLOCKS_PER_SEC;
    printf("the running time of loop is %lf secs\n", cost2);
}
