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
int AlokNathHelper(string s1, string s2, int m , int n, int l ,int*** dp)
{

	//base 
	if(l==0)
		return 0;
	if(m>0 && n>0)
	{
		// if(dp[m][n][l]!=-1)
		// 	return dp[m][n][l];
		int c1,c2,c3;
		if(s1[0]==s2[0])
		{
			c1 = (int)s1[0] + AlokNathHelper( s1.substr(1),  s2.substr(1), m-1, n-1,l-1 ,dp);
			c2 = AlokNathHelper( s1.substr(0),  s2.substr(1), m, n-1,l, dp);
			c3 = AlokNathHelper( s1.substr(1),  s2.substr(0), m-1, n,l, dp);
			dp[m][n][l] = max(c1,max(c2,c3));
			return dp[m][n][l];
		}

		c2 = AlokNathHelper( s1.substr(0),  s2.substr(1), m, n-1,l, dp);
		c3 = AlokNathHelper( s1.substr(1),  s2.substr(0), m-1, n,l, dp);
		dp[m][n][l] = max(c2,c3);
		return dp[m][n][l];
	}	
	return INT_MIN;
}
int AlokNath(string s1, string s2, int l)
{

	int m,n;
	m=s1.size();
	n=s2.size();

	int ***dp = new int** [m+1];
	for (int i = 0; i <= m; ++i)
	{
		dp[i] = new int* [n+1];
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j] = new int[l+1];	
			for (int k = 0; k <= l; ++k)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	int ans = AlokNathHelper( s1,  s2, m, n, l, dp);
	if(ans<0)
		ans=0;
	return ans;

}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		string b;
		int k;
		cin >> a;
		cin >> b;
		cin >> k;
		cout << AlokNath(a, b, k) << endl;
	}
	
	return 0;
}
