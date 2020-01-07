#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(void);
int main(){
    int choose;
    int quit = 1;
    int flag;           //Used to check whether the account repeat
    char account[50] ;      //account already stored in file
    char password[50] ;     //password already stored in file
    char new_account[50] ;  //use to input new account
    char new_password[50] ; //use to input new password

    //create new file
    FILE *file;
    file = fopen("sql.txt","r");
    fclose(file);

    FILE *file1 ;
    file1 = fopen("temp.txt","r");
    fclose(file1);

    while(quit){
        choose = menu();
        switch(choose){
        case 1://create new account
            printf("\nNew account : ");
            scanf("%s", new_account);
            printf("New password : ");
            scanf("%s", new_password);

            //check if the account exists
            file = fopen("sql.txt","r");
            flag = 1;
            while(fscanf(file, "%s%s", account, password) != EOF){
                flag = strcmp(account, new_account); //相同就返回0
                if(flag == 0){
                    break;
                }
            }
            fclose(file);

            if(flag == 0){                                //the account have been use
                printf("This account have been use\n");
            }
            else{
                printf("\nok!\n");
                file = fopen("sql.txt","a");
                fprintf(file,"%s \t %s\n", new_account, new_password);
                fclose(file);
            }
            break;

        case 2://sign in
            printf("\nYour account : ");
            scanf("%s",new_account);
            printf("Your password : ");
            scanf("%s",new_password);

            flag = 0;
            file = fopen("sql.txt","r");
            while(fscanf(file, "%s%s", account, password) != EOF){
                if(strcmp(account, new_account) == 0 && strcmp(password,new_password) == 0){
                    flag = 1;
                }
            }
            fclose(file);

            //check sign in suceesfully
            if(flag == 0){
                printf("Fail to sign in!\n");
            }
            else{
                printf("Success to sign in!\n");
            }
            break;

        case 3:                           //Delete
            printf("\nYour account : ");
            scanf("%s",new_account);
            printf("Your password : ");
            scanf("%s",new_password);

            flag = 0;
            file = fopen("sql.txt","r");
            file1 = fopen("temp.txt","w");
            while(fscanf(file, "%s%s", account, password) != EOF){

                if(strcmp(account, new_account) == 0 && strcmp(password, new_password) == 0){ 
                    flag = 1; //遇到相同的就flag=1，要删除
                }
                else{
                    fprintf(file1, "%s\t%s\n", account, password); //写到temp里面
                }
            }
            fclose(file);
            fclose(file1);
            remove("sql.txt");

            //Rewrite file

            FILE *file;
            file = fopen("sql.txt", "a");
            file1 = fopen("temp.txt", "r");
            while(fscanf(file1, "%s%s", account, password) != EOF){
                fprintf(file, "%s\t%s\n", account, password);
            }
            fclose(file);
            fclose(file1);

            remove(file1);
            //check successful deletion
            if(flag == 0){
                printf("no account\n");
            }
            else{
                printf("clear\n");
            }
            break;

        case 4://quit
            quit = 0;
            break;
        default:
            printf("input wrong\n");
            break;
        }
    }
    return 0;
}

int menu(void){
    int choose;
    printf("What function do you want to choose?\n\
           1.Register\n\
           2.Sign in\n\
           3.Delete\n\
           4.Quit\n");
    printf("Your choose? ");
    scanf("%d", &choose);
    return choose;
}
