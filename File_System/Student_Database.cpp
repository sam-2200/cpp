/*

        /////////  /////      ////      ///
        //        //   //    //  //  // //
        //////   //    //   //    //   //
            //  // /// //  //         //
      //////// //      // //         //
      
         

*/
#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(0);
#define fo(i,s,n) for(int i=s;i<n;i++)
#define mod 1000000007
#define umap unordered_map
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define lb() lower_bound()
#define ub() upper_bound()
#define PI 3.14159265
#define S second
#define F first 


struct student
{
    int id;
    char name[50];
    char branch[25];
};



struct marks
{
    int id;
    int DBMS,DS,C,total;
    double percent;

};


void newentry()
{
	FILE *file=fopen("student.txt","a+");
	student duplicheck,entry;
    idtake:
	cout<<"Enter student details to insert\n\tId (Id should be integer only): ";
	cin>>entry.id;
	while(fread(&duplicheck,sizeof(struct student),1,file))
	{
        if(duplicheck.id==entry.id)//compare(entry.id)==0)
        {
            cout<<"\nID already present enter new Id::"<<endl;
            goto idtake;
        }
    }
    cout<<"\tEnter Name :: ";
	cin>>entry.name;
	cout<<"\n\tEnter Branch :: ";
	cin>>entry.branch;
	fwrite (&entry, sizeof(student), 1, file);
	fclose(file);
}


void modifybranch()
{
    FILE *file=fopen("student.txt","r");
	int ID;
	printf("Enter ID whose branch is to be modified :: ");
	cin>>ID;
	student check;
	FILE *temp=fopen("tempfile.tmp","a+");
	fseek(file,0,0);
	fseek(temp,0,0);
    int flag=0;
	while(fread(&check,sizeof(struct student),1,file))
	{
		if(check.id!=ID)
			fwrite (&check, sizeof(struct student), 1, temp);
		else
		{
            flag=1;
			student entry;
			entry.id=ID;
			printf("\n\tEnter branch :: ");
			cin>>entry.branch;
			strncpy(entry.name,check.name,25);
			fwrite (&entry, sizeof(student), 1, temp);
		}
	}
    if(flag==0)
    {
        cout<<"No student with ID "<<ID<<" is found"<<endl;
    }
	fclose(file);
	fclose(temp);
    remove("student.txt");
	rename("tempfile.tmp","student.txt");

}

void modifyname()
{
	FILE *file=fopen("student.txt","r");
	int ID;
	printf("Enter ID whose name is to be modified :: ");
	cin>>ID;
	student check;
	FILE *temp=fopen("tempfile.tmp","a+");
	fseek(file,0,0);
	fseek(temp,0,0);
    int flag=0;
	while(fread(&check,sizeof(struct student),1,file))
	{
		if(check.id!=ID)
			fwrite (&check, sizeof(struct student), 1, temp);
		else
		{
            flag=1;
			student entry;
			entry.id=ID;
			printf("\n\tEnter name :: ");
			cin>>entry.name;
			strncpy(entry.branch,check.branch,25);
			fwrite (&entry, sizeof(student), 1, temp);
		}
	}
    if(flag==0)
    {
        cout<<"No student with ID "<<ID<<" is found"<<endl;
    }
	fclose(file);
	fclose(temp);
    remove("student.txt");
	rename("tempfile.tmp","student.txt");
    remove("tempfile.tmp");
}

void deletetxta()
{
	int ID;
	student check;
	marks mar;
	printf("\tEnter ID to be deleted :: ");
	cin>>ID;
	FILE *f=fopen("student.txt","r");
	FILE *temp=fopen("temp.txt","a+");
	FILE *fm=fopen("marks.txt","a+");
	FILE *tempm=fopen("tempm.txt","a+");
    int flag=0;
	while(fread(&check,sizeof(struct student),1,f))
	{
    	if(check.id!=ID)
			fwrite (&check, sizeof(struct student), 1, temp);
        else
        {
            flag=1;
        }
    }
            
	while(fread(&mar,sizeof(marks),1,fm))
		if(mar.id!=ID)
			fwrite (&mar, sizeof(marks), 1, tempm);
	fclose(f);
	fclose(temp);
	fclose(fm);
	fclose(tempm);
    if(flag==0)
    {
        cout<<"No such ID found \n";
    }
    else
    {
        cout<<"ID deleted"<<endl;
    }
    remove("student.txt");
    remove("marks.txt");
	rename("temp.txt","student.txt");
	rename("tempm.txt","marks.txt");
}

void search_branchwise()
{
        printf("\nEnter branch : ");
		char B[25];
		scanf("%s",B);
		FILE *f = fopen ("student.txt","r");
		student entry;
   		fseek(f,0,0);
        int flag=0;
   		while (fread (&entry, sizeof(student), 1, f))
        {
   			if(strcmp(entry.branch,B)==0)
    	  	{
                  if(flag==0)
                  {
                    flag=1;
                    cout<<"ID\t\t\tNAME\t\t\tBRANCH\n";
                  }
            	cout<<entry.id<<"\t\t\t"<<entry.name<<"\t\t\t"<<entry.branch<<endl;
            }
        }

        if(flag==0)
        {
            cout<<"No such branch found\n";
        }
            
}


void search_namewise()
{
    printf("\nEnter name :: ");
	char N[50];
	scanf("%s",N);
	FILE *f = fopen ("student.txt","r");
	student entry;
	fseek(f,0,0);
    int flag=0;
   	while (fread (&entry, sizeof(struct student), 1, f))
    {
        
		if(strcmp(entry.name,N)==0)
        {
            if(flag==0)
            {
                flag=1;
                cout<<"ID\t\t\tNAME\t\t\tBRANCH\n";
            }
            cout<<entry.id<<"\t\t\t"<<entry.name<<"\t\t\t"<<entry.branch<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"No such name found\n";
    }
}


int main()
{
    int choice;

    do
    {
        cout<<endl;
        cout<<"-----------------Database Entry MENU-----------------\n";
        cout<<"For a new entry press 1"<<endl<<"To modify Name press 2"<<endl;
        cout<<"To modify Branch press 3"<<endl;
        cout<<"For deletion of student data press 4"<<endl;
        cout<<"Press 5 to Search branchwise "<<endl;
        cout<<"Press 6 to Search by name "<<endl;
        cout<<"To enter marks of given entries press 7"<<endl;
        cout<<"TO exit program completly press 8"<<endl;
        cout<<"Enter your choice:: ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
            case 1:
            {
                newentry();
                cout<<endl;
                break;
            }
            case 2:
            {
                modifyname();
                cout<<endl;
                break;
            }
            case 3:
            {
                modifybranch();
                cout<<endl;
                break;
            }
            case 4:
            {
               deletetxta();
               cout<<endl;
               break;
            }
            case 5:
            {
                search_branchwise();
                cout<<endl;
                break;
            }
            case 6:
            {
                search_namewise();
                cout<<endl;
                break;
            }
            case 7:
                break;
            case 8:
                return 0;
            default:
            {
                cout<<"Incorrect option selected"<<endl;
                break;
            }
        }

    }while (choice!=7);

    choice=0;
    cout<<"\t\tEntring to marks MENU....."<<endl;

    do//while(1000)
    {
        a:
        cout<<endl;
        cout<<"..........MARKS - MENU.........."<<endl;
        cout<<"Press 1 for Insert Marks"<<endl<<"Press 2 for Update marks"<<endl;
        cout<<"Press 3 to Display Marks"<<endl;
        cout<<"Press 4 to search with percentage above a value"<<endl;
        cout<<"Press 5 to search with percentage above a value for a particular branch"<<endl;
        cout<<"Press 6 to Exit"<<endl;
        cout<<"Enter your choice:: ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
            case 1:
            {
                FILE *f = fopen("student.txt" , "r");
                struct student S;
                struct marks M;
                cout<<("Enter ID : ");
                cin>>M.id; int flag = 0;
                cout<<("\nEnter MARKS to insert:\n");
                while(fread(&S , sizeof(struct marks) , 1, f))
                    if(S.id==M.id)
                    {
                        flag = 1;
                        FILE *p = fopen("marks.txt" , "a+");
                        struct marks check;
                        while(fread(&check , sizeof(struct marks) , 1 , p))
                        if(check.id==M.id)
                        {
                            cout<<("Marks already entered for this ID!\n");
                            goto a;
                        }
                        cout<<("DBMS : ");
                        cin>>M.DBMS;
                        cout<<("DS : ");
                        cin>>M.DS;
                        cout<<("C : ");
                        cin>>M.C;
                        M.total = M.DBMS + M.C + M.DS;
                        M.percent = (double)M.total*1.0/3;
                        fwrite (&M , sizeof(struct marks), 1, p);
                        fclose(p);
                        continue;
                    }
                if(flag==0)
                    printf("ID doesn't exists !\n");
                fclose(f);
                break;
            }
            case 2:
            {
                int choice , ID;
                cout<<("Enter ID : ");
                cin>>ID;
                FILE *f = fopen("marks.txt" , "r");
                struct marks M;
                cout<<"\n1. Update DBMS marks\n2. Update DS marks\n3. Update C marks\nChoice :: ";
                cin>>choice;
                FILE *p = fopen("markstemp.txt" , "a+");
                while(fread(&M , sizeof(struct marks) , 1 , f))
                {
                    if(M.id!=ID)
                        fwrite (&M, sizeof(struct marks), 1, p);
                    else
                    {
                        struct marks stu;
                        stu.id = ID;
                        if(choice==1)
                        {
                            cout<<("Enter DBMS marks : ");
                            cin>>stu.DBMS;
                            stu.DS = M.DS;
                            stu.C = M.C;
                            stu.total = stu.DBMS + stu.DS + stu.C;
                            stu.percent = (double)stu.total*1.0/3;
                            fwrite(&stu, sizeof(struct marks), 1, p);
                        }
                        else if(choice==2)
                        {
                            cout<<("Enter DS marks : ");
                            cin>>stu.DS;
                            stu.DBMS = M.DBMS;
                            stu.C = M.C;
                            stu.total = stu.DBMS + stu.DS + stu.C;
                            stu.percent = (double)stu.total*1.0/3;
                            fwrite (&stu, sizeof(struct marks), 1, p);
                        }
                        else if(choice==3)
                        {
                            printf("Enter C marks : ");
                            cin>>stu.C;
                            stu.DBMS = M.DBMS;
                            stu.DS = M.DS;
                            stu.total = stu.DBMS + stu.DS + stu.C;
                            stu.percent = (double)stu.total*1.0/3;
                            fwrite (&stu, sizeof(struct marks), 1, p);
                        }
                    }
                }
                fclose(f);
                fclose(p);
                remove("marks.txt");
                rename("markstemp.txt" , "marks.txt");
                break;
            }
            case 3:
            {
                int ID;
                cout<<("Enter ID to be displayed: ");
                cin>>ID;
                FILE *f = fopen ("marks.txt" , "r");
                struct marks M; fseek(f , 0 , 0);
                int flag = 0; cout<<"FF"<<" "<<M.DBMS<<endl;
                while (fread (&M, sizeof(struct marks), 1, f))
                    if(M.id==ID)
                    {
                        if(flag==0)
                        {
                            flag=1;
                            cout<<("\nID\t\t\tDBMS\t\t\tDS\t\t\tC\t\t\tTOTAL\t\t\tPERCENTAGE\n");
                        }
                        cout<<M.id<<"\t\t\t"<<M.DBMS<<"\t\t\t"<<M.DS<<"\t\t\t"<<M.C<<"\t\t\t"<<M.total<<"\t\t\t"<<setprecision(10)<<M.percent<<endl;
                        continue;
                    }
                if(flag==0)
                    printf("ID doesn't exists !\n");
                fclose(f);
                break;
            }
            case 4:
            {
                double marker;
                printf("Enter marker: ");
                cin>>marker;
                FILE *f = fopen ("marks.txt" , "r");
                struct marks M;
                int flag=0;
                while (fread (&M, sizeof(struct marks), 1, f))
                {
                    if(M.percent>=marker)
                    {
                         if(flag==0)
                        {
                            flag=1;
                            printf("\nID\t\t\tNAME\t\t\tBRANCH\t\t\tPERCENTAGE\n");
                        }
                        FILE *p = fopen("student.txt" , "r");
                        struct student S;
                        while (fread (&S, sizeof(struct student), 1, p))
                            if(S.id==M.id)
                                cout<<M.id<<"\t\t\t"<<S.name<<"\t\t\t\t"<<S.branch<<"\t\t\t\t"<<setprecision(10)<<M.percent<<endl;
                        fclose(p);
                    }
                }
                if(flag==0)
                {
                    cout<<"\nNo one get above "<<marker<<endl;
                }
                fclose(f);
                break;
            }
            case 5:
            {
                double marker;
                char b[25];
                printf("\nEnter threshold precentage :: ");
                cin>>marker;
                cout<<("\nEnter branch:: ");
                cin>>b;
                FILE *f = fopen ("marks.txt" , "r");
                struct marks M;
                int flag=0;
                while (fread (&M, sizeof(struct marks), 1, f))
                {
                    if(M.percent>=marker)
                    {
                        if(flag==0)
                        {
                            flag=1;
                            printf("\nID\t\t\tNAME\t\t\tPERCENTAGE\n");
                        }
                        FILE *p = fopen("student.txt" , "r");
                        struct student S;
                        while (fread (&S, sizeof(struct student), 1, p))
                            if(S.id==M.id && strcmp(S.branch , b)==0)
                                cout<<M.id<<"\t\t\t"<<S.name<<"\t\t\t"<<setprecision(10)<<M.percent<<endl;
                        fclose(p);
                    }
                }
                if(flag==0)
                {
                    cout<<"\nNo one get above "<<marker<<" in ";
                    printf("%s \n",b);
                }
                
                
                fclose(f);
                break;
            }
            case 6:
                exit(0);
            default:
            {
                cout<<"Invalid enrty"<<endl;
                break;
            }
        }
    }while(choice!=6);

    return 0;

}