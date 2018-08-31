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
int BS(V a, l s, l e, l C, l N)
{
  l mid=(s+e)/2;
   // cout<<s<<' '<<e<<' '<<mid<<endl;
  int count,j;
  if(s<=e)
  {
    count=1;
    j=0;
    for (int i = 0; i < a.size(); ++i)
    {
      if(a[i]-a[j]>=mid)
      {
        count++;
         // cout<<"count "<<count<<endl;
        j=i;
      }  
    }
     // cout<<"HI"<<s<<' '<<e<<' '<<count<<endl;
    if(s==e && count<C)
    {
      // cout<<"HI";
      return s-1;
    }
    if(s==e && count>=C)
    {
      // cout<<"HI";
      return s;
    }

    if(count>=C)
      return BS(a,mid+1,e,C,N);
    return BS(a,s,mid-1,C,N);
  }

}
int main()
{
  int t,N,C,temp;
  V A;
  cin>>t;
  while(t--)
  {
    cin>>N>>C;

    for (int i = 0; i < N; ++i)
    {
      cin>>temp;
      A.push_back(temp);
    }
    sort(A.begin(),A.end());
    int initialDis = 0;
    int lastDis = A[N-1] - A[0];
    cout<<BS(A,initialDis,lastDis,C,N)<<endl;
    A.clear();
    // PrintVector(A);
  }
  return 0;
}