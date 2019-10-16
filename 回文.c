#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool huiwen(char *c){
    int len=strlen(c);
    int left=0,right=len-1;
    while(left<=right){
        if(c[left]==c[right]){
            left++;
            right--;
        }
        else{
            break;
        }
    }
    if(left>right){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char c[1000];
    while(scanf("%s",c) != EOF){
        if(huiwen(c)){
            printf("This is a palindrome.\n");
        }
        else{
            printf("This is not a palindrome.\n");
        }
    }
}
