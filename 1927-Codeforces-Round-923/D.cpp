#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ii pair<int,int>

using namespace std;

const int MAXN = 200005;

int n, q, a[MAXN];
ii t[4*MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {-1, -1};
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        if (t[v*2].first != -1 && t[v*2].second != -1) {
            t[v] = t[v*2];
        } else if (t[v*2+1].first != -1 && t[v*2+1].second != -1) {
            t[v] = t[v*2+1];
        } else {
            if (a[tl] != a[tr]) {
                t[v] = {tl, tr};
            } else {
                t[v] = {-1, -1};
            }
        }
    }
}

ii query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {-1, -1};
    if (l == tl && r == tr)
        return t[v];

    int tm = (tl + tr) / 2;
    if (r <= tm) {
        return query(v*2, tl, tm, l, r);
    } else if (l > tm) {
        return query(v*2+1, tm+1, tr, l, r);
    } else {
        ii ansl = query(v*2, tl, tm, l, min(r, tm));
        ii ansr = query(v*2+1, tm+1, tr, max(l, tm+1), r);
        if (ansl.first != -1 && ansl.second != -1) {
            return ansl;
        } else if (ansr.first != -1 && ansr.second != -1) {
            return ansr;
        } else {
            if (a[l] != a[r]) {
                return {l, r};
            } else {
                return {-1, -1};
            }
        }
    }
}

int main() {_
    int T; cin >> T;
    
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        build(1, 0, n-1);

        cin >> q;
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ii ans = query(1, l, r, l, r);
            cout << ans.first+1 << ' ' << ans.second+1 << '\n';
        }
        cout << '\n';
    }
    return 0;
}