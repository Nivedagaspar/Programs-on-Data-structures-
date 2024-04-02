#include<iostream>
using namespace std;
struct Node
{int data;
 Node* link;
}*arr[101];
void createlist(int sze)
{for(int i=0;i<sze;i++)
 {arr[i]=NULL;
 }
}
void insert(int datain,int sze)
{Node* pnew=new Node;
 pnew->data=datain;
 pnew->link=NULL;
 int loc=datain%sze;
 if (arr[loc]==NULL)
 {arr[loc]=pnew;
 }
 else
 {pnew->link=arr[loc]->link;
  arr[loc]->link=pnew;
 }
}
void deletenode(Node* ppre,int loc)
{if (ppre==NULL)
    {arr[loc]=arr[loc]->link;
	}
 else
   {ppre->link=ppre->link->link;
   }
}
Node* searchdlt(int target,int *loc,int sze)
{*loc=target%sze;
 Node* ppre=NULL;
 Node* ploc;
 ploc=arr[*loc];
 while(ploc!=NULL && ploc->data!=target)
 {ppre=ploc;
  ploc=ploc->link;
 }
 return ppre;
}
void search(int sze,int target)
{int j;
 Node* ploc;
 int loc=target%sze;
 ploc=arr[loc];
 while(ploc!=NULL)
 {if (target==ploc->data)
     {cout<<"found at index "<<loc<<" at pos "<<j;
      break;
	 }
  ploc=ploc->link;
  j++;
 }
}
void display(int sze)
{Node* ploc;
 for (int i=0;i<sze;i++)
 {if (arr[i]!=NULL)
     {ploc=arr[i];
      while(ploc!=NULL)
      {cout<<ploc->data<<" ";
       ploc=ploc->link;
	  }
	 }
  cout<<"\n";
 }
}
int main()
{int data,choice,loc,sze;
 Node* ppre;
 cout<<"Enter size:";
 cin>>sze;
 createlist(sze);
 cout<<"1.Insert\n2.Delete\n3.Search\n4.display";
 do
 {cout<<"\nEnter choice:";
  cin>>choice;
  switch(choice)
  {case 1:
  	     cout<<"Enter element:";
  	     cin>>data;
  	     insert(data,sze);
  	     break;
  	case 2:
  		cout<<"Enter element:";
  	    cin>>data;
  	    ppre=searchdlt(data,&loc,sze);
  	    deletenode(ppre,loc);
  	    break;
  	case 3:
  		cout<<"Enter element:";
  	    cin>>data;
  	    search(sze,data);
  	    break;
  	case 4:
  		display(sze);
  		break;	 
  }
 }while(choice!=5);
}
