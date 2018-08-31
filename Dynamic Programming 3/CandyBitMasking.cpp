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
int solve(int like[][30],int N)
{
	int dp[(1<<N)]; //1000
	dp[(1<<N)-1] = 1;//111

	for (int mask = (1<<N)-2; mask >=0; mask--)
	{
		int temp=mask;
		int count=0;// persons assigned
		while(temp>0)
		{
			int lastdigit = temp&1;
			count+=lastdigit;
			temp=temp/2;
		}
		dp[mask]=0;
		for (int i = 0; i < N; ++i)
		{
			if( like[count][i] && !(mask & (1<<i)) )//likes the candy and ith candy is not set
			{
				dp[mask] += dp[mask|(1<<i)];
			}
		}


	}
	return dp[0];
}
int main()
{
	int n=3;
	int like[30][30];
	cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
					cin>>like[i][j];
			}
		}
	cout<<solve(like,n)<<endl;
	return 0;
}