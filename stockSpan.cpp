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
int Final[10000];
int* stockSpan(int *price, int size) 
{
  stack<int> S;
  S.push(0);
  Final[0]=1;
  for (int i = 1; i < size; ++i)
  {
    while(!S.empty() && price[S.top()]< price[i])
      S.pop();

    if(S.empty())
      Final[i]=i+1;
    else
      Final[i]=i-S.top();
    S.push(i);
  }
  return Final;
}

int main()
{
  int size,price[10000];
  cin>>size;
  for (int i = 0; i < size; ++i)
    cin>>price[i];

  int *K=stockSpan(price, size);
  for (int i = 0; i < size; ++i)
    cout<<K[i]<<' ';
  cout<<endl;
  return 0;
}