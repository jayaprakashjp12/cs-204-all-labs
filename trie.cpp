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
struct trie* insert(struct trie* root,string key)
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
int main()
{
  string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                      "bye", "their" };
     int n = sizeof(keys)/sizeof(keys[0]);
 string keys2[n];

 struct trie *root =  createnode();

     // Construct trie
for (int i = 0; i < n; i++)
{
         insert(root, keys[i]);

}
for (int i = 0; i < n; i++)
{
if(  search(root,keys[i]))
{
  cout<<"yes";
  return 0;
}
}
cout<<"NO";
}
