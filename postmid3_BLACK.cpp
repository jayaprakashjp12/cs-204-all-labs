 #include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> visited;
int ans(int i, int j, vector<vector<int>>input,int n, int m,int val)
    { 
     val++;
     visited[i][j]=true;
     if(j<m-1&&!visited[i][j+1]&&input[i][j]==input[i][j+1]){val=ans(i,j+1,input,n,m,val);}
     if(j>0&&!visited[i][j-1]&&input[i][j]==input[i][j-1]){val=ans(i,j-1,input,n,m,val);}
     if(i<n-1&&!visited[i+1][j]&&input[i][j]==input[i+1][j]){val=ans(i+1,j,input,n,m,val);}
     if(i>0&&!visited[i-1][j]&&input[i][j]==input[i-1][j]){val=ans(i-1,j,input,n,m,val);}
     return val;
    
        
    }
int main()
{
 int n,m;
 cin>>n>>m;
 vector<vector<int>> input;
    vector<int> B;
    for(int i=0;i<m;i++) B.push_back(0);
    for(int i=0;i<n;i++) input.push_back(B);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
      int x,y;
      cin>>x>>y;
      input[x-1][y-1]=1;
    }
     vector<bool> W;
    for(int i=0;i<m;i++) W.push_back(false);
    for(int i=0;i<n;i++) visited.push_back(W);
    int max=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(!visited[i][j] && input[i][j]==1)
        {
          //cout<<endl;
          int cc=ans(i,j,input,n,m,0);
          if(cc>max) max=cc;
        }
      }
    }
    cout<<max<<endl;
  }
    
    
    
    
