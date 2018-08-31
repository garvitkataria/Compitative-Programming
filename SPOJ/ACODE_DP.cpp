#include<bits/stdc++.h>
#define MOD 1000000007
#define max2(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;

map<L, L> dp;
string s;
L n;
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
L decodePatterns(L i)
{
	if(i==0||i==-1)
	{
		return 1;
	}
	else if( (s[i-1]-'0')*10+(s[i]-'0') <= 26 )
	{
		return decodePatterns(i-1)+decodePatterns(i-2);
	}
	else
		return decodePatterns(i-1);
}
int main()
{
	while (cin >> s && s != "0")
	{
		n = s.length();
		cout<<decodePatterns(n-1)<<endl;
	}
	return 0;
}