#include<iostream>
using namespace std;
struct node
{int data;
 node* flink;
 node* blink;
};
struct lst
{int count;
 node* front;
 node* rear;
};
void createlist(lst* list)
{list->front=NULL;
 list->rear=NULL;
 list->count=0;
}
void insertnode(int datain,node* ppre,lst* list)
{node* pnew=new node;
 pnew->data=datain;
 list->count+=1;
 if (ppre==NULL)
 {if (list->front==NULL)//empty list
     {cout<<"Empty\n";
      pnew->blink=pnew;
      pnew->flink=pnew;
      list->rear=pnew;
      list->front=pnew;
	 }
  else//first node
     {cout<<"first\n";
	  pnew->blink=list->rear;
      pnew->flink=list->front;
      list->front->blink=pnew;
      list->front=pnew;
      list->rear->flink=pnew;
	 }
 }
 else
 {if (ppre==list->rear)//end
  {cout<<"End\n";
   pnew->flink=ppre->flink;
   pnew->blink=ppre;
   ppre->flink=pnew;
   list->front->blink=pnew;
   list->rear=pnew;
  }
  else
  {cout<<"middle\n";
   pnew->flink=ppre->flink;
   pnew->blink=ppre;
   ppre->flink->blink=pnew;
   ppre->flink=pnew;
  }
 }
}
void deletenode(node* ppre,lst *list)
{if(ppre==NULL)//first node
 {if (list->count==1)
  {list->front=NULL;
   list->rear=NULL;
  }
  else
  {list->front->flink->blink=list->rear;
   list->front=list->front->flink;
   list->rear->flink=list->front;
  }
 }
 else
 {if(ppre->flink==list->rear)//last node
  {list->rear=ppre;
   ppre->flink=list->front;
   list->front->blink=ppre;
  }
  else//middle
  {ppre->flink->flink->blink=ppre;
   ppre->flink=ppre->flink->flink;
  }
 }
 list->count-=1;
}
node* searchnode(lst* list,int target)
{node *ppre=NULL,*ploc;
 int cnt=1;
 ploc=list->front;
 if(ploc!=NULL)
 {while (cnt<=list->count && target>ploc->data)
 {
  cnt++;
  ppre=ploc;
  ploc=ploc->flink;
 }
 }
 return ppre;
}
void display(lst *list)
{node *ploc;
 int cnt=1;
 ploc=list->front;
 cout<<"forward traversal:";
 while (cnt<=list->count)
 {cnt++;
  cout<<ploc->data<<" ";
  ploc=ploc->flink;
 }
 cout<<"\nreverse traversal:";
 cnt=1;
 ploc=list->rear;
 while(cnt<=list->count)
 {cnt++;
  cout<<ploc->data<<" ";
  ploc=ploc->blink;
 }
}
int main()
{lst list;
 createlist(&list);
 node *ppre;
 int data,choice;
 cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit";
 do
 {cout<<"\nEnter choice:";
  cin>>choice;
  switch(choice)
  {case 1:
  	 cout<<"Enter element:";
  	 cin>>data;
  	 ppre=searchnode(&list,data);
  	 if(ppre!=NULL)
  	 {cout<<"search done "<<ppre->data;
	 }
  	 insertnode(data,ppre,&list);
  	 break;
   case 2:
   	 cout<<"Enter element:";
  	 cin>>data;
  	 ppre=searchnode(&list,data);
  	 deletenode(ppre,&list);
  	 break;
   case 3:
   	 display(&list);
   	 break;
  }
 }while(choice!=4);
}
