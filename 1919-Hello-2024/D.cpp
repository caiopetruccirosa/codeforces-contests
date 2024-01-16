// NOT SOLVED
#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

using namespace std;

int group_leaves(vector<int> &a, pair<int,int> range) {
    auto [l, r] = range;
    if (r <= l)
        return -1;
    if (a[l]-a[l+1] == 1) {
        return group_leaves(a, make_pair(l+2, r));
    } else if (a[r]-a[r-1] == 1) {
        return group_leaves(a, make_pair(l, r-2));
    }
}

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

    }

    return 0;
}