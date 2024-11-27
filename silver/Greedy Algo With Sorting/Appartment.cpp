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
     

     int n,m,k;
     cin>>n>>m>>k;

     vector<pair<int,int> > appartmentDesired(n);

     for(int i = 0;i<n;i++)
     {
        int a;
        cin>>a;

        appartmentDesired[i].f = a-k;
        appartmentDesired[i].s = a + k;
     }

     sort(all(appartmentDesired));

     multiset<int> mpApt;

     for(int i=0;i<m;i++)
     {
        int a;
        cin>>a;
        mpApt.insert(a);
     }


     int ans = 0;


     for(int i=0;i<n;i++)
     {
        if(!mpApt.empty()){auto mostProp = (mpApt.lower_bound(appartmentDesired[i].f));

        if(mostProp!= mpApt.end() && *mostProp <= appartmentDesired[i].s)
        {
            ans++;
            mpApt.erase(mostProp);
        }}


     }


     cout<<ans<<endl;

     




}