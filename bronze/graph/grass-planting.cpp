//just pure brute force
//two cases, if all three rectanges are stacked on top of each other, and if one rectangle is stacked on //top of the other two, which are side by side.  

#include <bits/stdc++.h>
using namespace std;




int main() {
    freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> arr(n+1);

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        arr[b].push_back(a);
        arr[a].push_back(b);
    }

    int ans = 0;

    for(auto c:arr)
    {
        int x = c.size();
        // cout<<x<<endl;
        ans=max(ans, x);
    }

    cout<< ans+1;
     return 0;
}
