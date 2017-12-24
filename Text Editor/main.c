#include <stdio.h>
#include <stdlib.h>     //header files
#include <string.h>

FILE *fp1,*fp2;
char fn[1000],s[1000],c,fn1[1000],fn2[1000],bc[100],text[1000]; //global declartions
char colorValue[32];
int  o,i,pos,len,ch,char_cnt=0,blank_cnt=0,line_cnt=0;


void fileEx(int ch1);  //function declaration
void editEx(int ch2);
void helpEx(int ch3);
int file_size( FILE * fp);
void displayHead()
{
    time_t mytime;
    mytime = time(NULL);
    printf("==========================================================|\n");
    printf(ctime(&mytime));//used to display time and date
    printf("\n\t...........TEXT EDITOR...............\n\n");
    printf("==========================================================|\n");

}
int main()
{
    int ch1,ch2,ch3;
    //start:
    char ch;
    system("title Editor");
    system("cls");
    system("color 47");
    displayHead();
    system("pause"); //asks for input from keyboard
    for(;;)
    {
        system("cls");
        displayHead();
        printf("\n1.File\t2.Edit\t3.Help\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:system("cls");
                   displayHead();
                   printf("1.New\t2.Open\t3.Detail   4.Set  5.Back  6.Exit\n");
                   fflush(stdin);//clears keyboard buffer
                   scanf("%d",&ch1);
                   fileEx(ch1);
                   break;
            case 2:system("cls");
                   displayHead();
                   printf("1.Append\t2.Modify\t3.Rename\t4.Copy\t5.Cut\t6.Delete\t7.Time/Date\t8.Back\n");
                   fflush(stdin);
                   scanf("%d",&ch2);
                   editEx(ch2);
                   break;
            case 3:system("cls");
                   displayHead();
                   printf("1.Editor\t2.About\n");
                   scanf("%d",&ch3);
                   helpEx(ch3);
                   break;
             //goto start;
        }
    }
return 0;
}


void fileEx(int ch1) //function definition
{
    switch(ch1)
    {
        case 1:system("cls");
               fflush(stdin);
               fp1=fopen("temp.txt","w");  //creating new file
               printf("Enter a few lines of text:\n");
               while(strlen(gets(s))>0)
                {
                fputs(s,fp1);
                fputs("\n",fp1);
                }
               fclose(fp1);
               printf("Enter new filename: ");
               scanf("%s",fn);
               fp1=fopen("temp.txt","r");
               fp2=fopen(fn,"w");
               while(!feof(fp1))
                {
                   c=getc(fp1);
                   putc(c,fp2);
                }
               fclose(fp2);
               break;
        case 2:system("cls");
               printf("Enter the file name: ");
               fflush(stdin);
               scanf("%s",fn);
               fp1=fopen(fn,"r");//displaying contents of file
               if(fp1==NULL)
               {
                printf("\n\tFile not found!");
                goto end1;
               }
               while(!feof(fp1))
               {
                c=getc(fp1);
                printf("%c",c);
               }
               end1:
                    fclose(fp1);
                    printf("\n");
                    fflush(stdin);
                    getch();
               break;
        case 3:system("cls");
                printf("Enter the file name : ");
                scanf("%s",fn);
               if((fp1=fopen(fn,"r"))==NULL)
               {
                system("cls");
                printf("\n\n\n\n\n\n\n\                   Error : \n\n");
                return;
               }
               fp2=fopen(fn,"r");//displaying details of file
               system("cls");
               printf("\n===============================================================================|\n");
               printf("File details :");
               printf("\n===============================================================================|\n\n");
               printf("\nFile size  : %ld",file_size(fp1));
               while((ch=getc(fp2))!=EOF)
               {
                char_cnt++;
               if(ch==' ')blank_cnt++;
               if(ch=='\n') line_cnt++;
               }
               fclose(fp2);
               printf("\n\nNumber of character : %d",char_cnt);
               printf("\n\nNumber of line : %d",line_cnt);
               printf("\n\nNumber of blanck : %d",blank_cnt);
               getch();
               system("cls");
               break;
        case 4:system("cls");
               printf("color setting\n\n");//used to change background settings
               printf("0 = Black   8 = Gray\n");
               printf("1 = Blue    9 = Light Blue\n");
               printf("2 = Green   A = Light Green\n");
               printf("3 = Aqua    B = Light Aqua\n");
               printf("4 = Red     C = Light red\n");
               printf("5 = Purple  D = Light Purple\n");
               printf("6 = Yellow  E = Light Yellow\n");
               printf("7 = White   F = Bright White\n");
               printf("\nEnter code for the background and foreground color without space\n");
               scanf("%s",bc);
               strcpy(colorValue, "color ");
               strcat(colorValue, bc);
               system(colorValue);
               break;
        case 5:system("cls");//back to main menu
               break;
        case 6:exit(0);//closes text editor
    }
}

void editEx(int ch2)
{
    switch(ch2)
    {
        case 1:system("cls");
               printf("Enter file\n");
               fflush(stdin);
               scanf("%s",fn);
               fp1=fopen(fn,"r");
               if(fp1==NULL)
               {
                printf("File does not exist\n");
                goto label;
               }
               while(!feof(fp1))
               {
                c=getc(fp1);
                printf("%c",c);
               }
               fclose(fp1);
               fp1=fopen(fn,"a");//appending contents to the file
               while(1)
               {
                c=getch();
                if(c==19)
                goto label;
                if(c==13)
                {
                 c='\n';
                 printf("\n");
                 fputc(c,fp1);
                }
                else
                {
                 printf("%c",c);
                 fputc(c,fp1);
                }
               }
               label:fclose(fp1);
               getch();
               break;
        case 2: system("cls");
                int i;
                printf("Enter Filename to modify\n");
                fflush(stdin);
                scanf("%s",fn1);
                fp1=fopen(fn1,"r");//modifying contents of file
                i= 0;
                while(!feof(fp1))
                {
                    text[i++]= getc(fp1);//storing file contents in array for further operation
                }
                text[i]= '\0';
                fclose(fp1);
                len=strlen(text);
                pos=len;
                while(1)
                {
                    system("cls");
                    for(i=0;i<len;i++)
                    {
                        if(pos!=i)
                        {
                            printf("%c",text[i]);
                        }
                        else
                        {
                            printf("_");
                        }
                    }//end for
                    c=getch();
                    //printf("%d", c); // debug input
                    if(c==75) // arrow key
                    {
                        if(pos>0)
                        pos--;
                    }
                    else if(c==77) // arrow key
                    {
                        if(pos<len)
                        pos++;
                    }
                    else if(c==-32)
                    {
                        // skip garbage
                        continue;
                    }
                    else if(c==13)
                    {
                        break;
                    }
                    else
                    {
                        text[pos]= c;
                        pos++;
                    }
                    if(pos>=len)
                    {
                        len= pos+1;
                        text[len]= '\0';
                    }

                }//end while

                fp1=fopen(fn1,"w");
                i= 0;
                while(i<len)
                {
                    putc(text[i], fp1);  //copying array content to the file
                    i++;
                }
                fclose(fp1);
                break;
        case 3:system("cls");
               printf("Enter a file to be renamed\n");
               scanf("%s",fn1);
               printf("Enter new name\n");
               scanf("%s",fn2);
               fp1=fopen(fn1,"r");//renaming the file
               fp2=fopen(fn2,"w");
               if(fp1==NULL)
               {
                   printf("File does not exist\n");
                   goto end1;
               }
               while((c=getc(fp1))!=EOF)
               {
                   putc(c,fp2);
               }
               fclose(fp2);
               fclose(fp1);
               fp2=fopen(fn2,"r");
               while((c=getc(fp2))!=EOF)
               {
                printf("%c",c);
               }
               fclose(fp2);
               if(remove(fn1)==0);
               end1:fclose(fp1);
                    fclose(fp2);
                    getch();
               break;
        case 4:system("cls");
               fflush(stdin);
               printf("Enter name of source file\n");
               scanf("%s",fn1);
               fflush(stdin);
               printf("Enter name of destination file\n");
               fflush(stdin);
               scanf("%s",fn2);
               fflush(stdin);
               fp1=fopen(fn1,"r");//copying contents of one file to another
               fp2=fopen(fn2,"w");
               while((c=getc(fp1))!=EOF)
               {
                putc(c,fp2);
               }
               fclose(fp2);
               fclose(fp1);
               fp2=fopen(fn2,"r");
               while((c=getc(fp2))!=EOF)
               {
                printf("%c",c);
               }
               fclose(fp2);
               printf("\n");
               getch();
               break;
        case 5:system("cls");
               fflush(stdin);
               printf("Enter name of source file\n");
               scanf("%s",fn1);
               fflush(stdin);
               printf("Enter name of destination file\n");
               fflush(stdin);
               scanf("%s",fn2);
               fflush(stdin);
               fp1=fopen(fn1,"r");//cut and paste
               fp2=fopen(fn2,"w");
               while((c=getc(fp1))!=EOF)
               {
                putc(c,fp2);
               }
               fclose(fp2);
               fclose(fp1);
               fp2=fopen(fn2,"r");
               while((c=getc(fp2))!=EOF)
               {
                printf("%c",c);
               }
               fclose(fp2);
               if(remove(fn1)==0);
               fp1=fopen(fn1,"w");
               fclose(fp1);
               printf("\n");
               getch();
               break;
        case 6:system("cls");
               printf("\n\tEnter the file name: ");
               scanf("%s",fn);
               fp1=fopen(fn,"r");
               if(fp1==NULL)
               {
                printf("\n\tFile not found!");
                goto end2;
               }
               fclose(fp1);
               if(remove(fn)==0)//Delete file if present
                {
                printf("\n\tFile has been deleted successfully!\n");
                goto end2;
                }
                else
                printf("\n\tError!\n");
                end2: printf("\n\n\tPress any key to continue…\n");
                      getch();
                break;
        case 7:system("date/t");
               system("time/t");
               printf("\n");
               getch();
               break;
        case 8:system("cls");//goto start;
               break;
    }
}

void helpEx(int ch3)
{
    switch(ch3)
    {
        case 1: printf("Most FAQ\n1.What is text editor?\n2.How do I find and replace specific characters or words?\n");
                printf("Please enter the question number whose answer you want\n");
                scanf("%d",&o);
                switch(o)
                {
                  case 1:printf("Text editor is a basic text-editing program and it's most commonly used to view or edit text files\n\n");
                         printf("This is a simple c program which used to edit text which includes");
                         printf("insert,delete append,modify etc\n");
                         system("pause");
                         break;
                  case 2:printf("Please use the choices that is specified in the MENU\n");
                         system("pause");
                         break;
                }
                break;
        case 2:printf("\nDeveloped by team EDITOR.\nTeam Memebers \n1.Faheem(Core Programmer)\n2.Ashwini.Loyd.Fernandes\n3.Jeevan Iral Barboza\n");
               printf("\nFeel free to refer this software.Please dont copy...\n");
               system("pause");
               break;
    }
}
 int file_size( FILE * fp)//calculating file contents
{
    long length;
    fseek(fp,0l,2);
    length=ftell(fp);
    return length;
}
