/*Binary Search Tree, BST*/
/*输入max_nodes = 7
    输入key = 50 30 40 45 20 70 60 80 85
        输出tree = 50 30 70 20 40 60 80    */
#include <stdio.h>
int main(){
    int max_nodes; //最多多少个数字
    int key; //连续输入数字
    scanf("%d", &max_nodes);
    int tree[1000];
    /*初始化tree都为-1*/
    for(int i = 0; i < max_nodes; i++){
        tree[i] = -1;
    }
    while (scanf("%d", &key) != EOF){
        int i = 0;
        while(i < max_nodes && tree[i] != -1){
            if(key<tree[i]){
                i=i*2+1; //left
            }
            else{
                i=i*2+2; //right
            }
        }
        if(i < max_nodes){
            tree[i] = key;
        }
    }
    /*输出排序后的数字*/
    for (int i = 0; i < max_nodes; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}
