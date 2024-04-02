#include<iostream>
using namespace std;
struct Node
{int data;
 Node* link;
};
struct lst
{int count;
 Node* head;
};
Node* rear;
void createlist(lst *list)
{list->head=NULL;
 list->count=0;
}
void insert(int datain,lst *list)
{Node* pnew=new Node;
 if(list->head==NULL)
 {rear=pnew;
 }
 pnew->data=datain;
 pnew->link=list->head;
 list->head=pnew;
 list->count+=1;
}
void bubblesort(lst *list)
{Node *p,*end;
 int temp;
 for (end=NULL;end!=list->head->link;end=p)
 {for (p=list->head;p->link!=end;p=p->link)
  {if (p->data>p->link->data)
   {temp=p->data;
    p->data=p->link->data;
    p->link->data=temp;
   }
  }
 }
}
void display(lst *list)
{Node* ploc;
 ploc=list->head;
 while(ploc!=NULL)
 {cout<<ploc->data<<" ";
  ploc=ploc->link;
 }
}
int main()
{int data,choice;
 lst list;
 createlist(&list);
 cout<<"\n1.Insert\n2.sort\n3.Display\n4.Exit";
 do
 {cout<<"\nEnter choice:";
  cin>>choice;
  switch(choice)
  {case 1:
  	    cout<<"Enter element:";
  	    cin>>data;
  	    insert(data,&list);
  	    break;
  	case 2:
  		bubblesort(&list);
  		break;
  	case 3:
  		display(&list);
  		break;
  }
 }while(choice!=4);
}
