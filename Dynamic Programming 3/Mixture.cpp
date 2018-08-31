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

int CSum(int* p, int a, int b)
{
	int ans=0;
	for (int i = a; i <= b; ++i)
	{
		ans+=p[i];
		ans%=100;
	}

	return ans;
}
//dp stores Smoke
int mcmHelper(int* p, int **dp, int i, int j)
{
	if(i==j)
		return 0;

	if(dp[i][j] != -1 )
		return dp[i][j];

	int ans=0, minAns=INT_MAX;

	for (int k = i; k < j; ++k)//1,2,3
	{
		ans =  mcmHelper(p,dp,i,k) + mcmHelper(p,dp,k+1 ,j) + CSum(p,i,k)*CSum(p,k+1,j);
		minAns = min(ans,minAns);

	}
	// cout<<"Min"<<minAns<<endl;
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
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	cout<<mcm(p,n)<<endl;
	return 0;
}