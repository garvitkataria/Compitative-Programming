#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
string _0 = "";
string _1 = "";
string _2 = "abc"; 
string _3 = "def";
string _4 = "ghi";
string _5 = "jkl";
string _6 = "mno";
string _7 = "pqrs";
string _8 = "tuv";
string _9 = "wxyz";
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
 
void printKeypad(int num, string output)
{
  if(num==0||num==1)
  {
    cout<<output<<endl;
    return;
  }
  int digit= num%10;
  int oldNum = num/10;
  if(digit==2)
  {
    for (int i = 0; i < _2.size(); ++i)
      printKeypad(oldNum, _2[i]+output);
  }
  else if(digit==3)
  {
    for (int i = 0; i < _3.size(); ++i)
      printKeypad(oldNum, _3[i]+output);
  }
  else if(digit==4)
  {
    for (int i = 0; i < _4.size(); ++i)
      printKeypad(oldNum, _4[i]+output);
  }
  else if(digit==5)
  {
    for (int i = 0; i < _5.size(); ++i)
      printKeypad(oldNum, _5[i]+output);
  }
  else if(digit==6)
  {
    for (int i = 0; i < _6.size(); ++i)
      printKeypad(oldNum, _6[i]+output);
  }
  else if(digit==7)
  {
    for (int i = 0; i < _7.size(); ++i)
      printKeypad(oldNum, _7[i]+output);
  }
   else if(digit==8)
  {
    for (int i = 0; i < _8.size(); ++i)
      printKeypad(oldNum, _8[i]+output);
  }
   else if(digit==9)
  {
    for (int i = 0; i < _9.size(); ++i)
      printKeypad(oldNum, _9[i]+output);
  }
}
int main()
{
  int input;
  string output;
  cin>> input;
  printKeypad(input, output);
	return 0;
}