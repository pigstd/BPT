#include <iostream>
#include <iterator>
#include <string>
#include "database.hpp"
#include "vector.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class mystr {
    int len;
    char ch[65];
public:
    mystr() {
        len = 0;
        ch[0] = '\0';
        for (int i = 1; i < 65; i++) ch[i] = 0;
    }
    mystr(string s) {
        len = s.size();
        for (int i = 0; i < len; i++) ch[i] = s[i];
        ch[len] = '\0';
        for (int i = len + 1; i < 65; i++) ch[i] = 0;
    }
    bool operator <(const mystr& b) const {
        for (int i = 0; i < std::min(len, b.len); i++)
            if (ch[i] != b.ch[i]) return ch[i] < b.ch[i];
        return len < b.len;
    }
    bool operator ==(const mystr& b) const {
        if (len != b.len) return 0;
        for (int i = 0; i < len; i++)
            if (ch[i] != b.ch[i]) return 0;
        return 1;
    }
    bool operator <=(const mystr& b) const {
        for (int i = 0; i < std::min(len, b.len); i++)
            if (ch[i] != b.ch[i]) return ch[i] <= b.ch[i];
        return len <= b.len;
    }
    // 转化为 string
    operator string() {
        string res = "";
        for (int i = 0; i < len; i++) res += ch[i];
        return res;
    }
};

#define ll long long
#define i128 __int128

const i128 Mod = 99234523452349217;
const i128 base = 998244353;

ll hs(string s) {
    i128 hs = 0;
    for (auto ch : s)
        hs = (hs * base + (int)(ch) + 1) % Mod;
    return hs;
}

int main() {
    cin.sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    // is_cover: when submit, upd to 0
    BPTdatabase<ll, int, 0, 113> database("BPT");
    while(T--) {
        string op; cin >> op;
        // cerr << "opt done" << T << ' ' << op << '\n';
        if (op == "insert") {
            string index; int value;
            cin >> index >> value;
            database.insert(hs(index), value);
        }
        else if (op == "delete") {
            string index; int value;
            cin >> index >> value;
            database.del(hs(index), value);
        }
        else if (op == "find") {
            string index;
            cin >> index;
            auto v = database.find_with_vector(hs(index));
            if (v.size() == 0) cout << "null\n";
            else {
                for (auto x : v) cout << x << ' ';
                cout << '\n';
            }
        }
        // cerr << "-----------\n";
        // database.print_tree();
        // cerr << "-----------\n";
        // cerr << "opt done\n" << endl;
    }
}