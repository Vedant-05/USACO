#include <bits/stdc++.h>
using namespace std;


long long max(long long a,long long b)
{
    if(a>b) return a;
    else return b;
}



int main() {

    ios::sync_with_stdio(false);
	cin.tie(NULL);
   int n,m;

   cin>>n>>m;
   set<int> sm;
   sm.insert(0);
   sm.insert(n);
   multiset<int> gap;
   gap.insert(n);
   

   for(int i=0;i<m;i++)
   {
      int a;
      cin>>a;

      auto posright = sm.upper_bound(a);
      auto posleft = posright;
      posleft--;
      gap.erase(gap.find(*posright - *posleft));
    //   if we just use gap.erase() with value than it will erase all the instance of that value rather we ant to erase only one instance
      gap.insert(a - *posleft);
      gap.insert(*posright - a);
      sm.insert(a);

      auto ans = gap.end();
      ans--;
      cout<<*ans<<" ";
     
   }

   return 0;

}
