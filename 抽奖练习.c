/*歡樂四星彩*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    /*random, input by player*/
    int randomNum , guess ,i ;
    /*computer number*/
    int one,two,three,four;
    /*the number player guess*/
    int guess_One,guess_two,guess_three,guess_four;
    /*remember of A & B*/
    int A = 0 , B = 0 ;

    /*gene random number*/
    randomNum = ( rand()%9000 ) +1000 ;

    //printf(" insert a number between 1000 ~ 9999 : ");
    printf("the number is: %d\n",randomNum);
    printf("your number:");
    scanf("%d",&guess);


    /*avoid wrong*/
    if ( ( guess < 1000 ) || ( guess > 9999) )
    {
        printf(" wrong number . The number is0 between 1000 ~ 9999\n");
        return 0 ;
    }

    /* separate computer's number for compare number */
    one = randomNum / 1000 ;
    two = ( randomNum % 1000 ) / 100 ;
    three = ( randomNum % 100  ) / 10  ;
    four  = randomNum % 10 ;
   // printf("\n random value = %d%d%d%d\n",one,two,three,four);

    /* separate user's number for compare number */
    guess_One = guess / 1000 ;
    guess_two = ( guess % 1000 ) / 100 ;
    guess_three = ( guess % 100  ) / 10  ;
    guess_four  = guess % 10 ;
    //printf(" user's value = %d%d%d%d\n",guess_One,guess_two,guess_three,guess_four);

    /* compare number */
    if ( guess_One == one ){
        A++;
    }
    else if( guess_One == two || guess_One == three || guess_One == four){
        A=A;
    }
    else{
        B++;
    }

    if ( guess_two == two ){
        A++;
    }
    else if( guess_two == one || guess_two == three || guess_two == four){
        A=A;
    }
    else{
       B++;
    }

    if ( guess_three == three ){
        A++;
    }
    else if( guess_three == one || guess_three == two || guess_three == four){
        A=A;
    }
    else{
       B++;
    }

    if ( guess_four == four ){
       A++;
    }
    else if( guess_four == one || guess_four == two || guess_four == three){
       A=A;
    }
    else{
       B++;
    }

    /*output the result*/
    if(A == 4){
        printf("恭喜中大獎\n");
    }
    else if(A == 3){
        printf("恭喜中貳獎\n");
    }
    else if(B == 4){
        printf("恭喜中特別獎\n");
    }
    else{
        printf("沒中獎\n");
    }

    system("pause");
    return 0;
}
