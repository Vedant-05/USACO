#include <bits/stdc++.h>
using namespace std;

int maxim = 1e5;
vector<vector<int>> factors(maxim+2);

void init() {
    
    for(int i=1;i<=maxim;i++)
    {
        for(int j=i;j<=maxim;j+=i)
        {
            factors[j].push_back(i);
        }
    }
}

int main() {
   init();
  int t;
  cin>>t;

 while(t--)
 {
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

   vector<int> freq(m+2,0);

    int uniqueCount = 0;
    int ans = INT_MAX;
    int left = 0;

    for(int right = 0;right<n;right++)
    {
        for(auto x: factors[arr[right]])
        {
            if(x>m) break;
            else
            {
                if(freq[x] == 0)
                {
                    uniqueCount++;
                    freq[x]++;
                }
                else
                {
                    freq[x]++;
                }
            }
        }

       
           

            while(uniqueCount == m)
            {
                 ans = min(ans,(arr[right]-arr[left]));

                 for(auto x: factors[arr[left]])
                 {

                    if(x>m) break;
                    freq[x]--;
                    if(freq[x] == 0)
                    {
                        uniqueCount--;
                    }
                 }

                 left++;

            }
        
         
    }

    cout<<(ans >= INT_MAX?-1:ans)<<endl;
 } 
 
}
