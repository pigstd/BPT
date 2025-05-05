#include <bits/stdc++.h>
using namespace std;

int mp[20][20];

int main(int argc, char **argv) {
    int seed = stoi(argv[1]);
    mt19937 rnd(seed);
    int T = 50;
    cout << T + 3 << '\n';
    while(T--) {
        int x = rnd() % 3 + 1, y = rnd() % 10 + 1;
        int op = rnd() & 1;
        if (op == 1) {
            while(mp[x][y]) x = rnd() % 3 + 1, y = rnd() % 10 + 1;
            cout << "insert " << x << ' ' << y << '\n';
            mp[x][y] = 1;
        }
        else {
            int t = 1000;
            while(t-- && !mp[x][y]) x = rnd() % 3 + 1, y = rnd() % 10 + 1;
            cout << "delete " << x << ' ' << y << '\n';
            mp[x][y] = 0;
        }
    }
    cout << "find 1\n";
    int cnt = 0;
    for (int i = 1; i <= 10; i++) if (mp[1][i]) cerr << i << ' ', cnt++;
    if (cnt == 0) cerr << "null\n";
    else cerr << '\n';
    cout << "find 2\n";
    cnt = 0;
    for (int i = 1; i <= 10; i++) if (mp[2][i]) cerr << i << ' ', cnt++;
    if (cnt == 0) cerr << "null\n";
    else cerr << '\n';
    cout << "find 3\n";
    cnt = 0;
    for (int i = 1; i <= 10; i++) if (mp[3][i]) cerr << i << ' ', cnt++;
    if (cnt == 0) cerr << "null\n";
    else cerr << '\n';
}