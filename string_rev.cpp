  #include<bits/stdc++.h>
using namespace std;
#define k 26
  struct trie
{
  struct  trie* children[k];
  bool isendofword;
};
struct  trie* createnode(void)
{
    struct  trie* temp=new trie;
    temp->isendofword= false;
    for(int i=0;i<k;i++)
    {
      temp->children[i]=NULL;

    }
    return temp;
}
void insert(struct trie* root,string key)
{  struct trie* crawl=root;

  for (int i=0;i<key.length();i++)
  { int index= key[i]-'a';
    if(!crawl->children[index]){
    crawl->children[index]=createnode();

  }
  crawl=crawl->children[index];
  }
  crawl->isendofword=true;
 }
bool search(struct trie* root,string key)
{
  struct trie*temp=root;
  for (int i=0;i<key.length();i++)
  {
    int index= key[i]-'a';
    if(!temp->children[index])
    {
      return false;
    }
    temp=temp->children[index];
  }
  if(temp->isendofword)
  {
    return true;
  }else{
    return false;
  }


}
bool palin(string a)
{
    int n=a.length();
    for(int i=0;i<n/2;i++)
    {
        if(a[i]!=a[n-i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
  int n;
  cin>>n;
  string keys[n];
  for (int i = 0; i < n; i++)
    {
        cin>>keys[i];      

    }


 struct trie *root =  createnode();


     // Construct trie
for (int i = 0; i < n; i++)
    {
        insert(root,keys[i]);
    }
 
for (int i = 0; i < n; i++)
{
    string temp=keys[i];
    cout<<temp<<" ";
    reverse( temp.begin(),temp.end() );
    cout<<temp<< " ";
    if(!palin(temp))
    { 
        //cout<<i<<" ";
    if(  search(root,temp))
    {
    cout<<"yes";
    return 0;
    }
    }
}
cout<<"NO";

}
