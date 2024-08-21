#include<iostream>  //charity manag. system assign. 2
using namespace std;
class Cms
{
public:
int did,amt;
string name,add;
string cno;
Cms *next,*prev; 

void accept();//function declaration
void display();
void search();
void update();
void Delete_from_beg();
void Delete_any_pos();
void Delete_from_end();
}*start,*end1;

void Cms::accept()//accept book record from users 
{
Cms *nnode;
nnode=new Cms;
cout<<"enter the donar id ";
cin>>nnode->did;
cout<<"enter the name";
cin>>nnode->name;
cout<<"enter the amount";
cin>>nnode->amt;
cout<<"enter the address";
cin>>nnode->add;
cout<<"enter the contact no";
cin>>nnode->cno;
nnode->next=nnode->prev=NULL;
if(start==NULL)
{
end1=start=nnode;
}
else
{
end1->next=nnode;
nnode->prev=end1;
end1=nnode;
}
}

void Cms::display()
{int count=0;
Cms *nnode;
nnode=start;
cout<<"\n"<<"donar id"<<"\t"<<"name"<<"\t"<<"amount"<<"\t"<<"address"<<"\t"<<"contact no";
while(nnode!=NULL)
{

cout<<"\n"<<nnode->did<<"\t"<<nnode->name<<"\t"<<nnode->amt<<"\t"<<nnode->add<<"\t"<<nnode->cno;
nnode=nnode->next;
count++;
}
cout<<"\nnumber of record :"<<count<<endl;
}

void Cms::search()
{
int id,f=0;
Cms *nnode;
nnode=start;
cout<<" enter the donar id you want to search";
cin>>id;
while(nnode!=NULL)
{
if(nnode->did==id)
{
f=1;
cout<<"\n"<<"donarid"<<"\t"<<"name"<<"\t"<<"amount"<<"\t"<<"address"<<"\t"<<"contactno";
cout<<"\n"<<nnode->did<<"\t"<<nnode->name<<"\t"<<nnode->amt<<"\t"<<nnode->add<<"\t"<<nnode->cno;
cout<<"\nrecord found";
break;
}
nnode=nnode->next;

}
if(f==0)
{
cout<<"record not found";
}
}

void Cms::update()
{
int id,f=0;
cout<<" enter the donar id you want to update ";
cin>>id;
Cms *nnode;
nnode=start;
while(nnode!=NULL)
{
if(nnode->did==id)
{
f=1;
cout<<"enter new name ";
cin>>nnode->name;
cout<<"enter new amount ";
cin>>nnode->amt;
cout<<"enter new address ";
cin>>nnode->add;
cout<<"enter new contact no ";
cin>>nnode->cno;
}
nnode=nnode->next;
}
if(f==0)
{
cout<<"record not found";
}
}

void Cms::Delete_from_beg()
{
Cms *temp;
if(start==NULL)
{
    cout<<"list is empty";

}
else
{
temp=start;
start=start->next;
start->prev=NULL;
delete (temp);
}
}

void Cms::Delete_any_pos()
{
Cms *temp;
temp=start;
int id,i;
cout<<"enter the did u want to delete";
cin>>id;
if(temp->did==id)
{
    cout<<"record found";
}
for(i=1;temp!=NULL&&i<id;i++)
{
    temp=temp->next;
}
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
delete (temp);
}
void Cms::Delete_from_end()
{
    Cms *temp;
    if(end1==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        temp=end1;
        end1=end1->prev;
        end1->next=NULL;
        delete (temp);
    }
}

int main()
{       
Cms l;
int ch;
do
{
cout<<"\n*record of book*"<<endl;
cout<<"\n1.accept";
cout<<"\n2.display";
cout<<"\n3.search";
cout<<"\n4.update";
cout<<"\n5.Delete from beg";
cout<<"\n6.Delete_any_pos";
cout<<"\n7.Delete from end";
cout<<"\n8.exit";
cout<<"\nenter your choice";
cin>>ch;

switch(ch)
{
case 1:
l.accept();
break;

case 2:
l.display();
break;

case 3:
l.search();
break;

case 4:
l.update();
break;

case 5:
l.Delete_from_beg();
break;

case 6:
l.Delete_any_pos();
break;

case 7:
l.Delete_from_end();
break;

case 8:
exit(0);
default:
cout<<"wrong choice";
}
}while(ch!=6);
return 0;

}