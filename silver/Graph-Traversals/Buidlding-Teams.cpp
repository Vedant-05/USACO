#include <bits/stdc++.h>
 
using namespace std;
const int maxN=1e5+1;
bool possible,vis[maxN],team[maxN];
vector<vector<int>>adj(maxN);
void dfs(int u,int p=0)
{
    for(int v:adj[u])
    {
        if(v!=p)
        {
            if(!vis[v])
            {
                team[v]=!team[u];
                vis[v]=true;
                dfs(v,u);
            }
            else{
                if(team[v]==team[u])
                possible=false;
            }
        }
    }
}
int main()
{
 
    int n,m;
    cin>>n>>m;
    
 
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   
 
    possible =true;
 
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            dfs(i);
        }
    }
    if(!possible) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<=n;i++)
        {
            cout<<(team[i]?1:2)<<" ";
        }
    }
   
 
   
 
}
