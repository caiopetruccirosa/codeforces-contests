#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += abs(a);
    }
    cout << sum << '\n';
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}