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

void PrintVector(v arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
v longestSubsequence(int *arr, int n)
{
  set<int> S;
    int ans = 0;
    int start=0,s=0;

    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    for (int i=0; i<n; i++)
    {
        if (S.find(arr[i]-1) == S.end())
        {
            
            int j = arr[i];
            while (S.find(j) != S.end())
              j++;
            if((ans < j - arr[i]))
            {
              start=arr[i];
              ans = j - arr[i];
              // cout<<start<<ans<<endl;
            }
        }
    }
    set <int> :: iterator itr;
    v A;
    itr=S.find(start);
  for (int i = 0; i < ans; ++i)
  {
    A.push_back(*itr);
    itr++;
  }
    return A;
}
int main()
{
  int t,N,C,temp;
  int A[1000];
  v B;
  cin>>N;
  for (int i = 0; i < N; ++i)
  {
    cin>>temp;
    A[i]=temp;
  }
  // cout<<longestSubsequence(A,N)<<endl;
  B = longestSubsequence(A,N);
  PrintVector(B);
  return 0;
}