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
V removeDup(V A)
{
  V B;
  l flag;
  for (int i = 0; i < A.size(); ++i)
  {
    flag=1;
    for (int j = 0; j < B.size(); ++j)
    {
      if(A[i]==B[j])
        flag=0;
    }
    if(flag==1)
      B.push_back(A[i]);
  }
  return B;
}
int main()
{
  int n;
  V A;
  l temp;
  cin>>n;
  for (int i = 0; i < n; ++i)
  {
    cin>>temp;
    A.push_back(temp);
  }
  removeDup(A);
  PrintVector(A);
	return 0;
}