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
 
void printPermutations(string input,string output)
{
   if(input.empty())
   {
    cout<<output<<endl;
    return;
   }
   string temp;
   for (int i = 0; i < input.size(); ++i)
   {
      temp = input.substr(0,i)+input.substr(i+1);
      // cout<<temp<<endl;
      printPermutations(temp,input[i]+output);
   }
    
}

int main()
{
  string input;
  cin>> input;
  string output;
  printPermutations( input,output);
	return 0;
}