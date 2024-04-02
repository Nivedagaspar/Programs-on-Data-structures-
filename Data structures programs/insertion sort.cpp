#include<iostream>
using namespace std;
void insertionsrt(int arr[])
{int i,j,key,n=10,hole;
 for (i=1;i<n;i++)
 {key=arr[i];
  hole=i;
  j=i-1;
  while (j>=0 && arr[j]>key)
  {arr[j+1]=arr[j];
   hole=j;
   j--;
  }
  arr[hole]=key;
 }
 cout<<"\nArray sorted by insertion sort is: ";
 for (i=0;i<10;i++)
 {cout<<arr[i]<<" ";
 }
}
void bubblesrt(int arr[])
{int i,j,temp,n=10;
 for (i=0;i<n;i++)
 {for (j=0;j<n-i-1;j++)
  {if (arr[j]>arr[j+1])
   {temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }
 cout<<"\nArray sorted by bubble sort is: ";
 for (i=0;i<10;i++)
 {cout<<arr[i]<<" ";
 }
}
int main()
{int arr[10],i;
 cout<<"Enter elements:\n";
 for (i=0;i<10;i++)
 {cin>>arr[i];
 }
 insertionsrt(arr);
 bubblesrt(arr);
}
