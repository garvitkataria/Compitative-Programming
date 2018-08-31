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

int main()
{
  L t,N,C,temp;
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
    int s = 0;//toffee
    int e = A[N-1];//toffee
    l mid;
    L count;
    while(s <= e)
    {
      mid=(s+e)/2;
      cout<<s<<' '<<e<<' '<<mid<<endl;
        count=0;//children
        for (int i = 0; i < N; ++i)
        {
          count+=A[i]/mid;
        }
        // cout<<"count: "<<count<<endl;
        if(count >= C)
            s=mid+1;

        if(count < C)
            e=mid-1; 
    }
    if(count<C)
      cout<<mid-1<<endl;
    else
      cout<<mid<<endl;
    A.clear();
  }
  return 0;
}