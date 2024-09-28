#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<pair<long long,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<n-2;i++)
    {
        int reqSum = m-arr[i].first;
        if(reqSum<2) continue;

        int left = i+1;
        int right = n-1;
        while(left<right)
        {
            if(arr[left].first + arr[right].first == reqSum)
            {
                cout<<arr[i].second<<" "<< arr[left].second<<" "<<arr[right].second<<endl;
                return 0;
            }
            else if(arr[left].first + arr[right].first < reqSum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

    }

    cout<<"IMPOSSIBLE"<<endl;
}
