#include <bits/stdc++.h>
 
using namespace std;
 
 
 
void dfs(vector<vector<char>> &a,vector<vector<int>>&vis,int i,int j)
{    if(i<0||i>=a.size()||j<0||j>=a[0].size()) return;
    if(vis[i][j]==1||a[i][j]=='#') return;
    vis[i][j]=1;
    // if(vis[i+1][j]==0&&a[i+1][j]=='.') 
    // if(vis[i][j+1]==0&&a[i][j+1]=='.') 
    // if(vis[i-1][j]==0&&a[i-1][j]=='.') 
    // if(vis[i][j-1]==0&&a[i][j-1]=='.') 
    dfs(a,vis,i,j-1);
    dfs(a,vis,i-1,j);
    dfs(a,vis,i,j+1);
    dfs(a,vis,i+1,j);
}
int main()
{
      int n,m;
      cin>>n>>m;
      vector<vector<char>> a(n,vector<char>(m));
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
      }
      int ans=0;
      vector<vector<int>> vis(n,vector<int>(m,0));
 
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0&&a[i][j]=='.')
            {  
                dfs(a,vis,i,j);
                ans++;
            }
        }
      }
 
      cout<<ans;
}
