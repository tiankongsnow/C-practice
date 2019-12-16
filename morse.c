/* Morse_Code */
/* 一开始可以直接输入一组暗号，并且解读出暗号的秘密 */
/* 输入都是大写字母和数字 */
/* 输入不超过10位 */
/* 若英文字母往后移动超出范围，则从头计算(如 Z 后移 2 则变为 B) */
/* 解开暗号后可以自行输入1继续、0结束 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*calculate Morse_Code*/
void output(char str[10]);

int main(){
    int choose = 0;
    char str[10];
    do{
        printf("Input:  ");
        scanf("%s", &str);
        output(str);
        printf("\n");

        printf("How many set of passwords do you want: ");//需要执行多少次，最多三次
        scanf("%d", &choose);
        printf("\n");

        switch(choose){
        case 1:
            printf("Input:  ");
            scanf("%s", &str);
            output(str);
            choose = 4; //为了跳出循环
            break;
        case 2:
            printf("Input:  ");
            scanf("%s", &str);
            output(str);
            printf("\n\nInput:  ");
            scanf("%s", &str);
            output(str);
            choose = 4; //为了跳出循环
            break;
        case 3:
            printf("Input:  ");
            scanf("%s", &str);
            output(str);
            printf("\n\nInput:  ");
            scanf("%s", &str);
            output(str);
            printf("\n\nInput:  ");
            scanf("%s", &str);
            output(str);
            choose = 4; //为了跳出循环
            break;
        default:
            printf("Too greedying");
            choose = 4;
        }
    }while(choose < 3);

    printf("\n");
    return 0;
}

void output(char str[10]){
    int i;        
    int k = 0;      //数字前面有几个英文
    int j = 0;      //几个英文被翻译
    int length; 

    char ASCII[10] = {0};          //存放ASCII
    char Morse_Code[10] = {0};     //摩斯密码
    length = strlen(str);

    if(length <= 10){
        for(i=0; i<length; i++){  
            ASCII[i] = (int)str[i];  //输入密码转成ascill
            if(ASCII[i] >= 48 && ASCII[i] <= 57){ 0~9
                for(k; k>0; k--){
                    Morse_Code[j] = ASCII[i-k] + (ASCII[i] - 48);
                    /*超过Z的情况*/
                    if(Morse_Code[j] > 90){ //超过Z
                        Morse_Code[j] = Morse_Code[j] - 26;   //从A开始
                    }
                    j++;
                }
                k=0;
            }
            else if(ASCII[i] >= 65 && ASCII[i] <= 90){ A~Z
                k++;
            }
            else{
                printf("Input error!");
                j=-1;
                break;
            }
        }
        if(j >= 1){
            printf("Output: ");
            for(i=0; i<j; i++){
                printf("%c", Morse_Code[i]);  //印出Morse_Code
            }
        }
        if(j == 0){   //全部都是英文或全部都是数字
            printf("Unrecognizable!");
        }
    }
    else{
        printf("Too greedying");
    }
}
