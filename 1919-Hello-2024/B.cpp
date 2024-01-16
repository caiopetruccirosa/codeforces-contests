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
        string s;
        cin >> n >> s;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                cnt++;
            } else {
                cnt--;
            }
        }
        cout << abs(cnt) << '\n';
    }

    return 0;
}