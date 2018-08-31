#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000

void merge(int input[],int s,int mid,int e)
{
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
	if(arr1[i]>arr2[j])
	{
	  input[k]=arr2[j++];
	}
	else
	{
	  input[k]=arr1[i++];
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

}
void mergeSort(int input[],int s,int e)
{
  int mid=(s+e)/2;
  if(s < e)
  {
	mergeSort(input,s,mid);
	mergeSort(input,mid+1,e);
	merge(input,s,mid,e);
  }
}
int main()
{
	int input[100];
	l n;
	cin>>n;
	l temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		input[i]=temp;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<input[i]<<' ';
	}
	cout<<endl;
  	mergeSort(input,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<input[i]<<' ';
	}
	cout<<endl;
	return 0;
}