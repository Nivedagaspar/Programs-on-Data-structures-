#include<iostream>
using namespace std;
struct node
{int data;
 node* leftlink;
 node* rightlink;
}*head;
class queue
{node* q[100];
 int f,r;
 public:
 queue()
 {f=r=-1;
 }
 void enqueue(node* x)
 {q[++r]=x;
  if (f==-1)
  {f++;
  }
 }
 node* dequeue()
 {return q[f++];
 }
 int isempty()
 {if (f==-1 || f>r)
     return 1;
  else
     return 0;
 }
};
node* insertnode(node* nd,int datain)
{if (nd==NULL)
 {node* pnew=new node;
  pnew->data=datain;
  pnew->leftlink=NULL;
  pnew->rightlink=NULL;
  if (head==NULL)
     head=pnew;
  return pnew;
 }
 if (datain<nd->data)
    {nd->leftlink=insertnode(nd->leftlink,datain);
	}
 else
    {nd->rightlink=insertnode(nd->rightlink,datain);
	}
}
void inorder(node* nd)
{if (nd!=NULL)
     {inorder(nd->leftlink);
      cout<<nd->data<<" ";
      inorder(nd->rightlink);
	 }
}
void preorder(node* nd)
{if (nd!=NULL)
     {cout<<nd->data<<" ";
	  preorder(nd->leftlink);
      preorder(nd->rightlink);
	 }
}
void postorder(node* nd)
{if (nd!=NULL)
     {
	  postorder(nd->leftlink);
      postorder(nd->rightlink);
      cout<<nd->data<<" ";
	 }
}
void bftraversal(node* nde)
{node* nd=head;
 queue q;
 while (nd!=NULL)
 {cout<<nd->data<<" ";
  if (nd->leftlink!=NULL)
     {q.enqueue(nd->leftlink);
	 }
  if (nd->rightlink!=NULL)
     {q.enqueue(nd->rightlink);
	 }
  if (!q.isempty())
     {nd=q.dequeue();
	 }
  else
     {nd=NULL;
	 }
 }
}
void searchnode(node* nd,int datain)
{if (nd!=NULL)
     {if (nd->data==datain)
         {cout<<"Found";
          return;
		 }
	  else if (datain<nd->data)
	     {searchnode(nd->leftlink,datain);
		 }
	  else if (datain>nd->data)
	     {searchnode(nd->rightlink,datain);
		 }
	 }
 else
    {cout<<"Not found";
     return;
	}
}
node* minnode(node* nd)
{node* min=nd;
 while(min->leftlink!=NULL)
 {min=min->leftlink;
 }
 return min;
}
node* deletenode(node* nd,int target)
{if (nd==NULL)
    return nd;
 else
   {if (target<nd->data)
       {nd->leftlink=deletenode(nd->leftlink,target);
	   }
	else if (target>nd->data)
       {nd->rightlink=deletenode(nd->rightlink,target);
	   }
	else//dltnode found
	   {if (nd->leftlink==NULL && nd->rightlink==NULL)
	       {return NULL;
		   }
		else if (nd->leftlink==NULL)
		   {node* temp=nd->rightlink;
		    //free(nd);
		    return temp;
		   }
		else if (nd->rightlink==NULL)
		   {node* temp=nd->leftlink;
		    //free(nd);
		    return temp;
		   }
		else
		   {node* temp=minnode(nd->rightlink);
		    nd->data=temp->data;
		    nd->rightlink=deletenode(nd->rightlink,temp->data);
		   }
	   }
   }
   return nd;
}
int main()
{int n,data;
 int choice;
 cout<<"Enter number of items:";
 cin>>n;
 for (int i=0;i<n;i++)
 {cout<<"Enter el"<<i+1<<": ";
  cin>>data;
  insertnode(head,data);
 }
 cout<<"Preorder traversal:";
 preorder(head);
 cout<<"\nInorder traversal:";
 inorder(head);
 cout<<"\nPostorder traversal:";
 postorder(head);
 do
 {cout<<"\n1.search\n2.delete\n3.Display\n4.exit\n";
  cin>>choice;
  switch(choice)
  {case 1:
  	cout<<"\nEnter search el: ";
    cin>>data;
    searchnode(head,data);
    break;
   case 2:
   	cout<<"\nEnter delete el: ";
    cin>>data;
    deletenode(head,data);
    break;
   case 3:
   	bftraversal(head);
   	break;
  }
 }while(choice!=4);
}
