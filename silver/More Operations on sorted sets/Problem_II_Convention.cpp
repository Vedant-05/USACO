#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   int n;
   cin>>n;

   vector<vector<int>> cows;

   for(int i=0;i<n;i++)
   {
       int x,y;
       cin>>x>>y;
       cows.push_back({i,x,y});
   }

   auto cmp = [](const vector<int> &a,const vector<int> &b){
       return a[1]<b[1];
   };

   sort(cows.begin(),cows.end(),cmp);

   int time  = 0;
   int longest_wait = 0;
   int curr = 0;

   set<vector<int>> waiting_list;

   while(curr<n || !waiting_list.empty())
   {
         if(curr< n && cows[curr][1]<=time)
         {
            waiting_list.insert(cows[curr]);
            curr++;

         }
         else if(waiting_list.empty())
         {
             time = cows[curr][1] + cows[curr][2];
             curr++;
         }
         else
         {
            vector<int> top_priority = *waiting_list.begin();
            waiting_list.erase(waiting_list.begin());
            longest_wait = max(longest_wait,time - top_priority[1]);
            time = time + top_priority[2];
         }
   }

   cout<<longest_wait<<endl;

    return 0;
}
