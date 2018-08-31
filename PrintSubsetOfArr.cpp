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
void Printsubset(int input[], int n, int output[],int i) 
{
  // cout<<input[0]<<input[1]<<input[2]<<endl;
  if(n==0)
  {
    for (int i = 1; i <= output[0]; ++i)
      cout<<output[i]<<' ';
    cout<<endl;
    return ;
  }
  Printsubset( input+1,  n-1,output,i);
  output[0]=i;
  output[i]=input[0];
  // cout<<"text"<<input[0]<<endl;
  Printsubset( input+1,  n-1,output,i+1); 
}

int main()
{
  int input[100];
  int output[20];
  output[0]=0;
  int x,size;
  cin>>size;
  for (int i = 0; i < size; ++i)
  {
    cin>>input[i];
  }

  Printsubset(input, size,output,1);
  return 0;
}