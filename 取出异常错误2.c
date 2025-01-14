#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char input[39]={0}, charwhere[20]={0}, errorchar[20]={0};
    int cnt=0, i=0, len=0, j=0, k=0, zerocnt=0;//cnt统计出现异常字符的次数, 如果没有则为0

    while(scanf("%s", input) != EOF){
        len = strlen(input);
        j = 1;
        for(i = 0;i < len-zerocnt; i++){
            if(input[i] == '0'){
                for(k = i; k < len-1; k++){
                    input[k] = input[k+1];
                }
                input[k] = '\0';
                zerocnt++;
                i--;
            }
            else{
                break;
            }
        }
        len = len-zerocnt;
        for(i = 0; i < len; i++){
            if((input[i] > 57 && input[i] <= 126) ){ //非数字的字符 
                charwhere[j] = i + 1 + cnt; //异常的位置纪录，从1开始 字母
                errorchar[j] = input[i]; //把异常字符存起来 字母
                cnt++; //纪录异常个数
                j++;
                for(k = i; k < len-1; k++){ //最终到最后一位的前一位赋值，所以len-1
                    input[k] = input[k+1]; //上面判断完一个字符这里就整体往前送，替换异常字符
                }
                input[len-1] = '\0';//原来的最后的位置给0
                i--; //i--之后回到for又加1，让循环从替换掉的字母位置开始
            }
            
        }
        /*无异常*/
        if(cnt == 0){
            printf("Parsing successfully: %s\n", input);
        }
        else{
            if(cnt == 1){
                printf("Panic: %d Error was detected.\n", cnt);
                printf("The input has following invalid character:\n");
                for(i = 1; i <= cnt; i++){
                    printf("[%d] Position: %d, Invalid character: %c\n", i, charwhere[i], errorchar[i]);
                }
                printf("Repaired result is %s.\n", input);
                printf("---\n");
            }
            else{
                printf("Panic: %d Errors were detected.\n", cnt);
                printf("The input has following invalid characters:\n");
                for(i=1; i <= cnt; i++){
                    printf("[%d] Position: %d, Invalid character: %c\n", i, charwhere[i], errorchar[i]);
                }
                printf("Repaired result is %s.\n", input);
                printf("---\n");
            }
        }
        /*复位*/
        for(i = 0; i < 20; i++){
            charwhere[i] = 0;
            errorchar[i] = 0;
        }
        cnt = 0;
    }

} 
