#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_possible(vector<vector<int>> &dp, string a, string b, int l, int r) {
    if (l > r)
        return true;

    if (dp[l][r] != -1)
        return dp[l][r];

    if (l == r) {
        dp[l][r] = a[l] == b[r];
        return a[l] == b[r];
    }

    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            if (a[i] == b[i] && 
                a[j] == b[j] && 
                a[j] == b[i] && 
                is_possible(dp, a, b, l, i-1) && 
                is_possible(dp, a, b, j+1, r)) {
                    dp[l][r] = 1;
                    return true;
                }
        }
    }

    dp[l][r] = 0;
    return false;
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        string a, b;
        cin >> a >> b;

        vector<vector<int>> dp(a.length(), vector<int>(a.length(), -1));
        if (is_possible(dp, a, b, 0, a.length()-1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}