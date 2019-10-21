#include <bits/stdc++.h>
using namespace std;
int fc(int i, int j,int* count,int input[n][m])
{ 
  







};


int main()
{
 int n,m,k;
 cin>>n>>m>>k;
 int input[n][m]={ 0 };
 for(int i=0;i<k;i++)
  {
    int a,b;
    cin>>a>>b;
    input[a][b]=1;
  }
  int visited[n][m]={ 0 };
  int max=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
        {int* count;
         if(visited[n][m]!=0)
          {count=fc(i,j,0,input,visited);}
          if(max<count){max=count;}
        }
  }








}
