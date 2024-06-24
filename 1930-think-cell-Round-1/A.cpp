#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(2*n+1);
    for (int i = 1; i <= 2*n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    ll sum = 0;
    for (int i = 1; i <= 2*n; i+=2)
        sum += a[i];
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