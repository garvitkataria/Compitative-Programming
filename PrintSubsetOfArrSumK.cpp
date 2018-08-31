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
void PrintsubsetSumToK(int input[], int n, int output[],int k,int i) 
{

    if(n==0)
    {
      if(k==0)
      {
        for (int i = 1; i <= output[0]; ++i)
          cout<<output[i]<<' ';
        cout<<endl;
        return;
      }
      else
        return;
    }
  PrintsubsetSumToK(input+1, n-1, output, k,i);
  output[0]=i;
  output[i]=input[0];
  PrintsubsetSumToK(input+1, n-1, output, k-input[0],i+1);
}

int main()
{
  int input[100];
  int output[20];
  output[0]=0;
  int x,size,k;
  cin>>size;
  for (int i = 0; i < size; ++i)
  {
    cin>>input[i];
  }
  cin>>k;
  PrintsubsetSumToK(input, size, output,k,1);
  
  return 0;
}