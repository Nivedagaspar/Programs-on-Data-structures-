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
void createlist(lst *list)
{list->count=0;
 list->head=NULL;
}
void insert(int datain,Node* ppre,lst *list)
{Node* pnew=new Node;
 pnew->data=datain;
 if (ppre==NULL)
 {
  pnew->link=list->head;
  list->head=pnew;
 }
 else
 {
 	pnew->link=ppre->link;
 	ppre->link=pnew;
 }
}
void delnode(Node* ppre,lst *list)
{
	if (ppre==NULL)
	{if(list->head==NULL)
        {
   	    cout<<"Empty list\n";
        }
	 else
	    {list->head=list->head->link;
		}	
    }
    else
    {ppre->link=ppre->link->link;
	}
}
Node* search(int target,lst *list)
{Node* ppre=NULL;
 Node* ploc;
 ploc=list->head;
 while(ploc!=NULL && target>ploc->data)
 {
  ppre=ploc;
  ploc=ploc->link;
 }
 return ppre;
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
 Node* ppre;
 lst list;
 createlist(&list);
 cout<<"\n1.Insert\n2.delete\n3.Display\n4.Exit";
 do
 {cout<<"\nEnter choice:";
  cin>>choice;
  switch(choice)
  {case 1:
  	    cout<<"Enter element:";
  	    cin>>data;
  	    ppre=search(data,&list);
  	    cout<<"search done";
  	    insert(data,ppre,&list);
  	    break;
  	case 2:
  		cout<<"Enter element:";
  	    cin>>data;
  	    ppre=search(data,&list);
  	    delnode(ppre,&list);
  	    break;
  	case 3:
  		display(&list);
  		break;
  }
 }while(choice!=4);
}
