#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}

int gcd(l a,l b)
{
	//2nd var is big
	if(a>b)
		gcd(b,a);

	//base case
	if(a==0)
		return b;
		
	b=b%a;
	return gcd(b,a);
}
int main()
{
	int a=5;
	int b=10;
	int ans =gcd(a,b);
	cout<<ans<<endl;
	return 0;
}