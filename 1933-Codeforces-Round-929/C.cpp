#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    ll a, b, l;
    cin >> a >> b >> l;

    vector<ll> axs, bys;
    ll ax = 1, by = 1;
    while (ax <= l) {
        axs.push_back(ax);
        ax = ax*a;
    }
    while (by <= l) {
        bys.push_back(by);
        by = by*b;
    }

    set<ll> ks;
    for (int i = 0; i < axs.size(); i++) {
        for (int j = 0; j < bys.size(); j++) {
            if ((l%(axs[i]*bys[j])) == 0) {
                ks.insert((l/(axs[i]*bys[j])));
            }
        }
    }
    cout << ks.size() << '\n';
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}