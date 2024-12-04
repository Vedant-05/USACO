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
     
     int a,b,c;
     cin>>a>>b>>c;
     int n;
     cin>>n;

     priority_queue<int,vector<int>,greater<int> > pqUSB;
     priority_queue<int,vector<int>,greater<int> > pqPS2;


     for (int i = 0; i < n; i++)
     {
        int x;
        string z;
        cin>>x>>z;

        if(z == "USB")
        {
            pqUSB.push(x);
        }
        else
        {
            pqPS2.push(x);
        }
     }

     long long ans = 0;
     int mouse = 0;

     while(a !=0 && !pqUSB.empty())
     {
        mouse++;
        int tp = pqUSB.top();
        pqUSB.pop();
        ans+=tp;
        a--;
    }

    while(b !=0 && !pqPS2.empty())
     {
        mouse++;
        int tp = pqPS2.top();
        pqPS2.pop();
        ans+=tp;
        b--;
    }

    while(c!=0 && (!pqUSB.empty() || !pqPS2.empty()))
    {
       int tp1 = pqUSB.empty() ? INT_MAX :pqUSB.top();
       int tp2 = pqPS2.empty() ? INT_MAX :pqPS2.top();

       if(tp1 < tp2)
       {
        pqUSB.pop();
        mouse++;
        ans+=tp1;
        c--;
       }
       else
       {
        pqPS2.pop();
        mouse++;
        ans+=tp2;
        c--;
       }

    }


    cout<< mouse <<" "<<ans<<endl;

     

}
