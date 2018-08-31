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

void multiply(L A[2][2],L M[2][2]){

	L firstValue = (A[0][0]%mod * M[0][0]%mod) + (A[0][1]%mod * M[1][0]%mod);
	L secondValue = (A[0][0]%mod * M[0][1]%mod) + (A[0][1]%mod * M[1][1]%mod);
	L thirdValue = (A[1][0]%mod * M[0][0]%mod) + (A[1][1]%mod * M[1][0]%mod);
	L fourthValue = (A[1][0]%mod * M[0][1]%mod) + (A[1][1]%mod * M[1][1]%mod);

	A[0][0] =firstValue%mod;
	A[0][1] = secondValue%mod;
	A[1][0] = thirdValue%mod;
	A[1][1] = fourthValue%mod;
	
}
void power(L A[2][2],L n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		L F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}
L getFibonacci(L n){
	if(n==0 || n==1){
		return n;
	}
	L A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}
 
L pow1(L a,L b,L c){
	if(b == 0)
	{
		return 1;
	}

	if(b%2 ==0)
	{
		//Even
		return pow1((a*a)%c,b/2,c);
	}
	else
	{
		// Odd
		return ((a%c)*(pow1((a*a)%c,b/2,c)))%c;
	}

}
	//Gn = 1 + Fn
	//Gn = Gn-1 + Gn-2
	//Gn%m = [a^fib(n-1)%m * b^fib(n)%m ] % m
	//G[0] = a
	//G[1] = b
	//a^fib(n-1)%m = ( a ^ [fib(n-1)%m-1] )% m

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		L F0,F1,n;

		cin>>F0>>F1>>n;
		if(n==0)
		{
			cout<<F0<<endl;
			continue;
		}
		L a,b,x,y;
		a = 1 + F0;
		b = 1 + F1;
		L fibn = getFibonacci(n) % (MOD-1);
		L fibn_1 = getFibonacci(n-1) % (MOD-1);
		x = pow1(a,fibn_1,MOD);
		y = pow1(b,fibn,MOD);
		L Gn = (x*y)%MOD;
		//cout<<fibn<<fibn_1<<" "<<getFibonacci(n)<<" "<<getFibonacci(n-1)<<" "<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<Gn <<endl;
		cout<<fibn<<" "<<fibn_1<<" "<<Gn<<endl;

		cout<< Gn - 1 <<endl;
	}	
	return 0;
}