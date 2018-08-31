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

bool checkAb(char S[]) 
{
  if(S[0]=='\0')
    return 1;

  if(S[0]=='a')
  {
    return checkAb(S+1);
  }
  else if(S[0]=='b'&& S[1]=='b')
  {
    if(S[2]=='b')
      return 0;
    return checkAb(S+2);
  }
  else
    return 0;
}
int main()
{

  char S[100];
  cin>>S;
  cout<<checkAb(S)<<endl;
	return 0;
}