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

// string A[1001];
l n;
unordered_map<string, int> A;

bool CheckInDictionary(string S)
{
        if (A.find(S) != A.end())
            return true;
    return false;
}

void wordBreak(string S,l n,string result)
{
	string prefix;
	for (int i = 1; i <= n; ++i)
	{
		prefix = S.substr(0,i);
		if(CheckInDictionary(prefix))
		{
			if(i==n)
			{
				result+=prefix;
				cout<<result<<endl;
				return;
			}	
			wordBreak(S.substr(i,n-i),n-i,result+prefix+' ');
		}
	}
}

int main()
{
	cin>>n;
	string S,temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		A.insert(mp(temp, 1));
	}
	cin>>S;
	wordBreak(S,S.size(),"");
	return 0;
}