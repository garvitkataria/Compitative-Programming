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

bool compare(int a, int b)
{	
	return a > b;

}

L KnapSnack( int arr[], int n)
{
	sort(arr,arr+n,compare);
	L pow=1;
	L count=0;
	for (int i = 0; i < n; ++i)
	{
		
		count += pow*arr[i];
		pow *= 2;
		//cout<<count<<endl;
	}
	return count;
}
int minAbsoluteDiff(int arr[], int n) {
    sort(arr,arr+n);
    int diff=arr[0]-arr[1];

    for (int i = 1; i < n-1; ++i)
    {
    	if(diff>arr[i]-arr[i+1])
    		diff=arr[i]-arr[i+1];

    }
    return diff

}
int main()
{
	L n,M;
	cin>>n>>M;
	L a,b;
	cin>>a>>b;
	L arr[10000];
	arr[0]=0;
	L ans=0;
	for (int i = 1; i < n; ++i)
	{
		L p,q,r;
		p = (arr[i-1]%M)%4294967296;
		q = (p * a%4294967296 )%4294967296;
		arr[i] = (q + b%4294967296)%4294967296;

		if(arr[i]/256>arr[i-1]/256)
			ans+=arr[i]/256-arr[i-1]/256;
	}
	cout<<ans<<endl;
	return 0;
}
