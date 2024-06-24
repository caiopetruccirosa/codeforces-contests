#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ii pair<int,int>

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> monsters(n);
    for (int i = 0; i < n; i++)
        cin >> monsters[i].second;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        monsters[i].first = abs(x);
    }
    sort(monsters.begin(), monsters.end());

    ll used = 0;
    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
        auto [x, a] = monsters[i];
        if (x*k-used < a) {
            possible = false;
        } else {
            used += a;
        }
    }
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}