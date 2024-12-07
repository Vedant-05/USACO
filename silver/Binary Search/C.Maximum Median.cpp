#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

int main() { 
     cin.tie(0)->sync_with_stdio(0);
     
     int n,k;
     cin>>n>>k;

     vector<int> vc(n);

     for(int i=0;i<n;i++)
     {
        cin>>vc[i];
     }

     sort(all(vc));


    int middleElementId = n/2;
    auto it = upper_bound(vc.begin(),vc.end(),vc[middleElementId]);
    int ansCanBe = 0;

    while(k>0)
    {
        // cout<<k<<" k "<<endl;
        if(it!=vc.end())
        {
            auto temp = vc.begin() + n/2;
            // cout<<it-temp<<" it temp "<<endl;

            if(it-temp<=k)
            {
                int valToAchieve = *it;
                int currValue = vc[middleElementId] + ansCanBe;
                long long eachIncrement = valToAchieve - currValue;
                int howManyInc = k;

                if((eachIncrement * (it-temp)) <= howManyInc)
                {
                    k-=(eachIncrement * (it-temp));
                    ansCanBe+=(eachIncrement);
                    it = upper_bound(vc.begin(),vc.end(),(vc[middleElementId] + ansCanBe));
                }
                else
                {
                    k-=(howManyInc);
                    ansCanBe+=(howManyInc/(it-temp));
                    break;
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            auto temp = vc.begin() + n/2;

            if((it-temp)<=k)
            {
                ansCanBe+=(((k / (it-temp))));
                break;
            }
            else
            {
                break;
            }
        }
    }

    cout<<vc[n/2]+ansCanBe<<endl;



}
