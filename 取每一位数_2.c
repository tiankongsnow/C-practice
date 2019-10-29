/*be a hacker 2019/10/21*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,newcode;
    int status; //status of the data
    int i,j; //variable
    int num[7]={0};
    FILE *inp;
    /*read file*/
    inp = fopen("password.txt","r");
    status = fscanf(inp,"%d",&number);

    /*compute the new number*/
    while(status != EOF) //EOF or not
    {
        printf("original number : %d\n",number);
        newcode=0;
        j=1;
        for(i=0;i<7;i++)
        {
            num[i]=number%10;  //从后往前取数，如1234，先取4，3，2，1
            num[i]=num[i]+3;
            number=number/10;
            if(num[i]>9) // 进位运算
            {
                num[i]=num[i]-10;
            }
            newcode=newcode+num[i]*j;//每一位数组合起来
            j=j*10;
        }
        printf("changed number : %d\n\n",newcode);
        status = fscanf(inp,"%d",&number); //read next password

    }

    fclose(inp);
    system("pause");
    return 0;
}
