#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    ll sum = 0;
    bool hasremainder1 = false, hasremainder2 = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i]%3 == 1)
            hasremainder1 = true;
        if (a[i]%3 == 2)
            hasremainder2 = true;
    }

    int remainder = sum % 3;
    if (remainder == 0)
        cout << 0;
    else if ((remainder == 1 && hasremainder1) || (remainder == 2 && hasremainder2))
        cout << 1;
    else
        cout << (3 - remainder);
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