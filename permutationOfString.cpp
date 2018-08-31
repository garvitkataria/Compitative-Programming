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
 
int returnPermutations(string input, string output[])
{
   if(input.empty())
   {
    output[0]="";
    return 1;
   }
   int old;
   string output2[300];
   old=returnPermutations(input.substr(1),output2);
   int k=0;
   for (int i = 0; i <= old; ++i)
   {
     for (int j = 0; j < input.size() ; ++j)
     {
       output[k++] = output2[i].substr(0,j) + input[0] + output2[i].substr(j);
     }
   }
   return old*input.size();
}


int main()
{
  string input;
  cin>> input;
  string output[300];
  int a = returnPermutations( input,output);
  for (int i = 0; i < a; ++i)
  {
    cout << output[i]<<endl;
  }
	return 0;
}

