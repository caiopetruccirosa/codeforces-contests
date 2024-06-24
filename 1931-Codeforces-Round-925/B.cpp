#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool solve() {
    int n; cin >> n;
    ll sum = 0, avg = 0, diff = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum/n;
    for (int i = n-1; i >= 0; i--) {
        diff += (a[i]-avg);
        if (diff > 0)
            return false;
    }
    return true;
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        if (solve()) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}