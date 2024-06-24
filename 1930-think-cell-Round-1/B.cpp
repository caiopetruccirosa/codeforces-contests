#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n+1);
    for (int i = 1, k = 1; i <= n; i+=2, k++)
        p[i] = k;
    for (int i = 2, k = n; i <= n; i+=2, k--)
        p[i] = k;

    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';
    cout << '\n';
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}