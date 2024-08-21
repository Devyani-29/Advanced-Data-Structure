#include<iostream>
#define MAX 20 
using namespace std;
int cnt=0,cnt1=0,cnt2=0;

class family
{
public:
int ger,age;
string gen,name;
family *lc,*rc;
void accept();
int display(family *root);
int leaf(family *root);
void insert(family *root,family *next);
void height();
}*root,*st[MAX] ;

//accept
void family::accept()
{
int ch;
family *next;
root=new family;
cout<<"enter the root info"<<endl;
cout<<"enter name,gen,age,ger"<<endl;
cin>>root->name>>root->gen>>root->age>>root->ger;
root->lc=root->rc=NULL;
cnt++;
cnt1=cnt2=cnt;
do
{
cout<<"do you want to add more info "<<endl;
cin>>ch;
if(ch==1)
{
next=new family;
cout<<"enter the new info"<<endl;
cin>>next->name>>next->gen>>next->age>>next->ger;
next->lc=next->rc=NULL;
insert(root,next);
}
}while(ch==1);
}
//insert
void family::insert(family *root,family *next)
{
char chr;
cout<<"where you want to insert (l/R)"<<root->name<<endl;
cin>>chr;
if(chr=='l' || chr=='L')
{
if(root->lc==NULL)
{
root->lc=next;
cnt1++;
}
else
{
insert(root->lc,next);
}
}
else if(chr=='r' || chr=='R')
{
if(root->rc==NULL)
{
root->rc=next;
cnt2++;
}
else
{
insert(root->rc,next);
}
}
}

/*int family::display(family *root)
{
if(root==NULL)
{
return 0;o
}
else
{
cout<<endl;
cout<<root->name<<"\t"<<root->gen<<"\t"<<root->age<<"\t"<<root->ger<<"\t"<<endl;
display(root->lc);
display(root->rc);
}
return 0;
}
*/

//display
int family:: display(family *root)
{

int top=-1;
family *temp;
temp=root;
if(root!=NULL)
{
do
{
while(temp!=NULL)
{
top++;
st[top]=temp;
temp=temp->lc;
}
if(top!=-1)
{
temp=st[top];
cout<<temp->name<<"\t"<<temp->gen<<"\t"<<temp->age<<"\t"<<temp->ger<<"\t"<<endl;
temp=temp->rc;
}
top--;
}while(temp!=NULL || top!=-1);
}
return 0;
}

//leap node
int family::leaf(family *root)
{
int top=-1;
family *temp;
temp=root;
if(root!=NULL)
{
do
{
while(temp!=NULL)
{
top++;
st[top]=temp;
temp=temp->lc;
}
if(top!=-1)
{
temp=st[top];
if(temp->lc==NULL && temp->rc==NULL)
{
cout<<temp->name<<"\t"<<temp->gen<<"\t"<<temp->age<<"\t"<<temp->ger<<"\t"<<endl;
}
temp=temp->rc;
top--;
}
}while(temp!=NULL || top!=-1);
}
return 0;
}

//height
void family::height()
{
if(cnt1>=cnt2)
{
cout<<"height of tree is:"<<cnt1;
}
else
{
cout<<"height of tree is:"<<cnt2;
}
}

int main()
{
family t;
int ch;
do{
cout<<"\n**MENU";
cout<<"\n1.CREATE";
cout<<"\n2.DISPLAY";
cout<<"\n3.HEIGHT";
cout<<"\n4.LEAF NODE";
cout<<"\n5.EXIT";
cout<<"\nEnter your Choice:";
cin>>ch;
		
switch (ch) 
{
case 1:
t.accept();
break;
case 2:
cout<<"Name\tGender\tAge\tGenereation"<<endl;
t.display(root);
break;
case 3:
t.height();
break;
case 4:
t.leaf(root);
break;
case 5:
exit(0);
default:
cout<<"Invalid Choice!!";
break;
}
}while(ch!=5);
}