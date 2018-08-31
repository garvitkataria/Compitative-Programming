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

l minCost(l i ,l M[] ,l C[] ,l menCount[],l n)
{

	if(i>=n)
		return 0;

	l TotalMen = menCount[0]+menCount[1]+menCount[2];
	l AliveMen = M[i];

	l p,q,r;
	p=menCount[0];
	q=menCount[1];
	r=menCount[2];

	l ans;
	ans = C[i] + minCost(i+1,M,C,menCount,n);

	if(TotalMen >= AliveMen)
	{
		l j=0;
		while(AliveMen > 0)
		{
				if(menCount[j]>=AliveMen)
				{
					menCount[j]-=AliveMen;
					AliveMen=0;
					break;
				}
				else if(menCount[j]<AliveMen)
				{
					AliveMen-=menCount[j];
					menCount[j]=0;
				}
				j++;
		}

		menCount[0]=menCount[1];
		menCount[1]=menCount[2];
		menCount[2]=0;
		ans = min(ans,minCost(i+1,M,C,menCount,n));
		menCount[0]=p;
		menCount[1]=q;
		menCount[2]=r;
	}

	menCount[2]+=M[i];
	ans = min( ans, 2*C[i]+minCost(i+1,M,C,menCount,n) );
	menCount[2]=r;


	return (ans);
}
int main()
{
	l n, m, c;
	int M[1000], C[1000];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>m>>c;
		M[i]=(m);
		C[i]=(c);
	}
	l menCount[3]={0,0,0};
	cout<<minCost(0,M,C,menCount,n)<<endl;
	return 0;
}