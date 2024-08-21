 #include<iostream>
#include<string>
using namespace std;
class AdjacencyList
{
    public:
    string city;
    int fuel,v,e;
    AdjacencyList *next;
    void create();
    void accept();
    void display();
}*start[30];
void AdjacencyList::create()
{
    cout<<"Enter Number of Cities : ";
    cin>>v;
    for(int i=0;i<v;i++)
    {
        cout<<"Enter Name of City : ";
        start[i]=new AdjacencyList;
        cin>>start[i]->city;
        start[i]->next=NULL;
    }
}
void AdjacencyList::accept()
{
    string source,dest;
    AdjacencyList *newnode,*temp;
    cout<<"Enter Number of Edges : ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the Source : ";
        cin>>source;
        cout<<"Enter the Destination : ";
        cin>>dest;
        for(int j=0;j<v;j++)
        {
            if(source==start[i]->city)
            {
                break;
            }
        }
        newnode=new AdjacencyList;
        newnode->city=dest;
        cout<<"Enter the fuel Required : ";
        cin>>newnode->fuel;
        newnode->next=NULL;
        temp=start[i];
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void AdjacencyList::display()
{
        AdjacencyList *newnode;
        for(int i=0;i<v;i++)
        {
            cout<<"\nSource : "<<start[i]->city;
            newnode=start[i]->next;
            while(newnode!=NULL)
            {
                cout<<"\nDestination : "<<newnode->city;
                cout<<"\nFuel Required : "<<newnode->fuel;
                newnode=newnode->next;
            }
        }   
}
int main()
{
    int choice;
    AdjacencyList am;
    do{
cout<<"\nAdjacency list"<<endl;
cout<<"\n1.create list";
cout<<"\n2.accept list";
cout<<"\n3.display list";
cout<<"\n4.exit";
cout<<"\nenter your choice ";
cin>>choice;
switch(choice)
{
    case 1:
    am.create();
    break;

    case 2:
    am.accept();
    break;
 
    case 3:
    am.display();
    break;

    case 4:
    exit(0);
    break;

    default:
    cout<<"invalid choice";
}
    }while(choice!=3);
    
    return 0;
}