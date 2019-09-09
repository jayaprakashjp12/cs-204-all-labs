#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b){
int flag=0;
string x=a.append(b);
string y=b.append(a);
if(x<y){
  flag=1;
          }
if (flag==1){return  false;}
  else return true;
}
int main()
{int t;

  string s ;
  cin>>t;
    while(t--){

      int m;
      cin>>m;
      vector<string> n;
      for (int i=0;i<m;i++){
          cin>>s;

        n.push_back(s);
      }
sort(n.begin(),n.end(),compare);
for(int i=0;i<n.size();i++){
  cout<<n[i];
}
cout<<endl;








    }












}
