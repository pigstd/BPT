#include <bits/stdc++.h>
using namespace std;

int mp[1005][1005];

int main(int argc, char **argv) {
    int seed = stoi(argv[1]);
    mt19937 rnd(seed);
    int T = 300000;
    const int xlim = 1000, ylim = 1000;
    cout << T << '\n';
    while(T--) {
        int x = rnd() % xlim + 1, y = rnd() % ylim + 1;
        int op = rnd() & 1;
        if (op == 1) {
            while(mp[x][y]) x = rnd() % xlim + 1, y = rnd() % ylim + 1;
            cout << "insert " << x << ' ' << y << '\n';
            mp[x][y] = 1;
        }
        else {
            int t = 1000;
            while(t-- && !mp[x][y]) x = rnd() % xlim + 1, y = rnd() % ylim + 1;
            cout << "delete " << x << ' ' << y << '\n';
            mp[x][y] = 0;
        }
    }
}