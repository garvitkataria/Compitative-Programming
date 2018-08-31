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
int subsetSumToK(int input[], int n, int output[][20],int k) 
{

    if(n==0)
    {
      if(k==0)
      {
        output[0][0]=0;
        return 1;
      }
      else
        return 0;
    }
  int output1[1000][20]={1};
  int output2[1000][20]={2};
  int n1,n2;

  n1=subsetSumToK(input+1, n-1, output1, k-input[0]);
  n2=subsetSumToK(input+1, n-1, output2, k);

// cout<<'1'<<output1[0][0]<<output1[0][1]<<endl;
// cout<<'2'<<output2[0][0]<<output2[0][1]<<endl;
  for (int i = 0; i < n2; ++i)
  {
    for (int j = 0; j <= output2[i][0]; ++j)
    {
      output[i][j]=output2[i][j];
    }
  }
  for (int i = n2; i < n1+n2; ++i)
  {
    output[i][0]=output1[i-n2][0]+1;
    output[i][1]=input[0];
    for (int j = 1; j <= output1[i-n2][0]; ++j)
    {
      output[i][j+1]=output1[i-n2][j];
    }
  }
  return n1+n2;
}

int main()
{
  int input[100];
  int output[1000][20];
  int x,size,k;
  cin>>size;
  for (int i = 0; i < size; ++i)
  {
    cin>>input[i];
  }
  cin>>k;
  int p=subsetSumToK(input, size, output,k);
  cout<<p<<endl;
	for (int i = 0; i < p; ++i)
  {
    for (int j = 0; j <= output[i][0]; ++j)
    {
      cout<<output[i][j]<<' ';
    }cout<<endl;
  }
  return 0;
}