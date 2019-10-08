#include<stdio.h>
float sqr(float m, float r){
    float mid = m / 2;
    float min, max;
    min = 0;
    max = m;
    while ((mid*mid - m > r) ||(mid*mid - m < -r)){
        if (mid*mid<m){
            min = mid;
        }    
        else if (mid*mid>m){
            max = mid;
        }
        else{
            return mid;
        }
            mid = (min + max)/2;
            //printf("%f", mid); 
    }
    return mid;
}
 
int main()
{
    int n;//先输入数组长度再依次输入数组元素
    int i, j;
    int temp1, temp2;
    scanf("%d",&n);
    int arr[n];
    float avgScore1;
    float avgScore;
    int sum = 0;
    float variation1=0;
    float variation2=0;
    float variation=0;
    float standardDeviatio;
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int maxScore=arr[0];
    int minScore=arr[0];
    for(i=0;i<n;i++){
        if(maxScore < arr[i]){
            maxScore = arr[i];
        }
        if(minScore > arr[i]){
            minScore = arr[i];
        }
        sum+=arr[i];
    }
 
    avgScore1 = (float)sum/n;
    for(i=0;i<n;i++){
    variation1+=((arr[i]-avgScore1)*(arr[i]-avgScore1));
    }
    variation2=(float)variation1/n;
    variation= (int)((variation2 * 100) + 0.5) / 100.0;
    avgScore = (int)((avgScore1 * 100) + 0.5) / 100.0;
    printf("maxScore=%d\n", maxScore);
    printf("minScore=%d\n", minScore);
    //printf("sum= %d\n", sum);
    //printf("avgscore1= %.2f\n", avgScore1);
    //printf("variation1=%.2f\n",variation1);
    printf("avgScore=%.2f\n",avgScore);
    printf("variation=%.2f\n",variation);
    //调用函数,算标准差
    standardDeviatio = sqr(variation, 0.001);
    printf("standard deviatio=%.2f\n", standardDeviatio);
   //冒泡排序算法：进行 n-1 轮比较
    for(i=0; i<n-1; i++){
        //每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
        for(j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp1 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp1;
            }
        }
    }
    printf("Min to Max=");
    for(j=0; j<n; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(arr[j] < arr[j+1]){
                temp2 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp2;
            }
        }
    }
    printf("Max to Min=");
    for(j=0; j<n; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");
}
