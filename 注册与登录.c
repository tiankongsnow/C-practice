/*account signup/login*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*the function that user choose*/
    int choose = 0;
    char account[50], password[50];
    while(choose != 3)
    {
        printf("What function do you want to use?\n");
        printf("1.Register\n");
        printf("2.Sign in\n");
        printf("3.Quit\n");
        printf("Your choose:");
        scanf("%d",&choose);
        printf("\n");

        /*identify what function is selected*/
        switch(choose){
        case 1:
            printf("New account:");
            scanf("%s",account);
            printf("New password:");
            scanf("%s",password);

            FILE *inp = fopen("sql.txt","a"); //a独自产生文件 ,可以接着输入不覆盖, w会覆盖 , r 前提是已经建立好文件
            int state = 0;
            char sql_account[50], sql_password[50];
            while(fscanf(inp,"%s%s",sql_account, sql_password)!=EOF){
                if(strcmp(sql_account, account) == 0){
                    state = 1;
                }
            }

            fclose(inp);
            if(state == 1){//if the data exist
                printf("\nRepetition\n");//重复的
            }
            else{
                printf("\nOK\n");
                FILE *oup = fopen("sql.txt","a");//输入的与之前的账号都不相同，就打开文件又存进新账号
                fprintf(oup,"%s\t\t%s\n",account, password);
                fclose(oup);
            }
            break;
        case 2:
            printf("Your account:");
            scanf("%s",account);
            printf("Your password:");
            scanf("%s",password);
            FILE *inp2 = fopen("sql.txt","r");
            char sql_account2[50], sql_password2[50];
            int state2 = 0;

            while(fscanf(inp2,"%s%s",sql_account2,sql_password2)!=EOF){
                if(strcmp(sql_account2,account) == 0 && strcmp(sql_password2,password) == 0){
                    state2 = 1;
                }
            }
            fclose(inp2);
            if(state2 == 1){//if the data exist
                printf("\nPass\n");
            }
            else{
                printf("\nFail\n");
            }
            break;
        case 3:
            break;
        default:
            printf("input wrong\n");
        }
        printf("\n");
    }
    return 0;
}
