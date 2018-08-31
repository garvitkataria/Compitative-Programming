#include <bits/stdc++.h>
using namespace std; 
#define size 750000
#define ll long long 
#define mod 1000000007 
  int main()
  { 
  	int T; 
  	cin>>T; 
  	while(T--)
  	{ 
  		ll*numbers = new ll [size+1]; 
  		for(int i=0;i<=size;i++)
  		{ 
  			numbers[i]=-1; 
  		} 
  		int n; 
  		cin>>n; 
  		for(int i=0;i<n;i++)
  		{ 
  			int ai; 
  			cin>>ai; 
  			numbers[ai]=1; 
  		} 
  		for(int i=1;i<=size/2;i++)
  		{ 
  			if(numbers[i]!=-1)
  			{ 
  				for(int j=i*2;j<=size;j+=i)
  				{ 
  					if(numbers[j]!=-1&&j!=i)
  					{ 
  						numbers[j]+=numbers[i]; 
  					}
  				}
  			} 
  		} 
  		ll ans=0; 
  		for(int i=0;i<=size;i++)
  		{ 
  			if(numbers[i]!=-1)
  			{ 
  				ans=(ans%mod +numbers[i]%mod)%mod; 
  			} 
  		} 
  		cout<<ans<<endl; 
  		delete []numbers;
  	} 
  }