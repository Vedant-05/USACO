// upper N / 2 cards are for the first half, lower N / 2 cards are for the second half.
// For first half, pick the card that is the least greater than Elsie's card
// For second half, pick the card that is the least smaller than Elsie's card

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    
    int N; cin >> N;
    
    set<int> bessie_cards;
    int elsie_cards[N];
    
    for (int i = 1; i <= 2 * N; ++i) bessie_cards.insert(i);
    
    for (int i = 0; i < N; ++i) {
        cin >> elsie_cards[i];
        bessie_cards.erase(elsie_cards[i]);
    }
    
    set<int> lower_half;
    set<int> upper_half;
    
    int i = 0;
    for (int card : bessie_cards) {
        if (i < N / 2) lower_half.insert(card);
        else if (i < N) upper_half.insert(card);
        else break;
        i++;
    }
    
    int ans = 0;
    for (int i = 0; i < N / 2; ++i) {
        auto it = upper_half.upper_bound(elsie_cards[i]);
        if (it != upper_half.end()) {
            ans++;
            upper_half.erase(it);
        }
        else {
            upper_half.erase(upper_half.begin());
        }
    }
    for (int i = N / 2; i < N; ++i) {
        auto it = lower_half.upper_bound(elsie_cards[i]);
        if (it != lower_half.begin()) {
            it--;
            ans++;
            lower_half.erase(it);
        }
        else {
            lower_half.erase(prev(lower_half.end()));
        }
    }
    
    cout << ans << "\n";
}
