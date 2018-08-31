#include<bits/stdc++.h>
#define MOD 1000000007
#define max2(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;

std::map<L, L> dp;
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
L optvalue(L n)
{
	if(n<12)
	{
		return n;
	}

	if(dp.count(n))
	{
		return dp[n];
	}
	else
		dp[n]=optvalue(n/2)+optvalue(n/3)+optvalue(n/4);
	return dp[n];
}
int main()
{
	L n;
	while(scanf("%lld",&n)!=EOF)
	{
		cout<<optvalue(n)<<endl;
	}
	return 0;
}