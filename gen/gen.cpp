#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> mp;

int main(int argc, char **argv) {
    int seed = stoi(argv[1]);
    mt19937 rnd(seed);
    int T = 300000;
    const int xlim = 10000, ylim = 10000;
    cout << T + xlim << '\n';
    while(T--) {
        int x = rnd() % xlim + 1, y = rnd() % ylim + 1;
        int op = rnd() & 1;
        if (op == 1) {
            while(mp.find({x, y}) != mp.end())
                x = rnd() % xlim + 1, y = rnd() % ylim + 1;
            mp.insert({x, y});
            cout << "insert " << x << ' ' << y << '\n';
        }
        else {
            int t = 100;
            while(t-- && mp.lower_bound({x, y}) != mp.end())
                x = rnd() % xlim + 1, y = rnd() % ylim + 1;
            auto p = mp.lower_bound({x, y});
            if (p != mp.end()) x = p->first, y = p->second;
            cout << "delete " << x << ' ' << y << '\n';
        }
    }
    for (int i = 1; i <= xlim; i++) cout << "find " << i << '\n';
}