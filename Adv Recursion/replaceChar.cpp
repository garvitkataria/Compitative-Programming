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
void replaceCharacter(char input[], char c1, char c2) 
{
  if(input[0]=='\0')
  {
  	return;
  }
  if(input[0]==c1)
  {
  	input[0]=c2;
  }
  replaceCharacter(input+1,c1,c2);
}


int main()
{
	char input[100];
	char c1;
	char c2;
	cin>>input;
	cin>>c1>>c2;
	replaceCharacter(input,c1,c2); 
	cout<<input<<endl;
	return 0;
}