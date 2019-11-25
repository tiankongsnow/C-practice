#include<stdio.h>
#include<math.h>
/*move function*/
void hannuota(int N, char A, char B, char C);
/*caculate times*/
void time(int M);
int num = 0;
int main(){

    char ch1 = 'A'; // three towers
    char ch2 = 'B';
    char ch3 = 'C';
    int n;  //disks number
    printf("please input the number of disks: ");
    scanf("%d", &n);

    hannuota(n, ch1, ch2, ch3);  //funtion
    time(n);
    system("pause");
    return 0;
}
/*move function*/
void hannuota(int N, char A, char B, char C){
    if(1 == N){
        printf("%d. put number %d disk from %c to %c\n",++num, N, A, C);
    }
    else{
        hannuota(N-1, A, C, B); //N-1个从A借助C移动到B ,N-1个就是除了最底层的剩下的
        printf("%d. put number %d disk from %c to %c\n",++num, N, A, C);//盘子序号N从上往下数1，2，3，4...
        hannuota(N-1, B, A, C);//本来放在B,然后借助A移动到C
    }
}
/*caculate times*/
void time(int M){
    printf("move %d times\n", (int)pow(2, M) - 1); //move times
}
