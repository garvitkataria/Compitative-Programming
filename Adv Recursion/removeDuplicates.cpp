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
void removeConsecutiveDuplicates(char *input) {
  if(input[0]=='\0')
    return;
  if(input[0]==input[1])
  {
    for (int i = 0; input[i]!='\0' ; ++i)
    {
      input[i]=input[i+1];
    }
    removeConsecutiveDuplicates(input);
  }
  else
    removeConsecutiveDuplicates(input+1);

}


int main()
{
	char input[100];

	cin>>input;

	removeConsecutiveDuplicates(input); 
	cout<<input<<endl;
	return 0;
}