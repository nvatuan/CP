#pragma exception_handler
/*
ID: nvatuan2
TASK: namenum 
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

set<string> mark;
void loadData() {
    ifstream fin ("dict.txt", std::ifstream::in);
    string name;
    mark.clear();
    while (fin >> name) {
        mark.insert(name);
    }
    fin.close();
}

map<char, vector<char>> m {
    {'2', {'A', 'B', 'C'}},
    {'3', {'D', 'E', 'F'}},
    {'4', {'G', 'H', 'I'}},
    {'5', {'J', 'K', 'L'}},
    {'6', {'M', 'N', 'O'}},
    {'7', {'P', 'R', 'S'}},
    {'8', {'T', 'U', 'V'}},
    {'9', {'W', 'X', 'Y'}}
};

void generate(string& id, vector<string>& names, string& name, int len=0) {
    int line = 0;
    try {
        if (len == id.length()) { line++;
            if (mark.find(name) != mark.end()) { line++;
                names.emplace_back(name); line++;
            } line++;
        } else {
            for (char chr : m[id[len]]) {
                string new_name = name + chr;
                generate(id, names, new_name, len+1);
            }
        }
    } catch (const std::exception &exc) {
        cerr << exc.what() << endl;
        cerr << "DEPTH " << len << endl;
        cerr << "vec SIZE " << names.size() << endl;
        cerr << "Exception thrown at line#" << line << endl;
        throw;
    }
}

int main() {
    #ifndef LOCAL
        freopen("namenum" ".in", "r", stdin);
        freopen("namenum" ".out", "w", stdout);
    #endif

    loadData();
    cerr << "Load ok\n";
    string id;
    cin >> id;
    vector<string> names;

    string nm = "";
    generate(id, names, nm);
    cerr << "Generate ok\n";

    sort(names.begin(), names.end());
    cerr << "Sort ok\n";

    for (string s : names) cout << s << endl;
    if (names.size() == 0) {
        cout << "NONE" << endl;
    }
    cerr << "output ok\n";
}