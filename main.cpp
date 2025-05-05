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
};

int main() {
    int T; cin >> T;
    // is_cover: when submit, upd to 0
    BPTdatabase<mystr, int, 0, 4> database("BPT");
    while(T--) {
        // cerr << "opt done" << endl;
        string op; cin >> op;
        if (op == "insert") {
            string index; int value;
            cin >> index >> value;
            database.insert(index, value);
        }
        else if (op == "delete") {
            string index; int value;
            cin >> index >> value;
            database.del(index, value);
        }
        else if (op == "find") {
            string index;
            cin >> index;
            auto v = database.find_with_vector(index);
            if (v.size() == 0) cout << "null\n";
            else {
                for (auto x : v) cout << x << ' ';
                cout << '\n';
            }
        }
        // cerr << "opt done\n" << endl;
    }
}