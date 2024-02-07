#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<vector<char>> characters(n+1);
        for (char c = 'z'; c >= 'a'; c--)
            characters[0].push_back(c);
            
        string s;
        for (int i = 0; i < n; i++) {
            char c = characters[a[i]].back(); characters[a[i]].pop_back();
            characters[a[i]+1].push_back(c);
            s += c;
        }
        cout << s << '\n';
    }
    return 0;
}