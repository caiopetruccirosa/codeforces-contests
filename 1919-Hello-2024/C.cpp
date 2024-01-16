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

        int s_len = 0, t_len = 0;
        vector<int> s(n), t(n);
        for (int i = 0; i < n; i++) {
            if (s_len == 0) {
                s[s_len] = a[i];
                s_len++;
            } else if (t_len == 0) {
                t[t_len] = a[i];
                t_len++;
            } else if (t[t_len-1] >= a[i] && s[s_len-1] >= a[i]) {
                int j = i+1;
                while (j < n && a[j-1] >= a[j]) {
                    j++;
                }
                if (s[s_len-1] >= a[j]) {
                    int k = i;
                    while (k < j) {
                        t[t_len] = a[k];
                        t_len++;
                        k++;
                    }
                    i = k-1;
                } else {
                    int k = i;
                    while (k < j) {
                        s[s_len] = a[k];
                        s_len++;
                        k++;
                    }
                    i = k-1;
                }
            } else if (s[s_len-1] >= a[i]) {
                s[s_len] = a[i];
                s_len++;
            } else {
                t[t_len] = a[i];
                t_len++;
            }
        }
        int penalty = 0;
        for (int i = 0; i < s_len-1; i++)
            if (s[i] < s[i+1])
                penalty++;
        for (int i = 0; i < t_len-1; i++)
            if (t[i] < t[i+1])
                penalty++;
        cout << penalty << '\n';
    }

    return 0;
}