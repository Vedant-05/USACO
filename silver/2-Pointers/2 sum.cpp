#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2e3;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++)
    {  int x;
        cin>>x;
        arr[i] = {x,i};
    }

    sort(arr.begin(),arr.end());
    
    int x = 0;
    int y= n-1;

    while(x<y)
    {
        if(arr[x].first+arr[y].first == m)
        {
            cout<<arr[x].second +1 <<" "<<arr[y].second + 1<<endl;
            return 0;
        }
        else if(arr[x].first + arr[y].first < m)
        {
            x++;
        }
        else
        {
            y--;
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
}
