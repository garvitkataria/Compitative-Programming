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

bool Check(L x,V L,Y C)
{
	long long int n,m,i,j,time=x;
	m = L.size()-1;
	n = C.size()-1;
	while(m >= 0 && n>=0)
	{	
		if(time==0)
			time=x;

		if(L[m]<C[n].first)
			return 0;

		if(L[m]>=C[n].first)
		{
			if(C[n].second > time) 
			{
				C[n].second -= time;
				time = 0;
				m--;
			}
			else
			{
				time-=C[n].second;
				C[n].second=0;
				n--;
			}
		}
		
	}

	if(n>=0)
		return 0;
	else
		return 1;
}
void MonkandCake(V F,Y C)
{
	L s, e, mid, ans=-1;
	s = 1;
	e = 10000000000000;

	while(s<=e)
	{
		mid = (s+e)/2;
		if(Check(mid,F,C))
		{
			ans = mid;
			e=mid-1;
		}
		else
			s = mid+1;
		
	}
	cout<<ans<<endl;
}
int main()
{
	L t, N, M, temp;
	V L;
	Y C;
	cin>>t;
	while(t--)
	{
		cin>>N>>M;
		for (int i = 0; i < M; ++i)
		{
			cin>>temp;
			L.pb(temp);
		}	
		for (int i = 0; i < N; ++i)
		{
			cin>>temp;
			C.pb(mp(temp,1));
		}	
		for (int i = 0; i < N; ++i)
		{
			cin>>temp;
			C[i].second = temp;
		}
		sort(L.begin(),L.end());
		sort(C.begin(),C.end());
		MonkandCake(L,C);	
		L.clear();
		C.clear();
	}
	return 0;
}