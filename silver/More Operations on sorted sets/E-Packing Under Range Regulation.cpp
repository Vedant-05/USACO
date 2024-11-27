#include <bits/stdc++.h>
#define inf 1000000007

using namespace std;
using pi = pair<int, int>;

int main()
{
      int t;
      cin>>t;

      while(t--)
      {
        int n;
        cin>>n;
        map<int,vector<int> > riRangeOnLi;
        set<int> lis;

        for(int i=0;i<n;i++)
        {
            int li,ri;
            cin>>li>>ri;
            riRangeOnLi[li].push_back(ri);
            lis.insert(li);
        }

        priority_queue<int, vector<int> , greater<int> > pqLeftBall;

        lis.insert(inf);
        
        int i = *(lis.begin());

        bool passing = true;

        while (i <= 1e9)
        {
           for( auto &xdRi : riRangeOnLi[i])
            {
                pqLeftBall.push(xdRi);
            }
             pqLeftBall.pop();

             if(pqLeftBall.empty())
             {
                i = *(lis.lower_bound(i+1));
             }
             else
             {
                if(pqLeftBall.top() <= i)
                {
                     passing = false;
                     break;
                }
            
                    i+=1;
                
             }

        }

        if(!pqLeftBall.empty())
        {
            passing=false;
        }

        if(passing)
        {
            cout<<"Yes"<<endl;
                       


        }
        else
        {
            cout<<"No"<<endl;
                   


        }
        


      }
      return 0;
}
