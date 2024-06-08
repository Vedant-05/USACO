#include <bits/stdc++.h>

using namespace std;



vector<int> needed(101,0);
int costMin = INT_MAX;
int currCost = 0;

vector<bool> vis(11,false);



void findi( vector<pair<int,int>> acs,vector<int> cooling, vector<int> cost)
{
    bool isDone = true;
    for(auto c: needed)
    {
        if(c>0)
        {
            isDone = false;
        }

    }
    if(isDone)
    {
        costMin = min(costMin,currCost);
        return;
    }
    else
    {
        for(int i = 0;i<cost.size();i++)
        {
            if(vis[i] == true) continue;
            vis[i] = true;
            currCost+=cost[i];
            for(int j = acs[i].first;j<=acs[i].second;j++)
            {
                needed[j]-=cooling[i];
            }
            findi(acs,cooling,cost);
            vis[i] = false;
            currCost-=cost[i];
             for(int j = acs[i].first;j<=acs[i].second;j++)
            {
                needed[j]+=cooling[i];
            }


        }
    }
}


int main()
{

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=a;j<=b;j++)
        {
            needed[j] = c;
        }
    }

    vector<pair<int,int>> acs(m);
    vector<int> cooling(m);
    vector<int> cost(m);

    for(int i = 0;i<m;i++)
    { 
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        acs[i].first = a;
        acs[i].second = b;
        cooling[i] = c;
        cost[i] = d;
    }

    findi(acs,cooling,cost);

    cout<<costMin<<endl;


   
}
