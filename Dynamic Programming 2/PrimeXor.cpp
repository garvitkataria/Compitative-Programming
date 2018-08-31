#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long freq[4505],prime[8193],dp[4505][8195];

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
        
        dp[3499][0]=1;
        
        for (i=3500;i<=4500;i++)
        {
            for (j=0;j<8192;j++)
            {
                if(freq[i]==0)
                 {
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
                
                long long  t=(freq[i])/2+1;
                long long  q=(freq[i]+1)/2;
              	dp[i][j]+=(dp[i-1][j]*t)%MOD;
                dp[i][j]%=MOD;
                dp[i][j]+=(dp[i-1][j^i]*q)%MOD;
                dp[i][j]%=MOD;
             }
        }
        // for (i=0;i<=3;i++)
        // {    
        // 	for (j=0;j<8;j++)
        //     {
        //     	cout<<dp[i][j]<<" ";
        //     }	
        // 	cout<<endl;
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
            	ans=(ans+dp[4500][i])%MOD;  
            		// cout<<i<<"-"<<dp[4500][i]<<endl;
            }

        }
        cout<<endl;
        
        cout<<ans<<endl;
    }
}