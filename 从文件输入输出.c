#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //int *input;
    FILE *output;//定义output；
    //int R;
    //int T;
    output = fopen("card.txt","w");// output的位置
    int N;
    srand((unsigned)time(NULL));
    N = rand() % 50;
    //input = fopen("C:\\Users\\ASUS\\Desktop\\TEST1\\card.txt","r");

    switch(N / 13){
        case 0:
            fprintf(output,"C");
            break;
        case 1:
            fprintf(output,"D");
            break;
        case 2:
            fprintf(output,"H");
            break;
        case 3:
            printf(output,"S");
            break;
        default:
            fprintf(output,"ERROR\n");


    }
     switch(N % 13){
        case 0:
            fprintf(output,"A");
            break;
        case 9:
            fprintf(output,"T");
            break;
        case 10:
            fprintf(output,"J");
            break;
        case 11:
            fprintf(output,"Q");
            break;
        case 12:
            fprintf(output,"K");
            break;
        case 1:
            printf(output,"2");
            break;
        case 2:
            fprintf(output,"3");
            break;
        case 3:
            fprintf(output,"4");
            break;
        case 4:
            fprintf(output,"5");
            break;
        case 5:
            fprintf(output,"6");
            break;
        case 6:
            fprintf(output,"7\n");
            break;
        case 7:
            fprintf(output,"8\n");
            break;
        case 8:
            fprintf(output,"S\n");
            break;
        default:
            fprintf(output,"ERROR\n");

    }
    //fclose(output);
    return 0;
}
