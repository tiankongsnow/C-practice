/*graph password*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, j, k, l, array[3][3]={1,2,3,4,5,6,7,8,9};
    char str1[100], str2[100];
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
           printf("%4d", array[i][j]);
        }
        printf("\n\n");
    }

    printf("Please create a graph password:");
    scanf("%s", str1);
    printf("\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<strlen(str1); k++){
                if(array[i][j] == (str1[k]-'0')){
                   array[i][j] = 1;
                   break;
                }
            }
            if(k == strlen(str1)){
                array[i][j] = 0;
            }
            printf("%4d", array[i][j]);
        }
        printf("\n\n");
    }
    while(1){
        printf("Please login the graph password:");
        scanf("%s", str2);
        if(strcmp(str1, str2) == 0){
            printf("login!\n");
            break;
        }
        else{
            printf("wrong password!\n");
        }
    }
    return 0;
}
