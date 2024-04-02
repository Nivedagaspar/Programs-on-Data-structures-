#include<iostream>
using namespace std;
int binarysrch(int arr[],int ele,int beg,int end)
{int mid;
 if(beg>end)
 {return 0;
 }
 else
 {mid=(beg+end)/2;
  if (arr[mid]==ele)
  {return 1;
  }
  else if(arr[mid]>ele)
  {return binarysrch(arr,ele,beg,mid-1);
  }
  else if(arr[mid]<ele)
  {return binarysrch(arr,ele,mid+1,end);
  }
 }
}
int main()
{int arr[10],ele,found;
 cout<<"Enter elements:";
 for(int i=0;i<10;i++)
 {cin>>arr[i];
 }
 cout<<"Enter element to be searched:";
 cin>>ele;
 found=binarysrch(arr,ele,0,9);
 if(found==1)
    cout<<"Found";
 else
    cout<<"Not found";
}
