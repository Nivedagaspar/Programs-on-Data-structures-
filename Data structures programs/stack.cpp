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
void createstack(lst *list)
{list->head=NULL;
 list->count=0;
}
void push(int datain,lst* list)
{Node* pnew=new Node;
 pnew->data=datain;
 pnew->link=list->head;
 list->head=pnew;
}
void pop(lst *list)
{cout<<list->head->data;
 list->head=list->head->link;
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
 createstack(&list);
 cout<<"1.Push\n2.Pop\n3.Display\n4.Exit";
 do
 {cout<<"\nEnter choice:";
  cin>>choice;
  switch(choice)
  {case 1:
  	  cout<<"Enter element:";
  	  cin>>data;
  	  push(data,&list);
  	  break;
   case 2:
   	  pop(&list);
   	  break;
   case 3:
   	  display(&list);
   	  cout<<"display over";
   	  break;
  }
 }while(choice!=4);
}


