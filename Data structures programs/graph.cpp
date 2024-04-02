#include<iostream>
using namespace std;
struct node
{char id;
 node* link;
};
struct Gnd
{char id;
 int visited;
 node* eptr;
};
class queue
{char q[10];
 int f,r;
 public:
 queue()
 {f=r=-1;
 }
 int isempty()
 {if (f==-1 ||f>r)
     {return 1;
	 }
  else
     {return 0;
	 }
 }
 void enqueue(char x)
 {if (f==-1)
     {f++;
	 }
  q[++r]=x;
 }
 char dequeue()
 {
  return q[f++];
 }
 int in_queue(char x)
 {int presence=0;
  for (int i=0;i<=r;i++)
    {if (q[i]==x)
        {presence=1;
		}
	}
  return presence;
 }
};
class stack
{char s[10];
 int top;
 public:
 stack()
 {top=-1;
 }
 int isempty()
 {if (top==-1)
     {return 1;
	 }
  else
     {return 0;
	 }
 }
 void push(char x)
 {
  s[++top]=x;
 }
 char pop()
 {return s[top--];
 }
 int in_stack(char x)
 {int presence=0;
  for (int i=0;i<=top;i++)
    {if (s[i]==x)
        {presence=1;
		}
	}
  return presence;
 }
};
class graph
{Gnd gnode[10];
 int n;
 public:
 void initialise()
 {for (int i=0;i<n;i++)
  {gnode[i].eptr=NULL;
   gnode[i].visited=0;
  }
 }
 void constructgraph()
 {int nadj;
  cout<<"Enter number of vertices:";
  cin>>n;
  initialise();
  for (int i=0;i<n;i++)
  {cout<<"Enter vertex "<<i+1<<": ";
   cin>>gnode[i].id;
   cout<<"Enter number of adjecent vertices for "<<gnode[i].id<<": ";
   cin>>nadj;
   for (int j=0;j<nadj;j++)
   {node* pnew=new node;
    cout<<"Enter id of adj "<<j+1<<": ";
    cin>>pnew->id;
    pnew->link=gnode[i].eptr;
    gnode[i].eptr=pnew;
   }
  }
 }
 void display()
 {node* ploc;
  for (int i=0;i<n;i++)
  {cout<<gnode[i].id<<"-->";
   ploc=gnode[i].eptr;
   while (ploc!=NULL)
   {
    cout<<ploc->id<<"  ";
    ploc=ploc->link;
   }
   cout<<"\n";
  }
 }
 int srchgraph(char x)
 {int idx=-1;
  for (int i=0;i<n;i++)
  {if (gnode[i].id==x)
      {idx=i;
	  }
  }
  return idx;
 }
 void BFS(int x)
 {queue q;
  char u;
  node* ploc;
  int idx;
  for (int i=0;i<n;i++)
  {gnode[i].visited=0;
  }
  q.enqueue(gnode[x].id);
  cout<<"BFS: ";
  while(!q.isempty())
  {
   u=q.dequeue();
   cout<<u<<" ";
   gnode[srchgraph(u)].visited=1;
   ploc=gnode[srchgraph(u)].eptr;
   while(ploc!=NULL)
   {
    idx=srchgraph(ploc->id);
    if (q.in_queue(ploc->id)!=1 && gnode[idx].visited!=1)
       {
	    q.enqueue(gnode[idx].id);
	   }
	ploc=ploc->link;
   }
  }
  for (int i=0;i<n;i++)
  {if (gnode[i].visited==0)
      {cout<<gnode[i].id<<" ";
	  }
  }
 }
 void DFS(int x)
 {stack stk;
  char u;
  node* ploc;
  int idx;
  for (int i=0;i<n;i++)
  {gnode[i].visited=0;
  }
  stk.push(gnode[x].id);
  cout<<"DFS: ";
  while(!stk.isempty())
  {
   u=stk.pop();
   cout<<u<<" ";
   gnode[srchgraph(u)].visited=1;
   ploc=gnode[srchgraph(u)].eptr;
   while(ploc!=NULL)
   {
    idx=srchgraph(ploc->id);
    if (stk.in_stack(ploc->id)!=1 && gnode[idx].visited!=1)
       {
	    stk.push(gnode[idx].id);
	   }
	ploc=ploc->link;
   }
  }
  for (int i=0;i<n;i++)
  {if (gnode[i].visited==0)
      {cout<<gnode[i].id<<" ";
	  }
  }
 }
};
int main()
{graph G;
 int op,i;
 G.constructgraph();
 G.display(); // To display adjacency list
 do
 {
 cout << endl<<"1- BFS 2- DFS 3- Exit \nEnter your option " << endl;
 cin >> op;
 switch (op)
 {case 1:
   cout << "Enter the index of starting vertex " ;
   cin >> i;
   cout<<"############ BFS ###############"<<endl;
   G.BFS(i);
   break;
  case 2:
   cout << "Enter the index of starting vertex " ;
   cin >> i;
   cout<<"############ DFS ###############"<<endl;
   G.DFS(i);
   break;
}
}
while (op != 3);
}
