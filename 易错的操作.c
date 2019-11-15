/*输入N，然后输入N个整数，无论正负，找最大，最小，平均*/
#include<stdio.h>
int main(){
    int N;
    int i;
    long avg;
    long sum = 0;
    long min = 999999999999;
    long max = -999999999999;
    while(scanf("%d", &N) != EOF){
        if(N > 100 || N<=0){
            break;
        }
        long num[N];
        
        for(i = 0; i < N; i++){
            scanf("%ld", &num[i]);
        }
        for(i = 0; i < N; i++){
            if(min > num[i]){
                min = num[i];
            }
            sum+=num[i];
        }
        for(i = 0; i < N; i++){
            if(max < num[i]){
                max = num[i];
            }
        }
        avg = sum/N;
        printf("max value = %ld\n", max);
        printf("min value = %ld\n", min);
        printf("average value = %ld\n", avg);
        //记得复位进行下一轮比较
        sum = 0;  
        min = 999999999999;
        max = -999999999999;
    }
    
}
