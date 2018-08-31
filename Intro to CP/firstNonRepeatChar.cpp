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
char nonRepeatingCharacter(string S)
{
  map<char,int> A;
  for (int i = 0; i < S.length(); ++i)
  {
    A[S[i]]+=1;
  }
  for (int i = 0; i < S.length(); ++i)
  {
    if(A[S[i]]==1)
      return S[i];
    // cout<<S[i]<<A[S[i]]<<endl;
  }
  return S[0];
}

int main()
{

  string S;
  cin>>S;
  cout<<nonRepeatingCharacter(S)<<endl;
	return 0;
}