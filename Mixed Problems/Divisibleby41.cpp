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
#define pb push_back
#define mp make_pair

void getNumber(L a0, L a1, L n, L c)
{
	V A;
	A.pb(a0);
	A.pb(a1);
	L temp;
	for (int i = 2; i < n; ++i)
	{
		temp = (A[i-1]*c + A[i-2]) % 10;
		A.pb(temp);
	}
	temp=A[0];
	for (int i = 1; i < n; ++i)
	{
		temp= (temp*10 + A[i])%41;
	}
	if(temp%41==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
}
int main()
{
	L t,a0,a1,n,c;
	cin>>t;
	while(t--)
	{
		cin>>a0>>a1>>c>>n;
		getNumber(a0,a1,n,c);
	}
	return 0;
}