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

int knapsnackItrOptimized(int* val,int* wt,int W,int n)
{
	// int** dp = new int*[n+1];
	// for(int i=0;i<=n;i++){
	// 	dp[i] = new int[W+1];
	// }
	int* dp_prev = new int[W+1];
	int* dp_current = new int[W+1];

	for(int i=0;i<=W;i++)
	{
		dp_current[i] = dp_prev[i] = 0;
	}

	// for(int i=0;i<=n;i++){
	// 	dp[i][0] = 0;
	// }

	for(int i=1;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(wt[i-1] <= w)
				dp_current[w] = max(dp_prev[w], val[i-1] + dp_prev[w-wt[i-1]]);
			else 
				dp_current[w] =  dp_prev[w];
		}
		for(int j=0;j<=W;j++)
		{
			dp_prev[j] = dp_current[j];
		}
		
	}

	int ans = dp_current[W];
	//delete dp array 
	return ans;
}
int knapsnackItr(int* val,int* wt,int W,int n){
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(wt[i-1] <= w)
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			else 
				dp[i][w] = dp[i-1][w];
		}
	}

	int ans = dp[n][W];
	//delete dp array 
	return ans;
}

int knapsackHelper(int* weights, int* values, int n, int maxWeight, int **dp)
{
	if(n==0)
		return 0;

	if(dp[n][maxWeight]!=-1)
		return dp[n][maxWeight];
	int c1,c2;

	if(weights[n-1] <= maxWeight)
	{
		c1 = values[n-1] + knapsackHelper(weights,values,n-1,maxWeight-weights[n-1],dp);
		c2 = knapsackHelper(weights,values,n-1,maxWeight,dp);
		dp[n][maxWeight] = max(c1,c2);
		return dp[n][maxWeight];
	}
	c1 = knapsackHelper(weights,values,n-1,maxWeight,dp);
	dp[n][maxWeight] = c1;
	return dp[n][maxWeight];
}

int knapsack(int* weights, int* values, int n, int maxWeight)
{


	int **dp = new int* [n+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = new int[maxWeight+1];
		for (int j = 0; j <= maxWeight; ++j)
		{
			dp[i][j]=-1;
		}
	}
	return knapsackHelper(weights,values,n,maxWeight,dp);
}

int main()
{
	int n,w[100],v[100],maxW;
	cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>w[i];
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	cin>>maxW;
	cout<<knapsack(w,v,n,maxW)<<endl;
	return 0;
}