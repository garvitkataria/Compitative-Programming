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
int subset(int input[], int n, int output[][20]) 
{
  if(n==0)
  {
    output[0][0]=0;
    return 1;
  }    
  int oldSubsetCount=subset(input+1,n-1,output);
  for (int i = 0; i < oldSubsetCount; ++i)
  {
    output[i+oldSubsetCount][0] = 1+output[i][0];
    output[i+oldSubsetCount][1] = input[0];

    for (int j = 2; j <= output[i][0]+1; ++j)
      output[i+oldSubsetCount][j] = output[i][j-1];
  }
  return oldSubsetCount*2;
}

int main()
{
  int input[100];
  int output[100][20];
  int x,size;
  cin>>size;
  for (int i = 0; i < size; ++i)
  {
    cin>>input[i];
  }
  int p=subset(input, size, output);

	for (int i = 0; i < p; ++i)
  {
    for (int j = 0; j <= output[i][0]; ++j)
    {
      cout<<output[i][j]<<' ';
    }cout<<endl;
  }
  return 0;
}