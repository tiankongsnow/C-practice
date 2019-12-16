/* ATM */
/* 初次使用会有一笔10000~50000元在卡内 */
/* 不是初次使用 会去读取money.txt中所剩的余额 */
/* 一开始会自动使用查询余额的功能，了解目前有多少钱 */
/* 每次功能选择完可以输入yes或no，判断要不要继续进行 */
/* 要把每次的操作纪录下来(除了查询余额)，并且将结果储存在money.txt中 */
/* 查询余额remaining，取钱withdraw，转账transfer，存钱deposit */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*write data to money.txt*/
void output(char mode[10], char str[30], int money, int sum);

int main(){
    int choose = 1;   
    int judge = 0;      
    int money;          // cost or save money
    int sum = 0;        // total money

    int status;
    int z, balance;      
    char x[10], y[10];   
    FILE *inp;
    inp = fopen("money.txt", "r");
    status = fscanf(inp, "%s %s %d %d", &x, &y, &z, &balance);

    char str[30] = {0};    // the result
    char select[5] = {0};  // the result

    printf("Is it the first time?   ");
    scanf("%d", &judge); //1是yes 0是no

    if(judge==1){
        FILE *oup = fopen("money.txt", "w");
        fprintf(oup, "Function\t\tNote\t\tMoney\t\tBalance\n");
        fclose(oup);
        /*10000~40000*/
        srand(time(NULL));
        sum = (rand() % 40001) + 10000;
    }
    else{
        while(fscanf(inp, "%s %s %d %d", &x, &y, &z, &balance) != EOF){
           status = fscanf(inp, "%s %s %d %d", &x, &y, &z, &balance);
        }
        sum = balance;
    }
    do{
        /*identify the function user input*/
        switch(choose){
        case 1:  //查询余额
            printf("Balance_money:%d\t", sum);
            printf("\nWhether continue to operate:");
            scanf("\n%s", &select);
            if(strcmp(select, "yes") == 0){

            }
            else if(strcmp(select, "no") == 0){
                 choose = 5;
            }
            break;
        case 2:  //取钱
            printf("Enter money:");
            scanf("%d", &money);
            printf("Note:");
            scanf("%s", &str);

            sum = sum - money;
            /*it has wrong*/
            if(sum < 0){
                printf("\nLacking remaining");
                break;
            }
            output("Withdraw",str,money,sum);

            printf("Whether continue operating:");
            scanf("\n%s",&select);
            if(strcmp(select, "yes") == 0){

            }
            else if(strcmp(select, "no") == 0){
                 choose=5;
            }
            break;
        case 3:  //转账
            printf("Enter money:");
            scanf("%d", &money);
            printf("Note:");
            scanf("%s", &str);

            sum = sum - money;
            /*it has wrong*/
            if(sum < 0){
                printf("\nLacking remaining");
                break;
            }
            output("Transfer", str, money, sum);

            printf("Whether continue operating:");
            scanf("\n%s",&select);
            if(strcmp(select, "yes") == 0){

            }
            else if(strcmp(select, "no") == 0){
                 choose = 5;
            }
            break;
        case 4:  //存钱
            printf("Enter money:");
            scanf("%d", &money);
            printf("Note:");
            scanf("%s", &str);

            sum = sum + money;
            output("Deposit", str, money, sum);

            printf("Whether continue operating:");
            scanf("\n%s", &select);
            if(strcmp(select, "yes") == 0){

            }
            else if(strcmp(select, "no") == 0){
                 choose = 5;
            }
            break;
        }
        printf("\n\n");
        if(choose < 5){
        printf("What function do you want to use?\n");
        printf("1.Remaining\n");
        printf("2.Withdraw\n");
        printf("3.Transfer\n");
        printf("4.Deposit\n");
        printf("Your choose:");
        scanf("%d", &choose);
        printf("\n");
        }
        if(choose > 4){
           printf("Wrong input");
        }
    }while(choose < 5);
    return 0;
}

void output(char mode[10], char str[30], int money, int sum){
    FILE *oup = fopen("money.txt", "a");
    fprintf(oup,"%s\t\t%s\t\t%d\t\t%d\n", mode, str, money, sum);
    fclose(oup);
}

