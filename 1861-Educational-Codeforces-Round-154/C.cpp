#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_possible(string s) {
    int arr_size = 0, to_decrease = 0, to_increase = 0;
    stack<int> last_size_when_sorted, last_size_could_sorted;
    last_size_when_sorted.push(0);
    last_size_could_sorted.push(0);
    for (char c: s) {
        //cout << "Letra atual: " << c << '\n';
        //cout << "Tamanho atual: " << arr_size << '\n';
        //cout << "to_increase atual: " << to_increase << '\n';
        //cout << "to_decrease atual: " << to_decrease << '\n';
        if (c == '+') {
            if (last_size_could_sorted.top() == arr_size+to_increase) {
                last_size_could_sorted.push(arr_size+to_increase+1);
            }
            to_increase++;
        } else if (c == '-') {
            to_decrease++;
        } else if (c == '0') {
            arr_size = arr_size - to_decrease + to_increase;
            to_decrease = 0;
            to_increase = 0;
            if (arr_size < 2) {
                return false;                
            }
        } else if (c == '1') {
            int ls = last_size_when_sorted.top();
            if (arr_size-to_decrease <= ls) {
                arr_size = arr_size - to_decrease + to_increase;
                to_decrease = 0;
                to_increase = 0;
                last_size_when_sorted.push(arr_size);
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        if (is_possible(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}