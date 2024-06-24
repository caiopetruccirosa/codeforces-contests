#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    int smallest_idx = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[smallest_idx])
            smallest_idx = i;
    }
    bool has_non_divisable = false, has_equal = false;
    for (int i = 0; i < n; i++) {
        if (i != smallest_idx) {
            if (a[i] == a[smallest_idx])
                has_equal = true;
            if (a[i] % a[smallest_idx] != 0)
                has_non_divisable = true;
        }
    }
    if (!has_equal || (has_non_divisable && has_equal))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}