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

bool possible = false;


bool canDo(vector<pair<int,int> > pc,vector<char> winds,long long days,long long x,long long y,long long toX,long long toY)
{
    long long cx = x;
    long long cy = y;
    long long n = pc.size();

    long long completeCycle = days / n;

    long long remainingDays = days % n;

    cx+= ((pc[n-1].first * completeCycle) + (remainingDays !=0 ? pc[remainingDays-1].first : 0));
    cy+= ((pc[n-1].second * completeCycle) + (remainingDays !=0 ? pc[remainingDays-1].second : 0));


    long long ans = abs(cx-toX);
    ans+=abs(cy-toY);
    if(ans <= days)
    {
        possible = true;
        return true;
       
    }
    else
    {
        return false;
    }
}

int main() { 
     cin.tie(0)->sync_with_stdio(0);
     
     int currX,currY,toX,toY;

     cin>>currX>>currY>>toX>>toY;


     int n;
     cin>>n;

     vector<char> vc(n);

     for(int i=0;i<n;i++)
     {
        cin>>vc[i];
     }

     vector<pair<int,int> > pc(n);

     int dx = 0;
     int dy = 0;

     for(int i=0;i<n;i++)
     {
        if(vc[i] == 'U')
        {
            dy++;
        }
        else if(vc[i] == 'D')
        {
            dy--;
        }
        else if(vc[i] == 'L')
        {
            dx--;
        }
        else
        {
            dx++;
        }
        pc[i].first = dx;
        pc[i].second = dy;
     } 

     long long low = 0;
     long long high = 1e18;
     long long ans = 0;

     while(low<=high)
     {
        long long mid = low + ((high-low)/2);
        // cout<<low<<" "<<high<<endl;

        if(canDo(pc,vc,mid,currX,currY,toX,toY))
        {
            ans = mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }

     }


     if(possible == false)
     {
        cout<<-1<<endl;
     }
     else
     {
         cout<<ans<<endl;
     }

    
     




}
