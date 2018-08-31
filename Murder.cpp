#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000

int merge(int input[],int s,int mid,int e)
{
  int c=0;
  //preprocess
  int m=mid-s+1;
  int n=e-mid;
  int arr1[m];
  int arr2[n];
  int i=0;
  int j=0;
  int k=0;

  for (int k = s; k <= mid; ++k)
  	arr1[i++]=input[k];
  for (int k = mid+1; k <= e; ++k)
  	arr2[j++]=input[k];

  //merge
	i=0;j=0;k=s;
  while(i<m && j<n)
  {
	if(arr1[i]>=arr2[j])
	{
	  input[k]=arr2[j++];
	}
	else
	{
		c+=arr1[i]*(n-j);
	  	input[k]=arr1[i++];
	  	// cout<<c<<endl;
	}
	k++;
  }
  while(i<m)
  {
	input[k++]=arr1[i++];
  }
  while(j<n)
  {
	input[k++]=arr2[j++];
  }
  return c;
}
int mergeSort(int input[],int s,int e)
{
  int count1=0;
  int count2=0;
  int count3=0;
  int mid=(s+e)/2;
  if(s < e)
  {
	count1=mergeSort(input,s,mid);
	count2=mergeSort(input,mid+1,e);
	count3=merge(input,s,mid,e);
	 cout<<count1<<count2<<count3<<endl;
	return count1+count2+count3;
  }
  return 0;
}
int main()
{
	int input[10000];
	l n,t;
	cin>>t;
	l temp;
	while(t--)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			input[i]=temp;
		}
	  	cout<<mergeSort(input,0,n-1);
		cout<<endl;
	}
	return 0;
}