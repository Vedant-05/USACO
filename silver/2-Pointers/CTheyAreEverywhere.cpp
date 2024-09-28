#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   string s;
   cin>>s;
   map<char,int> mp;

   int types = 0;

   for(int i=0;i<s.length();i++)
   {
     if(mp[s[i]]==0)
     {
       types++;
       mp[s[i]]++;
     }
   }

   map<char,int> currStat;
   int currDiff = 0;

   int ans = n;
   int left = 0;

   for(int right = 0; right < s.length(); right++)
   {
     if(currStat[s[right]] == 0)
     {
        currDiff++;
        currStat[s[right]]++;
     }
     else
     {
        currStat[s[right]]++;
     }
     while(currDiff == types && left<=right)
     {
        ans = min(ans,right-left+1);
        left++;
        currStat[s[left-1]]--;

        if(currStat[s[left-1]] == 0)
        {
            currDiff--;
        }
     }
   }

   cout<<ans<<endl;
 
}
