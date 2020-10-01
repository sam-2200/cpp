#include<stdlib.h>
#include<stdio.h>
#include<process.h>
struct student{
    int rollno;
    char name[50];
    char branch[5];
    int dbms,ds,c,total;
    float per;
    int std;
}st;
FILE *fptr;

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}
void write_student(){
    fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(st.name);
    printf("\n\nEnter The branch of student ");
    gets(st.branch);
    printf("\nEnter The marks in DBMS out of 100 : ");
    scanf("%d",&st.dbms);
    printf("\nEnter The marks in DS out of 100 : ");
    scanf("%d",&st.ds);
    printf("\nEnter The marks in C out of 100 : ");
    scanf("%d",&st.c);
    st.total=st.dbms+st.ds+st.c;
    st.per=(st.dbms+st.ds+st.c)/3.0;
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}



void display_all()
{
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0){
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nBranch of student : %s",st.branch);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in DBMS : %d",st.dbms);
      printf("\nMarks in DS : %d",st.ds);
      printf("\nMarks in C : %d",st.c);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nTotal Marks: %d",st.total);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}



void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0){
     if(st.rollno==n){
        system("cls");
        printf("\nRoll Number of Student : %d",st.rollno);
        printf("\nBranch of student : %s",st.branch);
        printf("\nName of student : %s",st.name);
        printf("\nMarks in DBMS : %d",st.dbms);
        printf("\nMarks in DS : %d",st.ds);
        printf("\nMarks in C : %d",st.c);
        printf("\nTotal Marks: %d",st.total);
        printf("\nPercentage of student is  : %.2f",st.per);
        printf("\n\n====================================\n");
        flag=1;
        }
    }
    fclose(fptr);
    if(flag==0)
        printf("\n\nrecord not exist");
    getch();
}



void modify_student()
{
    int no,found=0;
    system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.rollno==no)
           {
            printf("\nRoll Number of Student : %d",st.rollno);
            printf("\nBranch of student : %s",st.branch);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in DBMS : %d",st.dbms);
            printf("\nMarks in DS : %d",st.ds);
            printf("\nMarks in C : %d",st.c);
            printf("\nTotal Marks: %d",st.total);
            printf("\nPercentage of student is  : %.2f",st.per);
            
            printf("\nPlease Enter The New Details of student \n");
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\n\nEnter The branch of student ");
            gets(st.branch);
            printf("\nEnter The marks in DBMS out of 100 : ");
            scanf("%d",&st.dbms);
            printf("\nEnter The marks in DS out of 100 : ");
            scanf("%d",&st.ds);
            printf("\nEnter The marks in C out of 100 : ");
            scanf("%d",&st.c);
            st.total=st.dbms+st.ds+st.c;
            st.per=(st.dbms+st.ds+st.c)/3.0;
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
        printf("\n\n Record Not Found ");
    getch();
}





void delete_student()
   {
    int no;
    FILE *fptr2;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0){
       if(st.rollno!=no){
            fwrite(&st,sizeof(st),1,fptr2);
       }
    }

    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}



    void class_result()
    {
    system("cls");
    fptr=fopen("student.dat","rb");
    if(fptr==NULL){
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
    }

    printf("\n\n\t\tALL STUDENTS RESULT \n\n");
    printf("====================================================\n");
    printf("R.No.  Branch   Name      DBMS    DS    C    percentage     TOTAL\n");
    printf("====================================================\n");

    while((fread(&st,sizeof(st),1,fptr))>0)
     {
       printf("%-6d  %-2s   %-10s %-3d     %-3d    %-3d     %-3.2f percent    %-3d \n",st.rollno,st.branch,st.name,st.dbms,st.ds,st.c,st.per,st.total);
     }
     fclose(fptr);
     getch();
}



   void result(){
    int ans,rno;
    char ch;
    system("cls");
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2)? ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        system("cls");
        printf("\n\nEnter Roll Number Of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }


void intro()
{
 system("cls");
 gotoxy(35,11);
 printf("STUDENT Database \n");
 printf("Assignment 1");
 printf("\n\n\n\n\n\nMADE BY : Ekaansh Ahuja");
 printf("\nRoll number : 19ucc077\n\n");
 printf("press ENTER to continue...");

 getch();
}

void entry_menu()
{
    char ch2;
   system("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system("cls");
          write_student();
          break;
    case '2': display_all();break;
    case '3':  {
           int num;
           system("cls");
           printf("\n\n\tPlease Enter The roll number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': break;
      default:printf("\a");entry_menu();
   }
}
void main()
{
  char ch;
  intro();
  do
    {
      system("cls");
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': system("cls");
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}