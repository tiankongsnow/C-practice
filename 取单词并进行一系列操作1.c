/*取出文章中的单词，输出单词，计算总单词数
    计算每个单词长度， 计算每种长度的单词数，
        计算平均单词长度，输出最长单词，输出单词总数*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define     MAXWORD     1000    //最长单词1000个字母
#define     MAXLINE     1000    //最多1000个单词

char *getword(char *text, char *word);
/*取一段英文取出每一位单词*/
char *getword(char *text, char *word){
    char *ptr=text;
    char *qtr=word;
    char *textend;
    textend = text + strlen(text);
    word[0]='\0';
    while(isspace(*ptr)){
        ptr++;
    }
    //while(!isspace(*ptr) && *ptr != '\0'){ //方法1
    while(!isspace(*ptr) && ptr < textend){
        *qtr++ = *ptr++;
    }
    *qtr='\0';
    if(word[0]=='\0'){
        return NULL;
    }
    return ptr;
}
int main(){

    int i;
    int len = 0;
    int largestLen = 0; //最长单词有多长
    int sum = 0; //所以单词长度总和
    int wordCount = 0; //单词总数量
    char line[MAXLINE]; //输入句子
    char word[MAXWORD]; //存单词
    int length[MAXWORD]; //统计每种长度的数量，MAXWORD为长度单词
    char longestWord[MAXWORD];//最长的单词
    longestWord[MAXWORD] = '\0';//初始化
    
    char *ptr;
    for(i = 0; i < MAXWORD; i++){
        length[i] = 0;
    }
    while(fgets(line, MAXLINE, stdin)){
        ptr = line;//把句子首地址传给ptr
        while((ptr = getword(ptr, word)) != NULL){
            wordCount++; //单词总数量
            printf("%s\n", word);
            length[strlen(word)] += 1;//遇到长度是某个值的就加1，统计每种长度的数量，例如length[3],长度为3
            len = strlen(word); //统计每一个单词长度
            sum += len;//统计每一个单词长度 ，然后累加，计算所以单词长度总和
            if(len > largestLen){
                strcpy(longestWord, word);
                largestLen = strlen(word); //当最长单词有变化，就更新最长值
            }
        }
        printf("longest word: %s\n", longestWord);
        for(i = 0; i <=largestLen; i++){
            printf("%d\t%d\n", i, length[i]);
        }
        printf("average word length: %f\n", (float)sum/wordCount);
    }
    printf("longest word: %s\n", longestWord);
    for(i = 0; i <=largestLen; i++){
        printf("%d\t%d\n", i, length[i]);
    }
    printf("word letter sum：%d\n", sum);
    printf("word count：%d\n", wordCount);
    printf("average word length: %f\n", (float)sum/wordCount);
    
}
