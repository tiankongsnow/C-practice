#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_ITERA 100      //the maximum times of doing iterations 最多分割次数

double Func(double);                       //the function to solve
void auto_root_Range();                 //automatically find the range of the roots
double Bisection(double, double, double);  //Using Bisection Method to get the approximate root

int main(){
    double up, low, error;   //the interval and the permission error(user-defined)
    double answer;      //the root which found by Bisection Method

    auto_root_Range(); //估算有根的范围
    printf("\nPlease enter the interval and error (lower, upper, error):\n");
    scanf("%lf %lf %lf", &low, &up, &error);
    answer = Bisection(low, up, error); //返回的是最终估算的根
    printf("f(%f) = %.14f\n\n", answer, Func(answer));

    return 0;
}

double Func(double x){
    return (x*x*x + 1*x*x - 2*x - 1);                                                                                           //usable case: x*x*x - 5.48*x*x - 1.4883*x + 20.394828
}

void auto_root_Range(){  //估算有根的范围
    double x;
    printf("Equation: x^3+x^2-2x-1\n");
    for(x = -10000; x < 10000; x++){                 //range of double: -1E307~1E308 / -10^307 ~ 10^308
        if(Func(x)*Func(x+1) < 0)
            printf("There is at least one root in [%.0f,%.0f]\n", x, x+1);
    }
}

double Bisection(double low, double up, double error){
    double mid;         //midpoint
    int count = 0;      //count the times for doing iterations
    if(Func(up) * Func(low) > 0){               //not roots in the interval
        printf("There are no roots in interval [%.0f, %.0f]\n\n", low, up);
        return low;
    }
    else if(fabs(Func(up)) < error){ //取浮点的绝对值
        return up;         //up is the root
    } 
    else if(fabs(Func(low)) < error){
        return low;         //low is the root
    }    
    else{                   //do the iterations
        do{
            mid = 0.5 * (up + low);
            if(Func(up) * Func(mid) <= 0.0){
                low = mid;  //there is one root in [up, mid]
            }          
            else{
                up = mid;   //there is one root in [mid, low]  
            }                                   
            count++;
        }while(count < MAX_ITERA && fabs(Func(mid)) > error); //符合就一直执行 如果fabs(Func(mid)) < error 说明约等0，可以退出
    }      
    printf("\nDo %d times\n", count);
    return mid;
}
