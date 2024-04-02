#include<iostream>
using namespace std;
void bubblesort(int* arr,int sze)
{int sorted=0,temp;
 int current=sze-1,walker;
 while(current>=0 && sorted==0)
 {sorted=1;
  walker=0;
  while(walker<current)
  {if (*(arr+walker)>*(arr+walker+1))
      {sorted=0;
       temp=*(arr+walker);
       *(arr+walker)=*(arr+walker+1);
       *(arr+walker+1)=temp;
	  }
	walker++;
  }
  current--;
 }
}
int main()
{int arr[10],sze;
 cout<<"Enter size:";
 cin>>sze;
 cout<<"Enter elements one by one:\n";
 for(int i=0;i<sze;i++)
  {cin>>arr[i];
  }
 bubblesort(arr,sze);
 cout<<"Sorted elements: ";
 for(int i=0;i<sze;i++)
  {cout<<arr[i]<<" ";
  }
}
