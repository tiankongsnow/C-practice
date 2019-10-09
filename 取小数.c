/*定义头文件函数*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum,answer1,answer2,answer3;//save the number behind the dot
    float num_f;//the number let user input
    printf("Input decimal:");
    scanf("%f",&num_f);

    //get the number behind the dot
    answer1 = (int)(num_f * 10) % 10;
    answer2 = (int)(num_f * 100) % 10;
    answer3 = (int)(num_f * 1000) % 10;
    sum = answer1 + answer2 + answer3;

    //it can be replaced by the next line
    //sum = ((int)(num_f * 10)) % 10 + ((int)(num_f * 100)) % 10 + ((int)(num_f * 1000)) % 10;

    printf("Add three decimals:%d\n",sum);

    //if the number is multiple of 3
    if(sum % 3 == 0)
    {
        printf("Is three's multiple\n");
    }
    else
    {
        printf("Is not three's multiple\n");
    }
    system("pause");
    return 0;
}
