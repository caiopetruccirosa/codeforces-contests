#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int n;
vector<pair<ll,int>> tree;
vector<ll> ans;

pair<ll,int> query(int node, int node_low, int node_high, int query_low, int query_high) {
    // Segment completely inside query range
    if (query_low <= node_low && node_high <= query_high)
        return tree[node];

    // Segment completely outside query range
    if (node_high < query_low || node_low > query_high)
        return {0,0};
    
    int node_mid = (node_low + node_high) / 2;
    return max(query(2*node, node_low, node_mid, query_low, query_high), query(2*node+1, node_mid+1, node_high, query_low, query_high));
}

void update(int node, int node_low, int node_high, int query_target) {
    // Segment completely inside query range
    if (query_target == node_low && node_high == query_target) {
        tree[node] = {0, 0};
        return;
    }

    // Segment completely outside query range
    if (node_high < query_target || node_low > query_target)
        return;
    
    int node_mid = (node_low + node_high) / 2;
    update(2*node, node_low, node_mid, query_target);
    update(2*node+1, node_mid+1, node_high, query_target);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

void build(vector<ll> &a) {
    while (__builtin_popcount(n) != 1) {
        n++;
    }
    tree.resize(2*n);

    for (int i = 0; i < a.size(); i++)
        tree[n+i] = {a[i]+i+1, i};

    for (int i = n-1; i >= 1; i--)
        tree[i] = max(tree[2*i], tree[2*i+1]);
}

void get_ans(int l, int r, int offset) {
    if (l > r)
        return;

    pair<ll,int> p = query(1, 0, n-1, l, r);
    
    if (ans.size() > 0 && ans.back() == p.first-offset)
        offset++;
    ans.push_back(p.first-offset);
    get_ans(l, p.second-1, offset);
    get_ans(p.second+1, r, offset);
    return;
}

void solve() {
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(a);
    ans.clear();
    get_ans(0, a.size()-1, 0);

    sort(ans.begin(), ans.end(), greater<ll>());

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}