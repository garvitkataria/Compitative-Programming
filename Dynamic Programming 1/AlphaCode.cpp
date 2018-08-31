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

// int num_codes(int* n, int size) {
// 	 if (size == 1) {
// 		 return 1;
// 	 }
// 	 if (size == 0) {
// 		 return 1;
// 	 }
// 	 int output = num_codes(n, size - 1);
// 	 if (output[size - 2] * 10 + output[size - 1] <= 26) {
// 		 output += num_codes(n, size -2);
// 	 }
// 	 return output;
// }


L num_codes_i(string input) {
	L* output = new L[input.size() + 1];
	output[0] = 1;
	output[1] = 1;

	for (L i = 2; i <= input.size(); i++) 
	{
      output[i]=0;
      	if(input[i-1]!='0')
			output[i] = output[i - 1];
		L t=(input[i-2]-'0') *10 + (input[i - 1]-'0');
		//cout<<t<<endl;
		if(t==0)
        {
          return 0;
        }
		else if ( t <= 26 && t>9) 
		{
			output[i] += output[i - 2];
			output[i] %= MOD;
		}
      	else if(t%10==0)
		{
			return 0;
		}
	}
	L ans = output[input.size()] % MOD;
	delete [] output;
	return ans;
}




// int num_codes2(int* n, int size, int* arr) {
// 	 if (size == 1) {
// 		 return 1;
// 	 }
// 	 if (size == 0) {
// 		 return 1;
// 	 }
// 	 if (arr[size] > 0) {
// 		 return arr[size];
// 	 }

// 	 int output = num_codes2(n, size - 1, arr);
// 	 if (output[size - 2] * 10 + output[size - 1] <= 26) {
// 		 output += num_codes2(n, size -2, arr);
// 	 }
// 	 arr[size] = output;
// 	 return output;
// }


int main() 
{
	string S = "1";
	cin>>S;
	while(S[0]!='0')
	{
		
		cout<<num_codes_i(S)<<endl;
		cin>>S;
	}
}