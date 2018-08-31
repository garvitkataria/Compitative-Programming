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

int mcmHelper(int* p, int **dp, int i, int j)
{
	// cout<<i<<j<<endl;
	if(i==j-1)
		return 0;

	if(dp[i][j] != -1 )
	{
		 //cout<<"Overload"<<endl;
		return dp[i][j];
	}
	int ans=0 , minAns=INT_MAX;
	for (int k = i+1; k < j; ++k)//1,2,3
	{
		ans =  mcmHelper(p,dp,i,k) + mcmHelper(p,dp,k ,j) + p[i]*p[j]*p[k];
		minAns = min(ans,minAns);

	}
	 //cout<<minAns<<endl;
	dp[i][j] = minAns;
	return dp[i][j];
}

int mcm(int* p, int n)
{
	int **dp = new int*[n+1];
	for (int i = 0; i < n+1; ++i)
	{	
		dp[i] = new int[n+1]();
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j]=-1;
		}
	}

	return mcmHelper(p, dp, 0, n-1);
}

int main()
{
	int p[1000],n;
	cin>>n;
	for (int i = 0; i < n+1; ++i)
	{
		cin>>p[i];
	}
	cout<<mcm(p,n+1)<<endl;
	return 0;
}