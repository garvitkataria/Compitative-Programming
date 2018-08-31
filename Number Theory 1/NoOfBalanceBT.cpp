#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
int balancedBTs(int h) 
{
	if(h==1||h==0)
	{
		return 1;
	}
	L x,y,a,b,c;
	x=balancedBTs(h-1)%MOD;
	y=balancedBTs(h-2)%MOD;
	a=(x*x)%MOD;
	b=(2*x*y)%MOD;
	c=(a+b)%MOD;
	// cout<<'a'<<a<<endl;cout<<'b'<<b<<endl;cout<<'c'<<c<<endl;
 	return c;
}

void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
int main()
{
	int h;
	cin>>h;
	cout<<balancedBTs(h)<<endl;
	return 0;
}