#include <stdio.h>

int main (){
    int a[10], c=0;
    int i, j, n[10];
    FILE * input;
    input = fopen("random.txt","r");// 10个数存在一个.txt里面
    for(i = 0; i<10; i++){
        fscanf(input, "%d", &a[i]);
    }

    for (i=0; i<10; i++){
        n[i]=0;
    }

    for (j=0; j <10; j++){
        for (i=2; i<a[j]-1; i++){
            if (a[j] % i == 0){
                n[j]++; //不是质数就加一;
                //printf("%d\n", a[j]);
                break;
            }
        }
    }
    int max, min;
    min = 1500;
    max = 0;
    printf ("prime number ");
    for (j=0; j<10; j++){
        if (n[j]==0){
            c++;
            printf ("%d ",a[j]);
            if (max < a[j]){
                max = a[j];
            }

            if (min>a[j]){
                min = a[j];
            }
        }
    }
    printf ("\n");
    printf ("max %d\n",max);
    printf ("min %d\n",min);
    printf ("total %d\n",c);
    return 0;
}
