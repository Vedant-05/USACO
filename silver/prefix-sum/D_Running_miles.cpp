#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        for(int i=0;i<n;i++)
        {
            prefix[i] = arr[i] + i;
            suffix[i] = arr[i] - i;
        }
        for(int i=0;i<n;i++)
        {
            prefix[i] = max(prefix[i],(i>0?prefix[i-1]:prefix[i]));
        }

        for(int i=n-1;i>=0;i--)
        {
            suffix[i] = max(suffix[i],(i<n-1?suffix[i+1]:suffix[i]));

        }

        int ans = 0;

        for(int i=1;i<n-1;i++)
        {  
            ans = max(ans,prefix[i-1]+suffix[i+1]+arr[i]);
        }

        cout<<ans<<endl;
    }
}
