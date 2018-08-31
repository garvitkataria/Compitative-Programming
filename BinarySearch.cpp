#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef set<L> S;
typedef set<l> s;

#define limit 32000

void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
int binarySearch2(int input[], int s,int e, int x) 
{
  if(e>=s)
  {
    int mid=(e+s)/2;
    if(input[mid]==x)
    {
      return mid;
    }
    else if(input[mid]>x)
    {
      return binarySearch2(input,s,mid-1,x);
    }
    else if(input[mid]<x)
    {
      return binarySearch2(input,mid+1,e,x);
    }
  }
  return -1;
}
int binarySearch(int input[], int size, int element) 
{
  return binarySearch2(input,0, size-1, element);
}

int main()
{
  int input[100];
  int x,size;
  cin>>size;
  for (int i = 0; i < size; ++i)
  {
    cin>>input[i];
  }
  cin>>x;
  cout<<binarySearch(input, size, x)<<endl;
	return 0;
}