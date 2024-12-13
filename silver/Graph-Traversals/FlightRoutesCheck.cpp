#include <bits/stdc++.h>
 
 
using namespace std;
 
vector<int> adj[100005][2];bool vis[100005];
 
 
void dfs(int v,int x)
{
    vis[v]=true;
    for(int to:adj[v][x])
    {
        if(!vis[to])
        {
            dfs(to,x);
        }
    }
}
 
 
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
         cin>>u>>v;
         u--;v--;
         adj[u][0].push_back(v);
         adj[v][1].push_back(u);
    }
 
    dfs(0,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cout<<"NO"<<endl;
            cout<<1<<" "<<i+1<<endl;
            return 0;
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(0,1);
 
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cout<<"NO"<<endl;
            cout<<i+1<<" "<<1<<endl;
            return 0;
        }
    }
 
    cout<<"YES"<<endl;
 
    
 
 
 
}
