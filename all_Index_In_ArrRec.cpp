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


int allIndexes(int input[], int size, int x, int output[],int index) 
{
  if(size==0)
  {
    return 0;
  }
  if(input[0]==x)
  {
    output[0]=index;
    return 1+allIndexes(input+1,size-1,x,output+1,index+1);
  }
  return allIndexes(input+1,size-1,x,output,index+1);
}
int allIndexes2(int input[], int size, int x, int output[]) 
{
  return allIndexes( input,  size,  x,  output, 0);
}
int main()
{
  int input[100],output[100];
  int x,size;
  cin>>size;
  for (int i = 0; i < size; ++i)
  {
    cin>>input[i];
  }
  cin>>x;
  cout<<allIndexes2(input, size, x, output)<<endl;
  for (int i = 0; i < size; ++i)
  {
    cout<<output[i]<<' ';
  }cout<<endl;
	return 0;
}