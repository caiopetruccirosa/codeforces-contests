#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // se todos os elementos são iguais
    // i == n e j == -1
    int i = 0, j = n-1;
    while (i < n && a[i] == a[0])
        i++;
    while (j >= 0 && a[j] == a[n-1])
        j--;

    if (a[0] == a[n-1]) {
        cout << max(j-i+1, 0) << '\n';
    } else {
        cout << min(n-i, j+1) << '\n';
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