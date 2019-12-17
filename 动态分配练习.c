#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define   m   100
#define   n   100

int main(){
    int i;
    char *a; //一维数组
    char *b[m]; //二维数组m*n(指针的数组)，已知第一维
    char *B[m]; //二维数组m*n(指针的数组)，已知第一维，一次分配内存(保证内存的连续性)
    char (*c)[m]; //二维数组m*n(指向数组的指针)，已知第二维
    char **d; //二维数组m*n，两维都未知
    char **D; //二维数组m*n，两维都未知，一次分配内存(保证内存的连续性)
    
    /*一维数组,动态分配空间*/
    a = (char*)malloc(sizeof(char) * m);
    printf("一维数组动态,分配空间\n");
    printf("sizeof(a) = %ld byte\n", sizeof(a));//8, 指针
    printf("sizeof(a[0]) = %ld byte\n", sizeof(a[0]));//1
    printf("\n");

    /*二维数组m*n,已知第一维,动态分配空间*/
    for(i=0; i<m; i++){
        b[i] = (char*)malloc(sizeof(char*) * n);
        //*(b + i) = (char*)malloc(sizeof(char*) * n);
    }
    printf("二维数组m*n,已知第一维,动态分配空间\n");
    printf("sizeof(b) = %ld byte\n", sizeof(b));//8*m，指针数组
    printf("sizeof(b[0]) = %ld byte\n", sizeof(b[0]));//8，指针
    printf("sizeof(b[0][0]) = %ld byte\n", sizeof(b[0][0]));//1
    printf("\n");

    /*二维数组m*n,已知第一维,一次动态分配内存(保证内存的连续性)*/
    B[0] = (char *)malloc(sizeof(char) * m * n);
    for(i=1; i<m; i++){
        B[i] = B[i-1] + n;
    }
    printf("二维数组m*n,已知第一维,一次动态分配内存(保证内存的连续性)\n");
    printf("sizeof(B) = %ld byte\n", sizeof(B));//8*m，指针数组
    printf("sizeof(B[0]) = %ld byte\n", sizeof(B[0]));//8，指针
    printf("sizeof(B[0][0]) = %ld byte\n", sizeof(B[0][0]));//1
    printf("\n");

    /*二维数组m*n,已知第二维,动态分配空间*/
    c = (char (*)[m])malloc(sizeof(char *) * n);
    printf("二维数组m*n,已知第二维,动态分配空间\n");
    printf("sizeof(c) = %ld byte\n", sizeof(c));//8, 指针
    printf("sizeof(c[0]) = %ld byte\n", sizeof(c[0]));//m, 一维数组
    printf("sizeof(c[0][0]) = %ld byte\n", sizeof(c[0][0]));//1
    printf("\n");

    /*二维数组m*n,两维都未知,动态分配空间*/
    d = (char **)malloc(sizeof(char *) * m);
    for(i=0; i<m; i++){
        d[i] = (char *)malloc(sizeof(char) * n);//分配每个指针所指向的数组
        // *(d + i) = (char *)malloc(sizeof(char) * n);
    }
    printf("二维数组m*n,两维都未知,动态分配空间\n");
    printf("sizeof(d) = %ld byte\n", sizeof(d));//8，指针
    printf("sizeof(d[0]) = %ld byte\n", sizeof(d[0]));//8，指针
    printf("sizeof(d[0][0]) = %ld byte\n", sizeof(d[0][0]));//1
    printf("\n");

    /*二维数组m*n,两维都未知,一次动态分配内存(保证内存的连续性)*/
    D = (char **)malloc(sizeof(char *) * m);//分配指针数组
    D[0] = (char *)malloc(sizeof(char) * m * n);//一次性分配所有空间
    for(i=1; i<m; i++){
        D[i] = D[i-1] + n;
    }
    printf("二维数组m*n,两维都未知,一次动态分配内存(保证内存的连续性)\n");
    printf("sizeof(D) = %ld byte\n", sizeof(D));//8，指针
    printf("sizeof(D[0]) = %ld byte\n", sizeof(D[0]));//8，指针
    printf("sizeof(D[0][0]) = %ld byte\n", sizeof(D[0][0]));//1
    printf("\n");

    /*1byte 也是 1B(字节), 1byte = 8bit(位) */
    printf("1byte 也是 1B(字节), 1byte = 8bit(位)\n");
    printf("sizeof(char) = %ld byte\n", sizeof(char)); 
    printf("sizeof(int) = %ld byte\n", sizeof(int));
    printf("sizeof(float) = %ld byte\n", sizeof(float));
    printf("sizeof(double) = %ld byte\n", sizeof(double));

    /*释放动态空间*/
    /*释放a*/
    free(a);

    /*释放b*/
    for(i=0; i<m; i++){
        free(b[i]);
    }

    /*释放B*/
    free(B[0]);

    /*释放c*/
    free(c);

    /*释放d*/
    for(i=0; i<m; i++){
        free(d[i]);
    }
    free(d);

    /*释放D*/
    free(D[0]);
    free(D);
}
