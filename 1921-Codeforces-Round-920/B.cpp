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
        cin >> n;

        string s, f;
        cin >> s >> f;

        int diff_cat_on_s = 0, diff_cat_on_f = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && f[i] == '0')
                diff_cat_on_s++;
            if (s[i] == '0' && f[i] == '1')
                diff_cat_on_f++;
        }

        cout << max(diff_cat_on_s, diff_cat_on_f) << '\n';
    }

    return 0;
}