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

L modRecursive(L a,L b,L c){
	if(b == 0)
	{
		return 1;
	}

	if(b%2 ==0)
	{
		//Even
		return modRecursive((a*a)%c,b/2,c);
	}
	else
	{
		// Odd
		return ((a%c)*(modRecursive((a*a)%c,b/2,c)))%c;
	}

}
int main()
{	
	//cout<<modRecursive(2,6,500)<<endl;	
	int t;
	cin>>t;
	while(t--)
	{
		L n,p,temp=0;
		L sum=1;
		cin>>n>>p;
		if(n>=p)
		{
			cout<<"0"<<endl;
			continue;
		}
		for (L i = n+1; i < p; ++i)
		{
			sum*=i;
			sum%=p;
			if(sum==0)
				break;
			 // cout<<temp<<endl;
		}
		sum=(modRecursive(sum,p-2,p));
		sum=p-sum;
		cout<<sum<<endl;
	}
	return 0;
}