#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_possible(string a, string b) {
    for (int i = 0; i < a.length()-1; i++)
        if (a[i] == b[i] && a[i] == '0' && a[i+1] == b[i+1] && a[i+1] == '1')
            return true;
    return false;
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (is_possible(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}