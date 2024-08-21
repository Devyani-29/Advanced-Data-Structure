#include<iostream>
#include<string>
using namespace std;
class AdjacencyMatrix
{
    public:
    int vertex,edge,fuel,a[30][30];
    string city[30];
    void create();
    void display();
};
void AdjacencyMatrix::create()
{
    cout<<"Enter Number of Cities : ";
    cin>>vertex;
    for(int i=0;i<vertex;i++)
    {
        cout<<"Enter Name of City : ";
        cin>>city[i];
    }
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            if(i==j)
            {
                a[i][j]=0;
            }
            else
            {
                    cout<<"Enter the fuel "<<city[i]<<" to "<<city[j]<<" : ";
                    cin>>fuel;
                    a[i][j]=fuel;
                    a[j][i]=a[i][j];
            }
        }
    }
}
void AdjacencyMatrix::display()
{
    cout<<"**Adjecancy Matrix**\n";
    for(int i=0;i<vertex;i++)
    {
        cout<<"\t"<<city[i]<<"\t";
    }
    cout<<"\n";
    for(int i=0;i<vertex;i++)
    {
        cout<<city[i];
        for(int j=0;j<vertex;j++)
        {
            cout<<"\t"<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{   int choice;
    AdjacencyMatrix am;
    do{
cout<<"\nAdjacency matrix"<<endl;
cout<<"\n1.create matrix";
cout<<"\n2.display matrix";
cout<<"\n3.exit";
cout<<"\neneter your choice ";
cin>>choice;
switch(choice)
{
    case 1:
    am.create();
    break;

    case 2:
    am.display();
    break;

    case 3:
    exit(0);
    break;

    default:
    cout<<"invalid choice";
}
    }while(choice!=3);
    
    return 0;
}