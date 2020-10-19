//Assingment-1 First part
//Submitted by Shubham Agrawal 
// 19UCS073

#include<bits/stdc++.h>
using namespace std;
struct student
{
    int id;
    string name;
    string branch;
};

struct marks
{
    int id;
    double dbms,ds,c,total;
    double percent;
    
};

map<int,student>mp;
map<int,marks>mk;
map<int,student>::iterator itr;
student newenrty();
student modifyname(student input);
student modifybranch(student input);
void search_branchwise(string s);
void search_namewise(string s);

student newentry()
{
    student input;
    int i;
    string n,b;
    cout<<"Enter student id::";
    cin>>i;

    while(mp.find(i)!=mp.end())
    {
        cout<<"\nEntry is already present try whith a new one"<<endl;
        cout<<"Enter student id::";
        cin>>i;
    }
    cout<<"\nEnter name of student::";
    cin>>n;
    cout<<"\nEnter branch of student::";
    cin>>b;
    cout<<endl;
    input.id=i;
    input.name=n;
    input.branch=b;
    return input;
}


student modifyname(student input)
{
    cout<<"Enter name to be updated::";
    string s;
    cin>>s;
    cout<<"\n"<<input.name<<" is changed to "<<s;
    input.name=s;
    return input;
    //fwrite(&input,sizeof(student),1,out);

}


student modifybranch(student input)
{
    cout<<"Enter branch to be updated::";
    string s;
    cin>>s;
    
    cout<<"\n"<<input.branch<<" is changed to"<<s;
    input.branch=s;
    //fwrite(&input,sizeof(student),1,out);
    return input;

}


void search_branchwise(string s)
{
    int flag=0;
    for(auto i:mp)
    {
        if(i.second.branch==s)
        {
            if(!flag)
            {
                cout<<"STUDENT DETAILS::"<<endl;
                cout<<"ID\t\tNAME\t\tBRANCH"<<endl;
                flag=1;
            }
            cout<<i.second.id<<"\t\t"<<i.second.name<<"\t\t"<<i.second.branch<<endl;
        }
    }
}


void search_namewise(string s)
{
    int flag=0;
    for(auto i:mp)
    {
        if(i.second.name==s)
        {
            if(!flag)
            {
                cout<<"STUDENT DETAILS::"<<endl;
                cout<<"ID\t\tNAME\t\tBRANCH"<<endl;
                flag=1;
            }
            cout<<i.second.id<<"\t\t"<<i.second.name<<"\t\t"<<i.second.branch<<endl;
        }
    }
}
void updatemarks(int id)
{
    cout<<"Enter subject of which marks to be updated(all letters in small case)::";
    string s;
    cin>>s;
    int f=0;
    if(s=="dbms")
    {
        f=1;
        int marks;
        cout<<"\nEnter new marks in DBMS::";
        cin>>marks;
        while(marks>100)
        {
            cout<<"\nMarks cannot exceed 100 enter marks again"<<endl;
            cin>>marks;
        }
        mk[id].dbms=marks;
        cout<<"\nMarks updated"<<endl;
    }
    else if(s=="ds")
    {
        f=1;
        int marks;
        cout<<"\nEnter new marks in DS::";
        cin>>marks;
        while(marks>100)
        {
            cout<<"\nMarks cannot exceed 100 enter marks again"<<endl;
            cin>>marks;
        }
        mk[id].ds=marks;
        cout<<"\nMarks updated"<<endl;
    }
    else if(s=="c")
    {
        f=1;
        int marks;
        cout<<"\nEnter new marks in C::";
        cin>>marks;
        while(marks>100)
        {
            cout<<"\nMarks cannot exceed 100 enter marks again"<<endl;
            cin>>marks;
        }

        mk[id].c=marks;
        cout<<"\nMarks updated"<<endl;
    }
    mk[id].total=mk[id].c+mk[id].dbms+mk[id].ds;
    mk[id].percent=mk[id].total/3;
    if(f==0)
    {
        cout<<"\nEnter correct subject"<<endl;
        updatemarks(id);
        return;
    }
}
int main()
{
    //FILE *out;
    //out=fopen("data.txt","w");
    ifstream indata;
    indata.open("students.txt");

    if(!indata)
    {
        cout<<"FILE cannot be opend"<<endl;
        return 0;
    }
    int x;
    while(indata>>x)
    {
        student ind;
        ind.id=x;
        indata>>ind.name;
        indata>>ind.branch;
        mp[x]=ind;
    }
    indata.close();
    ofstream outdata;
    outdata.open("students.txt");
    if(!outdata)
    {
        cout<<"Students FILE cannot be opend"<<endl;
        return 0;
    }


    int choice;
    
    do
    {
        cout<<endl;
        cout<<"-----------------Entry MENU-----------------\n";
        cout<<"For a new entry press 1"<<endl<<"For modification of Name press 2"<<endl;
        cout<<"For modification in Branch press 3"<<endl;
        cout<<"Delete student data press 4"<<endl;
        cout<<"Search branchwise press 5"<<endl;
        cout<<"Search by name press 6"<<endl;
        cout<<"To Enter marks of given entries press 7\n"<<endl;
        cout<<"Enter your choice:: ";
        cin>>choice;
        cout<<endl;
        student input;
        student *in;
        in=NULL;
        switch (choice)
        {
            case 1:
            {    
                input=newentry();
                mp[input.id]=input;
                //fwrite(&input,sizeof(student),1,out);
                break;
            }
            case 2:
            {
                cout<<"Enter student id whose name to be modify::";
                int id;
                cin>>id;
                if(mp.find(id)==mp.end())
                {
                    cout<<"No such id found"<<endl;
                    break;
                }
                else
                {
                    input=mp[id];
                    mp[id]=modifyname(input);
                }
                
                break;
            }
            case 3:
            {
                cout<<"Enter student id whose branch to be modify::";
                int id;
                cin>>id;
                if(mp.find(id)==mp.end())
                {
                    cout<<"No such id found"<<endl;
                    break;
                }
                else
                {
                    input=mp[id];
                    mp[id]=modifybranch(input);
                }
                break;
            }
            case 4:
            {
                int id;
                cout<<"Enter id which has to be deleted::";
                cin>>id;
                if(mp.find(id)==mp.end())
                {
                    cout<<"No such id found"<<endl;
                    break;
                }
                else
                {
                    mp.erase(id);
                    cout<<"Student id::"<<id<<" has been deleted"<<endl;
                }
                break;
                
                
            }
            case 5:
            {
                string s;
                cout<<"Enter branch to be searched"<<endl;
                cin>>s;
                search_branchwise(s);
                break;
            }
            case 6:
            {
                string s;
                cout<<"Enter name to be searched"<<endl;
                cin>>s;
                search_namewise(s);
                break;
            }
            case 7:
                break;
            default:
            {   
                cout<<"Incorrect option selected"<<endl;
                break;
            }
        }

    }while (choice!=7);
    //outdata<<"ID\t\tNAME\t\tBRANCH"<<endl;
    for(auto i:mp)
    {
        outdata<<i.second.id<<"\t\t"<<i.second.name<<"\t\t"<<i.second.branch<<endl;
    }
   //outdata.close();
    ofstream out;
    out.open("marks.txt");
    if(!out)
    {
        cout<<" Marks FILE cannot be opend"<<endl;
        return 0;
    }
    cout<<"Insert marks of all students"<<endl;
    for(auto i:mp)
    {
        marks temp;
        cout<<"Enter marks of student id:: "<<i.first<<" "<<i.second.name<<endl;
        cout<<"Marks in DBMS::";
        cin>>temp.dbms;
        while(temp.dbms>100)
        {
            cout<<"\nMarks cannot exceed 100 Please re-enter marks in DBMS::";
            cin>>temp.dbms;
        }
        cout<<"\nMarks in DS::";
        cin>>temp.ds;
        while(temp.ds>100)
        {
            cout<<"\nMarks cannot exceed 100 Please re-enter marks in DS::";
            cin>>temp.ds;
        }
        cout<<"\nMarks in C::";
        cin>>temp.c;
        while(temp.c>100)
        {
            cout<<"\nMarks cannot exceed 100 Please re-enter marks in C::";
            cin>>temp.c;
        }
        temp.total=temp.dbms+temp.ds+temp.c;
        temp.percent=(temp.total*100)/300;
        cout<<"Total marks obtained:: "<<temp.total<<" out of 300 \t\tPercentage:: "<<temp.percent*1.0<<"%\n"<<endl;
        mk[i.first]=temp;


    }
    int ch;
    do
    {
        double h;
        cout<<"\n----------------Marks MENU----------------\n";
        cout<<"Press 1 for upate marks in one of the subject of student"<<endl;
        cout<<"Press 2 to delete student record from data\n";
        cout<<"Press 3 for list of marks by student ID\n";
        cout<<"Press 4 to search the student with above percentage threshold"<<endl;
        cout<<"Press 5 to search the students of a particular BRANCH with PERCENTAGE above a threshold"<<endl;
        cout<<"Press 6 to exit from program\n";
        cout<<"ENTER YOUR OPTION::";
        cin>>ch;
        cout<<endl;
        switch (ch)
        {
        case 1:
            {
                int id;
                cout<<"Enter student ID of which marks to be updated:: ";
                cin>>id;
                if(mk.find(id)==mk.end())
                {
                    cout<<"\nNO such ID found\n";
                    break;
                }
                updatemarks(id);
                break;
            }
        case 2:
        {
            cout<<"\nEnter student ID to be deleted::";
            int id;
            cin>>id;
            if(mk.find(id)==mk.end())
            {
                cout<<"\nNO such ID found\n";
                break;
            }
            mk.erase(id);
            mp.erase(id);
            cout<<"\nID deleted\n";
            break;

        }
        case 3:
        {
            cout<<"Enter student ID"<<endl;
            int id;
            cin>>id;
            if(mk.find(id)==mk.end())
            {
                cout<<"\nNO such ID found\n";
                break;
            }
            cout<<"MARKS OF ::"<<mp[id].name<<endl;
            cout<<"DBMS\t\tDS\t\tC\t\tTOTAL\t\tPERCENTAGE"<<endl;
            cout<<mk[id].dbms<<"\t\t"<<mk[id].ds<<"\t\t"<<mk[id].c<<"\t\t"<<mk[id].total<<"\t\t"<<mk[id].percent*1.0<<endl;
            break;

        }
        case 4:
        {
            cout<<"Set a threshold percentage::";
            cin>>h;
            int f=1;
            for(auto i:mk)
            {
                if(i.second.percent>h)
                {
                    if(f==1)
                    {
                        f=0;
                        cout<<"\nID\t\tNAME\t\tBRANCH\t\tPERCENTAGE"<<endl;
                    }
                    cout<<i.first<<"\t\t"<<mp[i.first].name<<"\t\t"<<mp[i.first].branch<<"\t\t"<<i.second.percent<<endl;
                }
            }
            if(f==1)
            {
                cout<<"\nNo such student found\n";
            }
            break;
        }
        case 5:
        {
            cout<<"Enter branch::";
            string s;
            cin>>s;
            cout<<endl;
            cout<<"Set a threshold percentage::";
            cin>>h;
            int f=1;
            for(auto i:mk)
            {
                int id=i.first;
                if(i.second.percent>h&&mp[i.first].branch==s)
                {
                    if(f==1)
                    {
                        f=0;
                        cout<<"\nID\t\tNAME\t\tBRANCH\t\tPERCENTAGE"<<endl;
                    }
                    cout<<i.first<<"\t\t"<<mp[id].name<<"\t\t"<<mp[id].branch<<"\t\t"<<i.second.percent*1.0<<"%"<<endl;
                }
            }
            if(f==1)
            {
                cout<<"\nNo such student found\n";
            }
            break;

        }
        case 6:
        {
            break;
        }
        
        default:
            cout<<"Choose correct option from menu\n";
            break;
        }

    } while (ch!=6);

    for(auto i:mp)
    {
        outdata<<i.second.id<<"\t\t"<<i.second.name<<"\t\t"<<i.second.branch<<endl;
    }
    out<<"ID\t\tMARKS IN DBMS\t\tMARKS IN DS\t\tMARKS IN C\t\tTOTAL MARKS\t\tPERCENTAGE\n";
    for(auto i:mk)
    {
        out<<i.first<<"\t\t"<<i.second.dbms<<"\t\t"<<i.second.ds<<"\t\t"<<i.second.c<<"\t\t"<<i.second.total<<"\t\t"<<i.second.percent*1.00<<"%\n";
    }
    cout<<endl;
    return 0;
  
    
}
