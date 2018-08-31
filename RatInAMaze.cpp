#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef set<L> S;
typedef set<l> s;
#define limit 32000

int board[20][20];

void helperMaze(int maze[][20], int n, int row , int col)
{
  if(row==n-1 && col==n-1)
  {
  // cout<<row<<' '<<col<<endl;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cout<<board[i][j]<<' ';
      cout<<endl;
    return;
  }
  // board[row][col]=1;
  //Explore Up Down Left Right.
  if(maze[row-1][col]==1 && row-1>=0 && board[row-1][col]==0)
  {
    board[row-1][col]=1;
    helperMaze(maze,n,row-1,col);
    board[row-1][col]=0;
  }
  if(maze[row+1][col]==1 && row+1<n && board[row+1][col]==0)
  {
    board[row+1][col]=1;
    helperMaze(maze,n,row+1,col);
    board[row+1][col]=0;
  }
  if(maze[row][col-1]==1 && col-1>=0 && board[row][col-1]==0)
  {
    board[row][col-1]=1;
    helperMaze(maze,n,row,col-1);
    board[row][col-1]=0;
  }
  if(maze[row][col+1]==1 && col+1<n && board[row][col+1]==0)
  {
    board[row][col+1]=1;
    helperMaze(maze,n,row,col+1);
    board[row][col+1]=0;
  }

    // cout<<"end"<<endl;
    return;
  
}
void ratInAMaze(int maze[][20], int n)
{
  memset(board,0,20*20*sizeof(int));
  board[0][0]=1;
  helperMaze(maze,n,0,0);
}

int main()
{
  int n;
  cin>>n;
  int maze[20][20];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin>>maze[i][j];
  ratInAMaze( maze, n);
  return 0;
}