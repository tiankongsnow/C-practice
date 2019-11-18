/*find two num, the prime factors, GCD(greast common divisor) and LCM(lowest common multiple)，质因子， 最大公约数， 最小公倍数 */
#include<stdio.h>
#include<stdlib.h>

/*return 1 if it's a prime; return 0 if it's not a prime, 判断质数，除了1和本身外不能被其他小于本身的数整除*/
int is_Prime(int);   
/* find all prime factors of a number */   
void Prime_Factor(int); 
/* find the Greatest Common Divisor of 2 numbers*/
int GCD(int, int);   
/*find the Least Common Multiple of 2 numbers   */ 
int LCM(int, int);       

int main(){
    int num1, num2;
    while(scanf("%d %d", &num1, &num2) != EOF){
        if(is_Prime(num1)){
            printf("%d is a prime!\n", num1);
        }
        else{        //not prime
            printf("prime factorization of %d: ",num1);
            Prime_Factor(num1);        //prime factorization，质因子
        }
        if(is_Prime(num2)){
            printf("%d is a prime!\n", num2);
        }
        else{      //not prime
            printf("prime factorization of %d: ",num2);
            Prime_Factor(num2);       //prime factorization，质因子
        }
        printf("GCD: %d\nLCM: %d\n", GCD(num1,num2), LCM(num1, num2));
    }
    system("pause");
    return 0;
}
/*return 1 if it's a prime; return 0 if it's not a prime, 判断质数，除了1和本身外不能被其他小于本身的数整除*/
int is_Prime(int num){  
    
    int i;
    for(i = num - 1; i >= 2; i--){
        if(num % i == 0){
             return 0;
        }
    }
    return 1;
}
/* find all prime factors of a number */ 
void Prime_Factor(int num){ 

    int i;
    int count = 1;             //count the times of printing

    for(i = 2; i <= num; i++){
        if(is_Prime(i)){           //The divisor is a prime.
            while(num % i == 0) {   //The number can be divided by a prime.
                if(count != 1){
                    printf(" x %d", i);
                }
                else {
                    printf("%d", i);
                }
                count++;
                num = num / i;
            }
        }
    }
    printf("\n");
    return;
}
/*find the Greatest Common Divisor of 2 numbers, GCD最大公约数*/
int GCD(int num1, int num2){       
    
    while(num1 > 0 && num2 > 0){
        if(num1 > num2) {
            num1 = num1 % num2; //num1 > num2, divide num1 by num2 and get the remainder
        }
        else {
            num2 = num2 % num1; //num2 > num1, divide num1 by num2 and get the remainder
        }
    }
    if(num1 == 0){
        return num2;       //num2 is the GCD
    }
    else{
        return num1;       //num1 is the GCD
    }
}
/*find the Least Common Multiple of 2 numbers, 最小公倍数*/
int LCM(int num1, int num2){       
    return (num1 * num2) / GCD(num1, num2);
}
