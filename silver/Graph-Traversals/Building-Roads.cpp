#include <bits/stdc++.h>
 
using namespace std;
 
 vector<int>adj[100005];
 bool vis[100005];
 
void dfs(int i)
{
    if(vis[i]) return;
    vis[i]=1;
 
    for(auto c: adj[i])dfs(c);
    
}
 
int main()
{   
      int n,m;
      cin>>n>>m;
      n++;   
      
 
      for(int i=0;i<m;i++)
      {  int k,l;
      cin>>k>>l;
        adj[k].push_back(l);
        adj[l].push_back(k);
        
      }
 
     
      vector<int>ans;
      int round=0;
      
      
      for(int i=1;i<n;i++)
      { 
        if(!vis[i])
        {  ans.push_back(i);
            dfs(i);
            round++;
       
               }
           
      }
     cout<<round-1<<endl;
     for(int i=1;i<ans.size();i++)
     {
           cout<<ans[i]<< " "<<ans[i-1]<<endl;
     }
 }    
