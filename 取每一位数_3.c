/*Comparison of size 2019/10/30*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number_1,number_2;
    //int status_1,status_2; //status of the data//方法2
    int i,j; //variable
    int num_1[3]={0};
    int num_2[3]={0};
    FILE *inp_1;
    FILE *inp_2; //建立档案
    /*read file*/
    inp_1 = fopen("Player1.txt","r"); //开档读档
    inp_2 = fopen("Player2.txt","r");

//    status_1= fscanf(inp_1,"%d",&number_1); //方法2
//    status_2 = fscanf(inp_2,"%d",&number_2);

    /*compute the new number*/
    while((fscanf(inp_1,"%d",&number_1) )!= EOF && (fscanf(inp_2,"%d",&number_2))!=EOF) //EOF or not  方法1
    {

        printf("Player1 number : %d\n", number_1);
        printf("Player2 number : %d\n", number_2);
        j=0;
            for(i=0;i<3;i++)
            {
               num_1[i]=number_1%10; //取余数 123 先取3
               num_2[i]=number_2%10;
               if(num_1[i]>num_2[i])
               {
                   j++; //player数大就+1
               }
               else if(num_1[i]<num_2[i])
               {
                   j--; //player数小就-1
               }
               else
               {
                   j=j; //player数等于就不变
               }
               number_1=number_1/10;// 取下一位余数 123/10=12 继续循环取余数
               number_2=number_2/10;
             }
            switch(j)
            {
                case -3: printf("Lose three\n\n"); break;
                case -2: printf("Lose two\n\n"); break;
                case -1: printf("Lose one\n\n"); break;
                case  0: printf("Tie\n\n"); break;
                case  1: printf("Win one\n\n"); break;
                case  2: printf("Win two\n\n"); break;
                case  3: printf("Win three\n\n"); break;
                default: printf("****\n\n"); break;

            }
//        status_1 = fscanf(inp_1,"%d",&number_1); //read next password
//        status_2 = fscanf(inp_2,"%d",&number_2); //read next password //方法2
    }

    fclose(inp_1);
    fclose(inp_2);
}
