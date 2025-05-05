#include <bits/stdc++.h>
using namespace std;

map<string, set<int>> mp;

int main() {
    int T; cin >> T;
    while(T--) {
        string op; cin >> op;
        if (op == "insert") {
            string index; int value;
            cin >> index >> value;
            mp[index].insert(value);
        }
        else if (op == "delete") {
            string index; int value;
            cin >> index >> value;
            mp[index].erase(value);
        }
        else {
            string index;
            cin >> index;
            auto s = mp[index];
            if (s.empty()) cout << "null\n";
            else {
                for (auto x : s) cout << x << ' ';
                cout << '\n';
            }
        }
    }
}