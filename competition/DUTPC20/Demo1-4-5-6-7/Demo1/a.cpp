#include <bits/stdc++.h> 
using namespace std;
 
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int __MULTITEST = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// ================================================= SOLUTION =================================================
int n;
string reg;
regex rgx;

void solve() {
    cin >> n;
    cin >> reg;
    //for (char& c : reg) c = tolower(c);

    string formalReg = "";
    for (int ptr = 0; ptr < reg.length();) {
        int ptr2 = reg.find('*', ptr);
        if (ptr2 == string::npos) {
            formalReg += "(" + reg.substr(ptr) + ")";
            break;
        }

        formalReg += ("(" + reg.substr(ptr, ptr2 - ptr) + ")");
        if (formalReg.length() != 0) formalReg += "(.*)";
        ptr = ptr2 + 1;
    }

    rgx = regex(formalReg);

    string s;
    while(n--) {
        cin >> s;
        //for (char& c : s) c = tolower(c);
        cout << (regex_match(s, rgx) ? "YES" : "NO") << '\n';
    }
    
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}