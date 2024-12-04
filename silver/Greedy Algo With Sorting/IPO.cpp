class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    
    int n = capital.size();
      
      priority_queue<int> pq;
      

      map<int,vector<int>> mp;

      mp.clear();

      for(int i = 0;i<n;i++)
      {
        if(capital[i]<=w)
        {
            pq.push(profits[i]);
        }
        else
        {
            mp[capital[i]].push_back(profits[i]);
        }
      }
      sort(capital.begin(),capital.end());
      long long ans = 0;

      while(k!=0 && !pq.empty())
      {
            ans+= pq.top();
            
            int newWealth = w + pq.top();
            pq.pop();
            k--;
            auto it = lower_bound(capital.begin(),capital.end(),w);
            while(it!=capital.end() && *it<=newWealth)
            {
                if(mp[*it].size() == 0)
                {

                }
                else
                {
                    for( auto c: mp[*it])
                    {
                        pq.push(c);
                        // cout<<w<<" "<<c<<" "<<*it<<endl;
                    }
                    mp[*it].clear();
                }

                it++;
            }
            w=newWealth;
      }
     
    return w;

    }

};
