#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        if (s.find('1') < s.find('3'))
            cout << 13 << '\n';
        else
            cout << 31 << '\n';
    }
    return 0;
}