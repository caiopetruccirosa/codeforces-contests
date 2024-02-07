#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                r = i;
                if (l == -1) {
                    l = i;
                }
            }
        }
        cout << r-l+1 << '\n';
    }
    return 0;
}