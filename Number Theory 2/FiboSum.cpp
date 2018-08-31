#include<bits/stdc++.h>
#include <unordered_map>
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


void multiply(int A[2][2],int M[2][2]){

	int firstValue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
	int secondValue = A[0][0] * M[0][1] + A[0][1] * M[1][1];
	int thirdValue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
	int fourthValue = A[1][0] * M[0][1] + A[1][1] * M[1][1];

	A[0][0] =firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
	
}
void power(int A[2][2],int n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		int F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}
int getFibonacci(int n){
	if(n==0 || n==1){
		return n;
	}
	int A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}
int main(){
	int n,m;
	cin >> n >> m;
	cout << (getFibonacci(m+2)-getFibonacci(n+1))<<endl;
	return 0;
}