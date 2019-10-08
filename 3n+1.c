#include<stdio.h>
int GetCycleLength(int n)
{
    int cycle_length= 1;
    while(n!=1){
      n=(n%2)?3*n+1:n/2;
      cycle_length++;
    }
    return cycle_length;
}
 
int main()
{
    int i, j, saveI, saveJ;
    int cycle_length;
    int cycle_length1= 0;
    while(scanf("%d %d",&i,&j) != EOF){
        if(i== 0 && j== 0){
            break;
        }
        else{ 
            cycle_length= 0;
            saveI= i;
            saveJ= j;
        if(i<j){
            for(;i<=j;i++)
            {
                cycle_length1=GetCycleLength(i);
                if(cycle_length<cycle_length1){
                    cycle_length=cycle_length1;
                } 
            }
        } 
                else{
                    for(;j<=i;j++){
                        cycle_length1=GetCycleLength(j);
                            if(cycle_length<cycle_length1){
                                cycle_length=cycle_length1;
                            }
                    }
                }
                    printf("%d %d %d\n",saveI,saveJ,cycle_length);
        } 
    } 
}
