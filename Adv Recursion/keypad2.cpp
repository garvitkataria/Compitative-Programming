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
 
int keypad(int num, string output[])
{
  // cout<<"num"<<num<<endl;
  if(num==1||num==0)
  {
    output[0]="";
    return 1;
  }
  int digit= num%10;
  int oldNum = num/10;
  string *oldoutput = new string[1000];
  int oldtotalcomb = keypad(oldNum, oldoutput);
  // cout<<"oldtotalcomb"<<oldtotalcomb<<endl;
  int newtotalcomb;
  if(digit == 2)
    newtotalcomb = oldtotalcomb*3;
  if(digit == 3)
    newtotalcomb = oldtotalcomb*3;
  if(digit == 4)
    newtotalcomb = oldtotalcomb*3;
  if(digit == 5)
    newtotalcomb = oldtotalcomb*3;
  if(digit == 6)
    newtotalcomb = oldtotalcomb*3;
  if(digit == 7)
    newtotalcomb = oldtotalcomb*4;
  if(digit == 8)
    newtotalcomb = oldtotalcomb*3;
  if(digit == 9)
    newtotalcomb = oldtotalcomb*4;

  for (int i = 0; i < newtotalcomb; ++i)
  {
    output[i]=oldoutput[i%oldtotalcomb];
  }

  for (int i = 0; i < newtotalcomb; ++i)
  {
    if(digit==2)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _2[j];
    }
    if(digit==3)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _3[j];
    }
    if(digit==4)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _4[j];
    }
     if(digit==5)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _5[j];
    }
     if(digit==6)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _6[j];
    }
     if(digit==7)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _7[j];
    }
      if(digit==8)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _8[j];
    } 
     if(digit==9)
    { 
        int j = i/oldtotalcomb;
        output[i] = output[i] + _9[j];
    }
  }

  return newtotalcomb;
}

int main()
{
  int input;
  cin>> input;
  // int totalSeq=pow(3,input.length());
  // cout<<totalSeq<<endl;
  string *output = new string[1000];
  int totalSeq = keypad(input, output);
  cout<<totalSeq<<endl;
  // Print Output
  for (int i = 0; i < totalSeq; ++i)
  {
    cout<<output[i]<<endl;
  }
	return 0;
}