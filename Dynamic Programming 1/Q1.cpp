#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef vector< pair<L,L> > Y;
#define limit 32000
#define MAX 1000001
#define MOD 1000000007
#define mod 1000000006
#define pb push_back
#define mp make_pair

// int kadane(V A)
// {
//     int current_best=1;
//     int best_sum=1;
//     for (int i = 0; i < A.size()-1; ++i)
//     {
//        // cout<<i<<endl;
//         best_sum=1;
//         //cout<<best_sum<<current_best<<endl;
        
//         for (int j = i+1; j < A.size(); ++j)
//         {
//             if(A[i]>=A[j]) 
//             {
//                 best_sum=j-i+1;
//             }
//             current_best=max(current_best,best_sum);
//         }
//     }
//     return current_best;
// }

int kadane(V A,int s,int e, int**dp)
{
    if(dp[s][e]!=-1)
        return dp[s][e];

    if(A[s] >= A[e])
    {
        return e-s+1;
    }

    int ans=0,ans1=0,ans2=0;
    ans1 = kadane(A,s,e-1,dp);
    ans2 = kadane(A,s+1,e,dp);
    ans = max(ans1,ans2);
   // cout<<ans<<ans1<<ans2<<endl;
    dp[s][e] = ans;

    return ans;
}
int main()
{
    l n,temp,t;
    V A;
    cin>>t;
    while(t--)
    {
       cin>>n;
        for (int i = 0; i < n; ++i)
        {
            cin>>temp;
            A.pb(temp);
        }
        int**dp = new int*[n];
        for (int i = 0; i < n; ++i)
        {
            dp[i] = new int[n];
            for (int j = 0; j < n; ++j)
            {
                dp[i][j]=-1;
            }
        }

        cout<<kadane(A,0,n-1,dp)<<endl; 
        A.clear();
    }
    
	return 0;
}