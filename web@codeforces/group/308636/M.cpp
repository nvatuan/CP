#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> ig, notig;
map<string, int> Size, AllIgnored;

unordered_map<string, int> parent_done;

int starts_with(string in, string tosearch) {
    if (in.length() < tosearch.length()) return false;
    for (int i=0; i<(int)tosearch.length(); i++) {
        if (tosearch[i] != in[i]) return false;
    }
    return true;
}

void incSize(string path, int isIgnored) {
    Size[path]++;
    if (isIgnored) AllIgnored[path]++;

    int idx = path.length();
    while (true) {
        idx = path.rfind('/', idx);
        if (idx == string::npos) break;

        string ppath = path.substr(0, idx);
        idx = idx-1;
        // cerr << ppath << '\n';

        Size[ppath]++;
        if (isIgnored) AllIgnored[ppath]++;
    }
}

int isParentIgnored(string path) {
    int idx = path.length();
    while (true) {
        idx = path.rfind('/', idx);
        if (idx == string::npos) break;

        string ppath = path.substr(0, idx);
        idx = idx-1;
        // cerr << ppath << '\n';
        
        if (parent_done[ppath]) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    ig.resize(n);
    notig.resize(m);
    Size.clear();
    AllIgnored.clear();
    parent_done.clear();

    for (string& s : ig) cin >> s;
    for (string& s : notig) cin >> s;
    //
    for (string s : ig) {
        incSize(s, 1);
    }
    for (string s : notig) {
        incSize(s, 0);
    }
    for (auto p : Size) {
        const string& dir = p.first;
        const int& sz = p.second;
        
    }
    //

    int ans = 0;
    string prvDir = "?";
    for (auto p : Size) {
        const string& dir = p.first;
        const int& sz = p.second;

        //cerr << dir << ' ' << sz << ' ' << AllIgnored[dir] << '\n';

        if (isParentIgnored(dir)) {
            //cerr << "Is alr done\n";
            continue;
        }

        if (sz == AllIgnored[p.first]) {
            parent_done[dir]++;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    int T; cin >> T;
    while (T--)
        solve();
}