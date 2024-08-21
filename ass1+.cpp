#include<iostream>  //assignment 1 lms
using namespace std;
class Lms
{
public:
int bid,pri;
string tt,aut;
Lms*next; 

void accept();//function declaration
void display();
void search();
void update();
void Delete_from_beg();
void Delete_from_end();
void Delete_any_pos();
}*start,*last;

void Lms::accept()//accept book record from users 
{
Lms *temp;
temp=new Lms;
cout<<"enter the book id";
cin>>temp->bid;
cout<<"enter the title";
cin>>temp->tt;
cout<<"enter the auther";
cin>>temp->aut;
cout<<"enter the price";
cin>>temp->pri;
temp->next=NULL;
if(start==NULL)
{
last=start=temp;
}
else
{
last->next=temp;
 last=temp;
}
}

void Lms::display()
{int count=0;
Lms *temp;
temp=start;
cout<<"\n"<<"book id"<<"\t"<<"title"<<"\t"<<"auther"<<"\t"<<"prize" ;
while(temp!=NULL)
{
cout<<"\n"<<temp->bid<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pri ;
temp=temp->next;
count++;
}
cout<<"\nnumber of book record :"<<count<<endl;
}

void Lms::search()
{
Lms *temp;  
int id,f=0;
temp=start;
cout<<" enter the bookid you want to search";
cin>>id;
while(temp!=NULL)
{
if(temp->bid==id)
{
f=1;
cout<<"record found";
cout<<"\n"<<temp->bid<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pri ;
break;
}
temp=temp->next;
}
if(f==0)
{
cout<<"record not found";
}
}

void Lms::update()
{Lms *temp;
int id,f=0;
temp=start;
cout<<" enter the bookid you want to update ";
cin>>id;

while(temp!=NULL)
{
if(temp->bid==id)
{
f=1;
cout<<"enter new title ";
cin>>temp->tt;
cout<<"enter new auther";
cin>>temp->aut;
cout<<"enter new prize ";
cin>>temp->pri;
}
temp=temp->next;
}
if(f==0)
{
cout<<"record not found";
}
}
void Lms::Delete_from_beg()
{
    Lms *temp;
    temp=start;
    if(start==NULL)
    {
        cout<<"list is empty";
    }
else
{
    start=start->next;
    delete (temp);
}
}
void Lms::Delete_from_end()
{Lms *temp;
Lms *prev;
temp=start;
  if(temp->next==NULL)
  {
      delete(temp);
  }
  else
  {
      while(temp->next->next!=NULL)
      {
          temp=temp->next;
      }
      prev=temp;
      temp=temp->next;
      delete temp;
      prev->next=NULL;
  }
}
void Lms::Delete_any_pos()
{Lms *temp;
Lms *nextnode;
int id,f=0,i;
temp=start;
cout<<" enter the bookid you want to delete ";
cin>>id;
if(temp->bid==id)
{
f=1;
cout<<"data found";
}
for(i=1;temp!=NULL&&i<id-1;i++)
{
temp=temp->next;
}

nextnode=temp->next;
temp->next=nextnode->next;
delete (nextnode);

}
int main()
{       
Lms l;
int ch;
do
{
cout<<"\n*record of book*"<<endl;
cout<<"\n1.accept";
cout<<"\n2.display";
cout<<"\n3.search";
cout<<"\n4.update";
cout<<"\n5.Delete_from_beg";
cout<<"\n6.Delete_from_end";
cout<<"\n7.Delete_any_pos";
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
l.Delete_from_end();
break;

case 7:
l.Delete_any_pos();
break;

case 8:
exit(0);
default:
cout<<"wrong choice";
}
}while(ch!=8);
return 0;
}