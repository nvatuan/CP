/*
ID: nvatuan2
TASK: transform 
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rot(vector<vector<char>> S, int apply = 1) {
    int e = S.size();
    vector<vector<char>> T (e, vector<char> (e, 0));

    while (apply > 0) {
        apply--;
        for (int i=0; i<e; i++) {
            for (int j=0; j<e; j++) {
                T[j][e-i-1] = S[i][j];
            }
        }
        swap(S, T);
    }
    return S;
}
vector<vector<char>> horReflc(vector<vector<char>> S) {
    int e = S.size();
    vector<vector<char>> T (e, vector<char> (e, 0));
    for (int i=0; i<e; i++) {
        for (int j=0; j<e; j++) {
            T[i][e-j-1] = S[i][j];
        }
    }
    return T;
}

enum TRANSFORM {
    ROT_90=1, ROT_180, ROT_270, REFLC, COMBI, NO_CHANGE, INVALID
};

void p(vector<vector<char>> M) {
    for (auto v : M) {
        for (auto i : v) cout << i;
        cout << endl;
    }
}

int main() {
    #ifndef LOCAL
        freopen("transform.in", "r", stdin);
        freopen("transform.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<vector<char>> S (n, vector<char>(n, 0));
    vector<vector<char>> T = S;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> S[i][j];
        }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> T[i][j];
        }
    
    if (rot(S, 1) == T) cout << ROT_90 << endl;
    else if (rot(S, 2) == T) cout << ROT_180 << endl;
    else if (rot(S, 3) == T) cout << ROT_270 << endl;
    else {
        auto rS = horReflc(S);
        if (rS == T) {
            cout << REFLC << endl;
        } else {
            for (int r=1; r<=3; r++) {
                if (rot(rS, r) == T) {
                    cout << COMBI << endl;
                    return 0;
                }
            }
            if (S == T) {
                cout << NO_CHANGE << endl;
            } else {
                cout << INVALID << endl;
            }
        }
    }
}