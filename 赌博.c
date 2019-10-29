/* compare 2019/10/21 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    /*player's card, computer's card*/
    int player, computer, playerpoint=0, computerpoint=0;
    int card_num[39];     // card number
    int check[39] = {0};  // record the card used

    int i=0;
    while (i < 39){
        card_num[i] = rand() % 39; //0~38 一共39个数
        /* i =0时，假设 card_num[0] =10，check[10] = 0，然后check[10] = 1，
        纪录10这个码已经取过，当下一个数再取到10时，check[10] ！= 0，
        所以不再进入if循环，并且以此类推*/
        if (check[card_num[i]]==0){
            check[card_num[i]]=1;
            i++;
        }
     }


        /*display computer's card*/
        printf("computer's card:  ");
        for(i=0;i<3;i++){
            computer=card_num[i];
            switch(computer / 13){
            case 0: printf("Diamond ");// 0~12都为Diamond;
                    break;
            case 1: printf("Heart ");// 13~25都为Heart;
                    break;
            default: printf("Spade "); //剩下的都为Spade;26~38
            }
            switch(computer % 13){
            case 0: printf("A  "); break; //0, 13, 26 ,C语言里面0除以非0数余数为0,实际上是不存在余数的,
            case 10: printf("J  "); break;//10, 23, 36
            case 11: printf("Q  "); break;//11, 24, 37
            case 12: printf("K  "); break;//12, 25, 38
            default: printf("%d  ",computer % 13 + 1);//remember +1
            }
            /*compute the point*/
            switch(computer / 13){
            case 0: computer=computer%13+1;
                    break;
            case 1: computer=(computer%13+1)*2;
                    break;
            default: computer=(computer%13+1)*3;
            }
            computerpoint=computerpoint+computer;

        }
        printf("\ncomputer point is : %d\n",computerpoint);

        /*display player's card*/
        printf("player's card:    ");
        for(i=3;i<6;i++){
            player=card_num[i];
            switch(player / 13){
            case 0: printf("Diamond ");
                    break;
            case 1: printf("Heart ");
                    break;
            default: printf("Spade ");
            }
            switch(player % 13){
            case 0: printf("A  "); break;
            case 10: printf("J  "); break;
            case 11: printf("Q  "); break;
            case 12: printf("K  "); break;
            default: printf("%d  ",player % 13 + 1);//remember +1
            }
            /*compute the point*/
            switch(player / 13){
            case 0: player=player%13+1;
                    break;
            case 1: player=(player%13+1)*2;
                    break;
            default: player=(player%13+1)*3;
            }

            playerpoint=playerpoint+player;

        }
        printf("\nplayer point is :   %d\n",playerpoint);


        /*calculate winner*/
        if(computerpoint==playerpoint){
            printf("tie!\n");
        }
        else{
            if(computerpoint>playerpoint)
                printf("computer win!\n");
            else
                printf("player win!\n");
        }


    return 0;
}


