/* 10.5 points game 2019/10/30 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    /*player's card, computer's card*/
    int player, computer;
    /*player's score, computer's score*/
    float player_point = 0, com_point = 0;
    int round;            // how many rounds from beginning
    int choose;           // player's choice to decide continue or end
    int card_num[52];     // card number
    int check[52] = {0};  // record the card used

    int i=0;
    while (i < 52)
    {
        card_num[i] = rand() % 52;//0~51 一共52个数
        /* i =0时，假设 card_num[0] =10，check[10] = 0，然后check[10] = 1，
        纪录10这个码已经取过，当下一个数再取到10时，check[10] ！= 0，
        所以不再进入if循环，并且以此类推*/
        if (check[card_num[i]]==0)
        {
            check[card_num[i]]=1;
            i++;
        }
     }

    for(round = 1;;round++)
    {
        printf("Round %d\n",round);
        /*give player & computer card*/
        computer=card_num[(round-1)*2]; //依次发牌 第0 2 4张
        player=card_num[(round-1)*2+1];//第1 3 5张

        /*display computer's card*/
        printf("computer's card:\t");
        switch(computer / 13)
        {
        case 0: printf("Diamond "); break;// 方块  0~12都为Diamond;
        case 1: printf("Club "); break;// 梅花 13~25都为梅花;
        case 2: printf("Heart "); break;// 红心 26~38都为红心
        default: printf("Spade ");// 黑桃 39~51都为黑桃
        }
        switch(computer % 13)
        {
        case 0: printf("A\n"); break;
        case 10: printf("J\n"); break;
        case 11: printf("Q\n"); break;
        case 12: printf("K\n"); break;
        default: printf("%d\n",computer % 13 + 1);//remember +1
        }

        /*display player's card*/
        printf("player's card:\t\t");
        switch(player / 13)
        {
        case 0: printf("Diamond "); break;// 方块  0~12都为Diamond;
        case 1: printf("Club "); break;// 梅花 13~25都为梅花;
        case 2: printf("Heart "); break;// 红心 26~38都为红心
        default: printf("Spade ");// 黑桃 39~51都为黑桃
        }
        switch(player % 13)
        {
        case 0: printf("A\n"); break;
        case 10: printf("J\n"); break;
        case 11: printf("Q\n"); break;
        case 12: printf("K\n"); break;
        default: printf("%d\n",player % 13 + 1);//remember +1
        }

        /*calculate computer point*/
        if(computer % 13 > 9)//JQK = 0.5 points
        {
            com_point += 0.5;
        }
        else
        {
            com_point += computer %13 + 1;//remember +1
        }

        /*calculate player point*/
        if(player % 13 > 9)//JQK = 0.5 points
        {
            player_point += 0.5;
        }
        else
        {
            player_point += player % 13 + 1;//remember +1
        }

        printf("computer's point:\t%.1f\n",com_point);
        printf("player's point:\t\t%.1f\n\n",player_point);

        /*more than 21 points*/
        if(player_point > 10.5)
        {
            printf("computer win\n");
            return 0;
        }
        else if(com_point > 10.5)
        {
            printf("player win\n");
            return 0;
        }
        if(player_point < 7 || com_point < 7)
        {
            choose=1;
        }
        else
        {
        /*get input by user. 1 = continue, 2 = end*/
            printf("Does player want to continue?(1/2):");
            scanf("%d",&choose);
        }

        if(choose == 2)
        {
            /*decide who is winner*/
            if(player_point > com_point)
            {
                printf("player win\n");
            }
            else if(player_point < com_point)
            {
                printf("computer win\n");
            }
            else
                printf("tie\n");
            break;//leave the for loop
        }
        printf("\n");
    }
    return 0;
}


