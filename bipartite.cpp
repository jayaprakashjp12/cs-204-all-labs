 #include <bits/stdc++.h>
using namespace std;
vector<vector<int>>a;
vector<int>col;
int main()
{
 int n,m ;
 cin>>n>>m;
 vector<int>dummy;
 for (int i=0;i<=n;i++)
 {
  dummy.push_back(0);
 }
 for (int i=0;i<=n;i++)
 {
    a.push_back(dummy);
 }

    for (int i=0;i<m;i++)
    {
      int c ,b;
      cin>>c>>b;
      a[c][b]=1;
      a[b][c]=1;
    }
 //   for (int i=0;i<=n;i++){for (int i2=0;i2<=n;i2++){cout<<a[i][i2]<<" ";}cout<<endl;}
    for (int i=0;i<=n;i++)
    { 
     col.push_back(0);
    }
int count=0;
queue<int>q1;
queue<int>q2;
  do
    { if(q1.empty())
            {
                for(int i=1;i<=n;i++)
                    {
                        if(col[i]==0){q1.push(i); 
                        count++;col[i]=1;break;}
                    }
                
            }
     
      while(!q1.empty())
            {
             int temp=q1.front();q1.pop(); 
             for(int i=1;i<=n;i++)
                {
                    if(temp!=i&&a[temp][i]==1)
                    { //cout<<i<<":edge wiht temp  ";
                     if(col[i]==0){col[i]=(col[temp]==1)?2:1;count++;q2.push(i);}
                     else if(col[i]==col[temp]){cout<<"NO"; return 0;}    
                        
                        
                    }
                }
                
                
            }     
     if(q2.empty())
        {   while(!q1.empty())
            {int temp=q1.front();q1.pop();
            for (int i=1;i<=n;i++)
                { 
                     if(temp!=i&&a[temp][i]==1)
                    {  
                      
                     if(col[i]==col[temp]){cout<<"NO"; return 0;}    
                    }
                }
                
            }
            
        }
     swap(q1,q2);
     
     
     }while(!q1.empty());

 cout<<"YES";
 

}
    
    
