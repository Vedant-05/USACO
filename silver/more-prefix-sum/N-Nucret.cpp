#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2e3;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=1;i<n;i++)
    {
        arr[i] = max(arr[i],arr[i-1]-m);
    }

    for(int i=n-1;i>0;i--)
    {
           arr[i-1] = max(arr[i-1],arr[i]-m);
    }
    

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
