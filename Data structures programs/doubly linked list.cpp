#include<iostream>
using namespace std;
struct Node
{int data;
 Node* flink;
 Node* blink;
};
struct lst
{Node* head;
 Node* rear;
 int count;
};
void insert(int datain,Node* ppre,lst *list)
{Node* pnew=new Node;
 pnew->data=datain;
 if (ppre==NULL)
 {
  if (list->head==NULL)//inserting in empty list
     {
	  pnew->flink=list->head;
	  list->head=pnew;
	  pnew->blink=NULL;
	 }
  else//insertion as first element
     {
	  pnew->flink=list->head;
      pnew->blink=NULL;
      list->head->blink=pnew;
      list->head=pnew;
	 }
 }
 else
 {
  if(ppre->flink==NULL)//insertion at end
    {
	 list->rear=pnew;
     pnew->flink=ppre->flink;
     ppre->flink=pnew;
     pnew->blink=ppre;
	}
  else//insertion at middle
    {
	 pnew->flink=ppre->flink;
     pnew->blink=ppre;
     ppre->flink->blink=pnew;
     ppre->flink=pnew;
	}
 }
}
void deletenode(Node* ppre,lst *list)
{if (ppre==NULL)
    {if (list->head==NULL)//empty list
        {cout<<"Empty list\n";
		}
	 else//first node (or) only node
	    {if (list->head->flink==NULL)//only node
	        {list->head=NULL;
	         list->rear=NULL;
			}
		 else//first node
		    {list->head->flink->blink=list->head->blink;
		     list->head=list->head->flink;
			}
		}
	}
 else// end or middle
    {if (ppre->flink->flink==NULL)//end
        {ppre->flink=NULL;
         list->rear=ppre;
		}
	 else//middle
	    {ppre->flink->flink->blink=ppre;
	     ppre->flink=ppre->flink->flink;
		}
	}
}
Node* search(int target,lst *list)
{Node *ppre=NULL,*ploc;
 ploc=list->head;
 while(ploc!=NULL && target>ploc->data)
 {ppre=ploc;
  ploc=ploc->flink;
 }
 return ppre;
}
void display(lst *list)
{Node *ploc;
 cout<<"Forward traversal: ";
 ploc=list->head;
 while(ploc!=NULL)
 {cout<<ploc->data<<" ";
  ploc=ploc->flink;
 }
 cout<<"\nReverse traversal: ";
 ploc=list->rear;
 while(ploc!=NULL)
 {cout<<ploc->data<<" ";
  ploc=ploc->blink;
 }
}
int main()
{Node* ppre;
 lst list;
 int data,choice;
 cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit";
 do
 {cout<<"\nEnter choice:";
  cin>>choice;
  switch(choice)
  {case 1:
  	    cout<<"Enter element to be inserted:";
  	    cin>>data;
  	    ppre=search(data,&list);
  	    insert(data,ppre,&list);
  	    break;
  	case 2:
  	    cout<<"Enter element to be deleted:";
  	    cin>>data;
  	    ppre=search(data,&list);
  	    deletenode(ppre,&list);
  	    break;
  	case 3:
  		display(&list);
  		break;
  }
 }while(choice!=4);
}
