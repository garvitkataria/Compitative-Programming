#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
int partition(int input[],int s,int e)
{
	int p = input[s];
	int count=0;
	for (int i = s+1; i <= e; ++i)
	{
		if(p>input[i])
			count++;
	}
	input[s]=input[s+count];
	input[s+count]=p;
	
	int temp;
	int j=e;
	for (int i = s; i < s+count; ++i)
	{
		if(input[i]>=p)
		{
			while(input[j]>=p)
				j--;

				temp=input[j];
				input[j]=input[i];
				input[i]=temp;
		}
	}
	return s+count;
}
void quickSort(int input[],int s,int e)
{
  int c;
  if(s < e)
  {
  	c = partition(input,s,e);
	quickSort(input,s,c-1);
	quickSort(input,c+1,e);
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
  	quickSort(input,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<input[i]<<' ';
	}
	cout<<endl;
	return 0;
}