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
 
void printSubseq(string input, string output)
{
  if(input.empty())
  {
    cout<<output<<endl;
    return;
  }
  printSubseq(input.substr(1),output);
  printSubseq(input.substr(1),output+input[0]);
}
int main()
{
  string input,output;
  cin>> input;
  printSubseq(input, output);
	return 0;
}