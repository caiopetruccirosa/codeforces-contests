#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll x, y; cin >> x >> y;

    int sqrtn;
    for (sqrtn = 1; sqrtn*sqrtn < n; sqrtn++);

    vector<ll> a(n), amodx(n), amody(n);
    vector<vector<pair<ll,ll>>> asqrt(sqrtn);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        asqrt[i/sqrtn].push_back({a[i]%x,a[i]%y});
    }

    for (int i = 0; i < sqrtn; i++)
        sort(asqrt[i].begin(), asqrt[i].end());

    ll pairs = 0;
    for (int i = 0; i < n; i++) {
        pair<ll,ll> target = {(x-(a[i]%x))%x,a[i]%y};
        for (int j = 0; j < i/sqrtn; j++) {
            pairs += upper_bound(asqrt[j].begin(),asqrt[j].end(),target) - lower_bound(asqrt[j].begin(),asqrt[j].end(),target);
        }
        for (int j = (i/sqrtn)*sqrtn; j < i; j++) {
            if (target.first == a[j]%x && target.second == a[j]%y) {
                pairs++;
            }
        }
    }
    cout << pairs << '\n';
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}