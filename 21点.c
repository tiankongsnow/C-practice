/* 21 points game 2019/10/10 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    /*player's card, computer's card*/
    int player, computer;
    /*player's score, computer's score*/
    int player_point = 0, com_point = 0;
    int round;            // how many rounds from beginning
    int choose;           // player's choice to decide continue or end
    int card_num[52];     // card number
    int check[52] = {0};  // record the card used

    int i=0;
    while (i < 52){   //不可以抽到相同的牌
        card_num[i] = rand() % 52;
        if (check[card_num[i]]==0){
            check[card_num[i]]=1;
            i++;
        }
     }

    for(round = 1;;round++){
        printf("Round %d\n",round);
        /*give player & computer card*/
        computer=card_num[(round-1)*2];
        player=card_num[(round-1)*2+1];

        /*display computer's card*/
        printf("computer's card:\t");
        switch(computer / 13){
        case 0: printf("Spade "); break;
        case 1: printf("Club "); break;
        case 2: printf("Heart "); break;
        default: printf("Diamond ");
        }
        switch(computer % 13){
        case 0: printf("A\n"); break;
        case 10: printf("J\n"); break;
        case 11: printf("Q\n"); break;
        case 12: printf("K\n"); break;
        default: printf("%d\n",computer % 13 + 1);//remember +1
        }

        /*display player's card*/
        printf("player's card:\t\t");
        switch(player / 13){
        case 0: printf("Spade "); break;
        case 1: printf("Club "); break;
        case 2: printf("Heart "); break;
        default: printf("Diamond ");
        }
        switch(player % 13){
        case 0: printf("A\n"); break;
        case 10: printf("J\n"); break;
        case 11: printf("Q\n"); break;
        case 12: printf("K\n"); break;
        default: printf("%d\n",player % 13 + 1);//remember +1
        }

        /*calculate computer point*/
        if(computer % 13 > 9){//JQK = 10 points

            com_point += 10;
        }
        else{
            com_point += computer %13 + 1;//remember +1
        }

        /*calculate player point*/
        if(player % 13 > 9){//JQK = 10 points
            player_point += 10;
        }
        else{
            player_point += player % 13 + 1;//remember +1
        }

        printf("computer's point:\t%d\n",com_point);
        printf("player's point:\t\t%d\n\n",player_point);

        /*more than 21 points*/
        if(player_point > 21){
            printf("computer win\n");
            return 0;
        }
        else if(com_point > 21){
            printf("player win\n");
            return 0;
        }

        /*get input by user. 1 = continue, 2 = end*/
        printf("Does player want to continue?(1/2):");
        scanf("%d",&choose);

        if(choose == 2){
            /*decide who is winner*/
            if(player_point > com_point){
                printf("player win\n");
            }
            else if(player_point < com_point){
                printf("computer win\n");
            }
            else{
                printf("tie\n");
            }
            break;//leave the for loop
        }
        printf("\n");
    }
    return 0;
}


