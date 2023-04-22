
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<assert.h>
#define PROGRAM_THROUGH_OUTPUT 23
void gotoxy(int ,int );
void menu();
void add();
void view();
void Schedule();
void modify();
void replaceAll(char *str, const char *oldWord, const char *newWord);
void deleterec();
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}
void green(){
    printf("\033[0;32m");
}
void cyan(){
    printf("\033[0;36m");
}
void reset () {
  printf("\033[0m");
}
#define BUFFER_SIZE 1000
struct student
{
    char name[30];
};


size_t len(){
    struct student std;
    FILE* len = fopen("record.txt","r");
    size_t count = 0;
    while(fscanf(len, "%s", std.name)!=EOF){
        count++;
    }
    fclose(len);
    return count;
}
void free_array(char* a[30]){
    for (size_t i = 0; i < len(); i++)
    {
        free(a[i]);
    }
    
}

int main()
{
    system("cls");
    green();
    gotoxy(15,8);
    printf("<--:IPL CRICKET TOURNAMENT SCHEDULAR:-->");
    gotoxy(33,13);
    gotoxy(19,15);
    printf("Press any key to continue.");
    reset();
    getch();
    menu();
    return 0;  
}
void menu()
{
    int choice;
    cyan();
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Plaese Enter Valid Button.");
    gotoxy(10,7);
    printf("1 : Add Team.");
    gotoxy(10,8);
    printf("2 : View Team.");
    gotoxy(10,9);
    printf("3 : View Schdule.");
    gotoxy(10,10);
    printf("4 : Modify Team.");
    gotoxy(10,11);
    printf("5 : Delete Team.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    reset();
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        green();
        add();
        break;
    case 2:
        green();
        view();
        break;
    case 3:
        green();
        Schedule();
        break;
    case 4:
        green();
        modify();
        break;
    case 5:
        green();
        deleterec();
        getch();
        menu();
        break;
    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        red();
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    fp = fopen("record.txt","a+");
    char another ='y';
    system("cls");
    if(fp == NULL){
        red();
        printf("Error opening file");
    }
    while (another=='y')
    {
       gotoxy(10,3);
       printf("<--:ADD Team:-->\n"); 
       gotoxy(10,5);
       printf("\nEnter Team Name : ");
       gotoxy(10,7);
       fflush(stdin);
       scanf("%s",std.name);
       gotoxy(10,8);
       fprintf(fp,std.name);
       fprintf(fp, "\n");
       gotoxy(10,15);
       cyan();
       printf("Want to add of another Team? Then press 'y' else 'n'.");
       fflush(stdin);
       another = getch();
       system("cls");
       fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW record:-->");
    gotoxy(10,5);
    printf("S.No   Name of Teams       ");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt","r+");
    if(fp == NULL){
        gotoxy(10,8);
        red();
        printf("Error opening file.");
        exit(1);
    }
    j=8;
     while(fscanf(fp, "%s", std.name)!=EOF)
   {
        gotoxy(10,j);
   		printf("%d            %s",i,std.name );
        j++;
        i++;
   }
    fclose(fp);
    gotoxy(10,j+3);
    red();
    printf("Press any key to continue.");
    reset();
    getch();
    menu();
}

void Schedule(){
    FILE *fp;
    struct student std;
    fp = fopen("record.txt","r");
    assert(fp != NULL);
    system("cls");
    char* a[30];
    int ia = 0;

    while(fscanf(fp, "%s", std.name)!=EOF){
        int len = strlen(std.name);
        a[ia] = (char*)malloc(sizeof(char)*len);
        strcpy(a[ia],std.name);
        ia++;
    }
    fclose(fp);
    gotoxy(10,3);
    printf("<---------:View Shedule:--------->\n\n\n");
    int count = 1;
    for (int i = 0; i < len(); i++) {
        for (int j = i + 1; j < len(); j++) {
            printf("Match %d: %s vs %s\n", count, a[i], a[j]);
            count++;
        }
    }
    red();
    printf("\n\n\nPress any key to continue.");
    reset();
    free_array(a);
    getch();
    menu();

}
void modify()
{
    FILE * fPtr;
    FILE * fTemp;
    char *path = "record.txt";
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];
    system("cls");
    gotoxy(10,3);
    printf("<---------:Repalce Team:--------->\n\n\n");
    gotoxy(10,6);
    printf("Enter Team Name to replace: ");
    scanf("%s", oldWord);
    printf("Replace '%s' with: ");
    scanf("%s", newWord);
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 
    if (fPtr == NULL || fTemp == NULL)
    {   gotoxy(10,6);
        red();
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        replaceAll(buffer, oldWord, newWord);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(path);
    rename("replace.tmp", path);
    gotoxy(10,6);
    green();
    printf("\nSuccessfully replaced Team Name of %s with %s", oldWord, newWord);
    gotoxy(10,8);
    cyan();
    printf("\nPress any key.....");
    reset();
    getch();
    menu();
}
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;
    owlen = strlen(oldWord);
    if (!strcmp(oldWord, newWord)) {
        return;
    }
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}
void deleterec()
{
    char* file_name = "record.txt", temp_file_name[50], str[100];
    FILE *fp, *temp_fp;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter the Team to be deleted: ");
    scanf("%s", str);

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        gotoxy(10,5);
        red();
        printf("Error opening file!");
        exit(1);
    }

    strcpy(temp_file_name, "temp.txt");
    temp_fp = fopen(temp_file_name, "w");
    if (temp_fp == NULL) {
        gotoxy(10,5);
        red();
        printf("Error creating temporary file!");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp)) {
        if (strstr(line, str) != NULL) {
            continue;
        }
        fputs(line, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    if (remove(file_name) != 0) {
        gotoxy(10,5);
        red();
        printf("Error deleting file!");
        exit(1);
    }

    if (rename(temp_file_name, file_name) != 0) {
        gotoxy(10,5);
        red();
        printf("Error renaming file!");
        exit(1);
    }
    gotoxy(10,5);
    green();
    printf("Team '%s' deleted successfully from file '%s'", str, file_name);
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
