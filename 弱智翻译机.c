#include        <stdio.h>
#include        <stdlib.h>
#include        <string.h>
 
void main()
{
        char input[150];
        while(scanf("%s", input) != EOF) {
              if(strcmp("cat", input) == 0) {
                printf("貓\n");
              }
              else if(strcmp("dog", input) == 0){
                printf("狗\n");
              }
              else if(strcmp("banana", input) == 0){
                printf("香蕉\n");
              }
              else if(strcmp("pineapple", input) == 0){
                printf("鳳梨\n");
              }
              else if(strcmp("computer", input) == 0){
                printf("電腦\n");
              }
              else if(strcmp("key", input) == 0){
                printf("鑰匙\n");
              }
              else if(strcmp("code", input) == 0){
                printf("程式\n");
              }
              else if(strcmp("flunk", input) == 0){
                printf("當掉\n");
              }
              else if(strcmp("array", input) == 0){
                printf("陣列\n");
              }
              else {
                printf("這啥鬼?\n");
              }
        //printf("\t余文辉\t|\t0908641928\n");
        //printf("----------------------------------------\n");
        //printf("\tJohn\t|\t2720411\n");
        //printf("\tMary\t|\t2721008\n");
        }
}
