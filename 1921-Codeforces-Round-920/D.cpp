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
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll D = 0;
        int al = 0, ar = n-1;
        int bl = 0, br = m-1;
        while (al <= ar) {
            if (abs(a[al]-b[br]) > abs(a[ar]-b[bl])) {
                D += abs(a[al]-b[br]);
                al++;
                br--;
            } else {
                D += abs(a[ar]-b[bl]);
                ar--;
                bl++;
            }
        }
        cout << D << '\n';
    }

    return 0;
}