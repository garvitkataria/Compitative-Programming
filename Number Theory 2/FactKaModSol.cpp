#include<bits/stdc++.h> 
using namespace std; 
long long int pow1(long long int a, long long int b, long long int c) 
{ 
	long long int ans=1LL; 
	while(b>0) 
	{ 
   		if(b&1) 
          ans=(ans*a)%c; 
      a=(a*a)%c; 
      b=b>>1; 
    } 
  	return ans; 
} 
int main() 
{ 
  long long int n, p, i, ans, fact; 
  int t; scanf("%d",&t); 
  while(t--) 
  { 
    fact=1; 
    scanf("%lld%lld",&n, &p); 
    if(n>=p) 
    {
      printf("0\n");continue;
    } 
    for(i=n+1;i<=p-1;i++) 
    { 
      fact=(fact*i)%p; 
      if(fact==0) break; 
    } 
    ans=pow1(fact, p-2, p); 
    printf("%lld\n",p-ans); 
  } 
  return 0; 
}