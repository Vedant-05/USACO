#include <bits/stdc++.h>

using namespace std;



int main()
{

  
  int n,x;
  cin>>n>>x;

  vector<int> arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  long long sum=0;

  long long ans = 0;

  map<long long,int> mp;
// multiset<long long> mp;

mp[0] = 1;
  for(int i=0;i<n;i++)
  {

    sum+=arr[i];

    ans+=mp[sum-x];
    mp[sum]++;
  }



  cout<<ans<<endl;

  
  return 0;
   
}
