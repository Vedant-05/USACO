#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> attack;
    vector<int> defence;

    for(int i = 0; i < n; i++) {
        string s;
        int b;
        cin >> s >> b;
        if(s == "ATK") {
            attack.push_back(b);
        } else {
            defence.push_back(b);
        }
    }

    sort(attack.begin(), attack.end());
    sort(defence.begin(), defence.end());

    vector<int> ciel(m);
    multiset<int> cards;
    
    for(int i = 0; i < m; i++) {
        cin >> ciel[i];
        cards.insert(ciel[i]);
    }
    sort(ciel.begin(), ciel.end());

    int ans = 0;

    // Case 1: Not killing all attack cards
    {
        int temp = 0;
        int atk_idx = 0;
        for(int i = m-1; i >= 0 && atk_idx < attack.size(); i--) {
            if(ciel[i] >= attack[atk_idx]) {
                // cout<<i<<" "<<m<<" "<<ciel[i]<<" "<<attack[atk_idx]<<endl;
                temp += ciel[i] - attack[atk_idx];
                atk_idx++;
            }
        }
        ans = temp;
    }

    // cout<< ans <<"not anel to "<<endl;

    // Case 2: Try killing all cards
    {
        multiset<int> temp_cards = cards;
        bool possible = true;

        // Kill defense cards first
        for(int def : defence) {
            auto it = temp_cards.upper_bound(def);
            if(it == temp_cards.end() || *it<=def) {
                possible = false;
                break;
            }
            temp_cards.erase(it);
        }

        // Try killing all attack cards
        if(possible && temp_cards.size() >= attack.size()) {
            // Check if remaining cards can actually kill all attack cards
            vector<int> remain;
            remain.clear();
            for(int x : temp_cards) {
                remain.push_back(x);
            }
            
            int atk_idx = attack.size()-1;
            bool can_kill_all = true;
            
            // Try matching highest cards with attack cards
            for(int i = remain.size()-1; i >= 0 && atk_idx >= 0; i--) {
                // cout<<remain[i]<<" "<<remain.size()<<" "<<attack[atk_idx]<<endl;
                if(remain[i] >= attack[atk_idx]) {
                    atk_idx--;
                } else {
                    can_kill_all = false;
                    break;
                }
            }

        //    cout<<can_kill_all<<endl;

            if(can_kill_all) {
                int sum_attack = 0;
                for(int x : attack) {
                    sum_attack += x;
                }

                int sum_ciel = 0;
                auto it = temp_cards.end();
                
                // Take highest cards for attack
               for(auto x : remain)
               {
                sum_ciel+=x;
               }

                ans = max(ans, sum_ciel - sum_attack);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
