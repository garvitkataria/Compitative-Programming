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

struct Item
{
	int S,F,P;
};

bool compare(Item a, Item b)
{	
	return a.F < b.F;
}

//O[ n^2 ]
double KnapSnack( Item arr[], int n)
{
	sort(arr,arr+n,compare);

	int *dp = new int[n];
	dp[0] = arr[0].P;
	for (int i = 1; i < n; ++i)
	{
		dp[i] = arr[i].P;
		for (int j = i-1; j >= 0; j--)
		{
			if(arr[i].S >= arr[j].F)
			{
				dp[i]+=dp[j];
				break;
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
		// for (int j = 0; j < n; ++j)
		// {
		// 	cout<<dp[j]<<" ";
		// }cout<<endl;

	}
	return dp[n-1];
}

//O [nlog(n)]
double KnapSnack2( Item arr[], int n)
{
	sort(arr,arr+n,compare);

	int *dp = new int[n]();
	dp[0] = arr[0].P;
	for (int i = 1; i < n; ++i)
	{
		dp[i] = arr[i].P;
		int s=0,j;
		int e= i-1;
		int x=-1;
		while(s<=e)
		{
			j=(s+e)/2;
			cout<<s<<" "<<e<<" "<<j<<endl;
			
			if(arr[i].S >= arr[j].F)
			{
				x = j;
				cout<<"x"<<x<<endl;
				s=j+1;
			}
			else
				e=j-1;
		}

		if(x!=-1)
			dp[i]+=dp[x];

		dp[i]=max(dp[i],dp[i-1]);
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[j]<<" ";
		}cout<<endl;

	}
	return dp[n-1];
}
int main()
{
	int N;
	Item *arr;
	arr = new Item[1000009];
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i].S >> arr[i].F >> arr[i].P;
	}
	cout<<KnapSnack2(arr,N)<<endl;
	return 0;
}
