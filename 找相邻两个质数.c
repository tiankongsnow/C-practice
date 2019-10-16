#include<stdio.h>
int main(){

int num, x, y;
scanf("%d", &num);
x = num - 1;
y = num + 1;
int i = 2;

for (i = 2; i < x ; i++){
    if (x % i != 0){
        continue;
    }
    else{
        x--;
    }
}

for (i = 2; i < y ; i++){
    if (y % i != 0){
        continue;
    }
    else{
        y++;
    }
}
    printf("%d < %d < %d", x, num, y);
}
