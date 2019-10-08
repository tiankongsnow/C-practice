#include <stdio.h>
#include <string.h>
int main()
{   //int num;
    char str[150];
    int i;
    while(scanf("%s", str) != EOF) {
        //sprintf(str,"%d",num);
        int len = strlen(str); 
        for(i=len-1;i>=0;i--) {
            printf("%c",str[i]); 
        }
        printf("\n");
    }
}
