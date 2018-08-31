#include <bits/stdc++.h>
using namespace std;
typedef long long int L;
#define MAX 1000000007
#define MODINV 500000004
L f(L n)
{
  n%=MAX;
  n=(n*(n+1))%MAX;
  n=(n*MODINV)%MAX;
  return n;
}
int main()
{
  	L n;
  	cin>>n;

  	L j=0;
  	L x=0;
  	L ans=0;
  	L y=0;
  	for(L i=1;i<=n;i=j+1)
  	{
		x=n/i;
		j=n/x;
	    x=f(x);
	    y=f(j)-f(i-1);
	    
	    y%=MAX;
	    if(y<0) 
	    	y+=MAX;
	    y*=x;
    	
   		ans=(ans+y)%MAX;
   		// cout<<i<<" "<<ans<<" "<<j<<" xy "<<x<<y<<endl;
  	}
  	cout<<ans<<endl;
    return 0;
}