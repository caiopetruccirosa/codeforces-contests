#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll f, a, b;
        cin >> n >> f >> a >> b;

        vector<ll> m(n+1);
        m[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> m[i];

        ll c = f;
        for (int i = 1; i <= n && c > 0; i++) {
            if (a*(m[i]-m[i-1]) < b) {
                c -= a*(m[i]-m[i-1]);
            } else {
                c -= b;
            }
        }

        if (c > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}