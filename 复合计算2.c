#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<math.h>
 
int main()
{
    int n;//先输入数组长度再依次输入数组元素
    int i,j;
    scanf("%d",&n);
    int sum[n];
    float avgScore1[n];
    float avgScore[n];
    //int length;
    typedef struct arr ar;
    struct arr{
        char x[40];
        int y;
        int z;
    };
    ar *space;
    space = (ar*)malloc(n * sizeof(ar));
    for (i=0; i<n; i++){
        scanf("%s", space[i].x);
        scanf("%d", &space[i].y);
        scanf("%d", &space[i].z);
    }
 
    for(i=0; i<n; i++){
        sum[i] = space[i].y + space[i].z;
        //printf("%d\n", sum[i]);
        avgScore1[i] = (float)sum[i]/2;
        //printf("%.2f\n", avgScore1[i]);
        avgScore[i] = (int)((avgScore1[i] * 100) + 0.5) / 100.0;
        //printf("%.2f\n", avgScore[i]);
    }
    
    float temp;
    char tempX[40];
    int tempY;
    int tempZ;
 
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(avgScore[j] > avgScore[j+1]){
                temp = avgScore[j];
                avgScore[j] = avgScore[j+1];
                avgScore[j+1] = temp;
 
                strcpy(tempX, space[j].x);
                strcpy(space[j].x, space[j+1].x);
                strcpy(space[j+1].x, tempX);
                
                
                //tempX = space[j].x;
                //space[j].x = space[j+1].x;
                //space[j+1].x = tempX;
 
                tempY = space[j].y;
                space[j].y = space[j+1].y;
                space[j+1].y = tempY;
 
                tempZ = space[j].z;
                space[j].z = space[j+1].z;
                space[j+1].z = tempZ;
            }
        }
    }
    //length = sizeof(space[i].x);
    //for (i = 0; i < length; i++){
	//	printf("%c", space[i].x);
    //}
    for(i=0; i<n; i++){
        printf("%s %d %d %.2f\n", space[i].x, space[i].y, space[i].z, avgScore[i]);
    }
        return 0;
}
