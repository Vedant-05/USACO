#include <bits/stdc++.h>

using namespace std;



int main()
{

    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
  int n;
  cin>>n;

  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  long long sum=0;

  vector<long long> prefix(n+1,0);

  prefix[0] = 0;

  for(int i=1;i<=n;i++)
  {
    prefix[i] = prefix[i-1] + arr[i-1];
  }

  int len=0;

  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=n-i;j++)
    {
          if((prefix[j+i]-prefix[j]) % 7 == 0)
          {
               len=max(len,i);
          }
    }
  }

  cout<<len<<endl;
  return 0;
   
}
