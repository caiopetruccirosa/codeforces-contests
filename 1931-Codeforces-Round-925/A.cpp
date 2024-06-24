#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

string solve(int n) {
    for (int a = 1; a <= 26; a++) {
        for (int b = 1; b <= n-a && b <= 26; b++) {
            int c = n-a-b;
            if (c <= 26) {
                string s = "";
                s += (char)('a'+a-1);
                s += (char)('a'+b-1);
                s += (char)('a'+c-1);
                return s;
            }
        }
    }
    return "";
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}