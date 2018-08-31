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

int lcs2Helper(string s1, string s2, int m, int n, int** dp) 
{
	if (m == 0 || n == 0) {
		return 0;
	}

	if (dp[m][n] > -1) {
		return dp[m][n];
	}

	int ans;

	if (s1[0] == s2[0]) 
	{
		ans = 1 + lcs2Helper(s1.substr(1), s2.substr(1), m - 1, n - 1, dp);
	}
	else 
	{
		int option1 = lcs2Helper(s1, s2.substr(1) , m, n - 1, dp);
		int option2 = lcs2Helper(s1.substr(1) , s2, m - 1, n, dp);

		ans = max(option1, option2);
	}
	dp[m][n] = ans;
	return ans;
}

int lcs2(string s1, string s2) 
{
	int m = (s1.size());
	int n = (s2.size());

	int** dp = new int*[m + 1];

	for (int i = 0; i <= m; i++) 
	{
		dp[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) 
		{
			dp[i][j] = -1;
		}
	}

	int ans = lcs2Helper(s1, s2, m, n, dp);

	for (int i =0; i <=  m; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	cout << lcs2(a, b) << endl;
	return 0;
}
