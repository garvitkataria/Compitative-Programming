#include<bits/stdc++.h>
#define MOD 1000000007
#define max2(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;

map<L, L> dp;
string s;
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
L decodePatterns(L i)
{
	if(s[i]=='0')
	{
		return dp[i-2];
	}
	if(i==0||i==-1)
	{
		return 1;
	}
	else if( (s[i-1]-'0')*10+(s[i]-'0') > 9 && (s[i-1]-'0')*10+(s[i]-'0') <= 26 )
	{
		return dp[i-1]+dp[i-2];
	}
	else
		return dp[i-1];
}
int main()
{
	dp[0]=1;
	dp[-1]=1;
	l flag;
	while (cin >> s && s[0] != '0')
	{
		flag=1;
		L n = s.length();
		for (int i = 0; i < n; ++i)
		{
			if( s[i]=='0' && (s[i-1]=='0') )
			{
				cout<<'0'<<endl;
				flag=0;	
				break;
			}
				dp[i]=decodePatterns(i);
		}
		if(flag)
			cout<<dp[n-1]<<endl;
	}
	return 0;
}