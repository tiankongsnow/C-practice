/*int 数组中数的相加*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
    clock_t begin1, end1;
    clock_t begin2, end2;
    double cost1, cost2;
    int i;
    int n;
    int sum;

    /*input the number of arry*/
    scanf("%d", &n);
    int arr[n];

    /*input n number in arry*/
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    begin1 = clock();
    sum = recu(arr, n-1);
    printf("sum of recu is %d\n", sum);
    end1 = clock();

    cost1 = (double)(end1 - begin1)/CLOCKS_PER_SEC;//计算运行时间
    printf("the running time of recu is %lf secs\n", cost1);

    begin2 = clock();
    loop(arr, n);
    end2 = clock();

    cost2 = (double)(end2 - begin2)/CLOCKS_PER_SEC;
    printf("the running time of loop is %lf secs\n", cost2);
    
}

void loop(int arr[], int n){
    int j;
    for(j = 0; j < n-1; j++){
        arr[j+1] = arr[j] + arr[j+1];
    }
    printf("sum of loop is %d\n", arr[n-1]);
}

int recu(int arr[], int n){
    if(n == 0){
        return arr[0];
    }
    else{
        return recu(arr, n-1) + arr[n];
    }
}
