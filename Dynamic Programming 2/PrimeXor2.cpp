#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long freq[4505],prime[8193],dp[2][8195];

void sieve()
{
    int i,j;
    prime[1]=1;
    prime[0]=1;
    for (i=2;i*i<=8192;i++)
    {
        if(prime[i])
            continue;
        for (j=2*i;j<=8192;j+=i)
        prime[j]=1;
    }
}

int main()
{
    int Q;
    sieve();
    scanf("%d",&Q);
    
    while(Q--)
    {
        memset(freq,0,sizeof(freq));
        memset(dp,0,sizeof(dp));
        int N;
        cin>>N;

        int i,j;
        for (i=0;i<N;i++)
        {
            int x;
            cin>>x;
            freq[x]++;
        }
        
        dp[0][0]=1;
        
        for (i=3500;i<=4500;i++)
        {
            for (j=0;j<8192;j++)
            {
                if(freq[i]==0)
                 {
                    dp[1][j]=dp[0][j];
                    continue;
                }
                
                long long  t=(freq[i])/2+1;
                long long  q=(freq[i]+1)/2;
                dp[1][j]+=(dp[0][j]*t)%MOD;
                dp[1][j]%=MOD;
                dp[1][j]+=(dp[0][j^i]*q)%MOD;
                dp[1][j]%=MOD;
             }
             for (int k = 0; k < 8192; ++k)
             {
                 dp[0][k]=dp[1][k];
                 dp[1][k]=0;
             }
             // for (int k = 0; k <= 4; ++k)
             // {
             //     cout<<dp[0][k]<<" ";
             // }cout<<endl;
        }
        // for (i=0;i<=3;i++)
        // {    
        //  for (j=0;j<=4;j++)
        //     {
        //      cout<<dp[i][j]<<" ";
        //     }    
        //  cout<<endl;
        // }
        long long ans=0;
        
        // for (i=1;i<=8192;i++)
        // {
        //     cout<<dp[4500][i]<<' '  ;
        // }cout<<endl;

        for (i=1;i<=8192;i++)
        {
            if(!prime[i])
            {
                ans=(ans+dp[0][i])%MOD;  
                    // cout<<i<<"-"<<dp[4500][i]<<endl;
            }

        }
        //cout<<endl;
        
        cout<<ans<<endl;
    }
}