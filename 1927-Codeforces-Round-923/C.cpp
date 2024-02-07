#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n+1, 0), b(m+1, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];

        set<int> in_a, in_b, intersection;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= k) {
                in_a.insert(a[i]);
            }
        }
        for (int i = 1; i <= m; i++) {
            if (b[i] <= k) {
                if (in_a.find(b[i]) != in_a.end()) {
                    intersection.insert(b[i]);
                }
                in_b.insert(b[i]);
            }
        }
        if (in_a.size()-intersection.size() <= k/2 && 
            in_b.size()-intersection.size() <= k/2 &&
            in_a.size()+in_b.size()-intersection.size() == k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}