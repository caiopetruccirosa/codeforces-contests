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
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        ull ways = 0;
        int i = 0, j = 1, k = 2;
        while (i < j && j < k && k < n) {
            if (max(a[i],a[j])+1 > a[k]) {
                ways++;
                k++;
            } else if (i+1 < j) {

            }
        }
        for (int i = 0; i < n-2; i++) {
            if (max(a[i],a[i+1])+1 > a[i+2]) {
                ways++;
            }
        }
        cout << ways << '\n';
    }

    return 0;
}