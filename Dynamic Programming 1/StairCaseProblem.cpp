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
long staircase(int n)
{
    V A;
    A.pb(1);
    A.pb(1);
    A.pb(2);
    for (int i = 3; i <= n; ++i)
    {
    	A.pb(A[i-1]+A[i-2]+A[i-3]);
    }
    return A[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<staircase(n)<<endl;
	return 0;
}