#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE *input;//定义输入的文件
FILE *output;//定义输出的文件
void CaculateWeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
    switch(iWeek)
    {       
    case 0: fprintf(output, "星期一\n"); break;
    case 1: fprintf(output, "星期二\n"); break;
    case 2: fprintf(output, "星期三\n"); break;
    case 3: fprintf(output, "星期四\n"); break;
    case 4: fprintf(output, "星期五\n"); break;
    case 5: fprintf(output, "星期六\n"); break;
    case 6: fprintf(output, "星期日\n"); break;
    }
}
int main(){

    int year;
    int month;
    int day;
    int sum;
    int leap;
    input = fopen("data.txt","r");
    output = fopen("result.txt", "w");
    fscanf(input,"%d" "%d" "%d", &year, &month, &day);

    switch(month){
    case 1: sum = 0; break;
    case 2: sum = 31; break;
    case 3: sum = 59; break;
    case 4: sum = 90; break;
    case 5: sum = 120; break;
    case 6: sum = 151; break;
    case 7: sum = 181; break;
    case 8: sum = 212; break;
    case 9: sum = 243; break;
    case 10: sum = 273; break;
    case 11: sum = 304; break;
    case 12: sum = 334; break;
    default: fprintf(output,"error\n");
    }
    sum+=day;

    if(year % 400==0 ||(year % 4 == 0 && year % 100 != 0)){
        leap = 1;
    }
    else{
        leap = 0;
    }
    if(leap==1 && month > 2){
         sum++;
    }
    
    fprintf(output,"it is the %dth day", sum);
    CaculateWeekDay(year, month, day);

    fclose(input);
    fclose(output);
    return 0;


}
