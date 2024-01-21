#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

using namespace std;

bool exists_template(string a, string b, string c, int n) {
    int exclusive_to_c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != c [i] && b[i] != c[i]) {
            exclusive_to_c++;
        }
    }
    return (exclusive_to_c > 0);
}

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n;
        string a, b, c;
        cin >> n >> a >> b >> c;
        if (exists_template(a, b, c, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}