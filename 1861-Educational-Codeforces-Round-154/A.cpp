#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i*i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

bool is_possible(string s, string &a) {
    if (s.length() < 2)
        return false;

    ll x = stoi(s);
    if (is_prime(x)) {
        a = s;
        return true;
    }

    for (int i = 0; i < s.length(); i++) {
        string b = s.substr(0, i) + s.substr(i+1, s.length());
        if (is_possible(b, a)) {
            return true;
        }
    }

    return false;
}


int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        string s, a = "";
        cin >> s;
        if (is_possible(s, a))
            cout << a << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}