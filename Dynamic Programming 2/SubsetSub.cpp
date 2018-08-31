#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* val,int n,int sum){

	bool** dp = new bool*[2];
	for(int i=0;i<=1;i++){
		dp[i] = new bool[sum+1];
	}

	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag = 1;

	for(int i=1;i<=n;i++)
	{
		// cout<<i<<endl;
		for(int j=0;j<=sum;j++){

			dp[flag][j] = dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-val[i-1]];
				// cout<<dp[flag][j]<<" "<<j<<dp[flag^1][j]<<dp[flag^1][j-val[i-1]]<<j-val[i-1]-1<<endl;
			}
		}
		
		// for(int k=0;k<=sum;k++)
		// 	cout<<dp[flag][k]<<" ";
		// cout<<endl;

		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][sum];
	// delete dp array
	return ans;
}
int main()
{
	int val[10000],n,sum;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>val[i];
	}
	cin>>sum;
	if(subsetSum(val,n,sum))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;	
	return 0;
}