#include<iostream>
using namespace std;
/*NOTE:
  WTgraph[][]- a WEIGHT graph in the form of adjacency matrix
  graph[]-contains the vertices of graph
  weight[]- contains the present weights of each edge in graph
  parent[]-stores the final parent (i.e) to which parent vertex each vertex is connected
  mstSET[]-if the vertex is already taken or not 
*/
#define infinite 9999
int n;
char graph[10];
int wtgraph[10][10];
int minwt(int weight[],bool mstSet[])
{int min=infinite,min_index=0;
 for(int i=0;i<n;i++)
 {if (mstSet[i]==false && weight[i]<min)
     {min=weight[i];
      min_index=i;
	 }
 }
 return min_index;
}
void printMST(int parent[])
{cout<<"Edge    weight\n";
 for (int i=1;i<n;i++)
    {
    cout<<graph[parent[i]]<<" to "<<graph[i]<<"- "<<wtgraph[i][parent[i]];
    cout<<"\n";
    }
}
void MST()
{int parent[10];
 int weight[10];
 bool mstSet[10];
 int u;
 for (int i=0;i<n;i++)
 {weight[i]=infinite;
  mstSet[i]=false;
 }
 parent[0]=-1;//sice root node has no parent
 weight[0]=0;//to start from 1st node
 for (int count=0;count<n-1;count++)
 {
 	u=minwt(weight,mstSet);
 	mstSet[u]=true;
 	for (int v=0;v<n;v++)
 	{
 		if (wtgraph[u][v]!=0 && mstSet[v]==false && weight[v]>wtgraph[u][v])
 		{parent[v]=u;
 		 weight[v]=wtgraph[u][v];
		}
	}
 }
 printMST(parent);
}
int main()
{
	cout<<"Enter number of vertices:";
	cin>>n;
	for (int i=0;i<n;i++)
	{cout<<"Enter vertex "<<i+1<<":";
	 cin>>graph[i];
	}
	for (int i=0;i<n;i++)
	{for (int j=0;j<n;j++)
	 {if (i!=j)
	  {cout<<"Enter weight of "<<graph[i]<<" to "<<graph[j];
	  cin>>wtgraph[i][j];
	  }
	 }
	}
	MST();
}
