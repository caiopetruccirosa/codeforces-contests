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
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << max(max(abs(x1-x2), abs(x1-x3)), abs(x1-x4)) * max(max(abs(y1-y2), abs(y1-y3)), abs(y1-y4)) << '\n';
    }

    return 0;
}