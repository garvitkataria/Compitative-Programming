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
int N,M;
int editDistanceHelper(string s1, string s2, int m, int n, int** dp)
{
	//base 
	if(m==0)
		return n;
	if(n==0)
		return m;
	//DP
		if(dp[m][n]!=-1)
			return dp[m][n];

	if(s1[0]==s2[0])
		return editDistanceHelper( s1.substr(1),  s2.substr(1), m-1, n-1, dp);

	int c1,c2,c3;
	c1 = 1 + editDistanceHelper( s1.substr(1),  s2.substr(1), m-1, n-1, dp);
	c2 = 1 + editDistanceHelper( s1,  s2.substr(1), m, n-1, dp);
	c3 = 1 + editDistanceHelper( s1.substr(1),  s2, m-1, n, dp);
	dp[m][n]=min(c1,min(c2,c3));
	return dp[m][n];
}
int editDistance(string s1, string s2)
{

	int m,n;
	m=s1.size();
	n=s2.size();
	M=m;
	N=n;
	int **dp = new int* [m+1];
	for (int i = 0; i <= m; ++i)
	{
		dp[i] = new int[n+1];
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	return editDistanceHelper( s1,  s2, m, n, dp);

}
int main() 
{
	string a;
	string b;
	cin >> a;
	cin >> b;
	cout << editDistance(a, b) << endl;
	return 0;
}
