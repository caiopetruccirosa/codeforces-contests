#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    int first_chip = 0, last_chip = 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!first_chip && a[i])
            first_chip = i;
        if (a[i])
            last_chip = i;
    }

    bool finished = false;
    int ops = 0;
    while (last_chip > first_chip && !finished) {
        int closest_free_chip = 0;
        for (int i = last_chip-1; i > first_chip && !closest_free_chip; i--)
            if (!a[i])
                closest_free_chip = i;

        if (closest_free_chip != 0) {
            a[closest_free_chip] = 1;
            a[last_chip] = 0;
            for (int i = first_chip; i <= n; i++)
                if (a[i])
                    last_chip = i;
            ops++;
        } else {
            finished = true;
        }
    }
    cout << ops << '\n';
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}