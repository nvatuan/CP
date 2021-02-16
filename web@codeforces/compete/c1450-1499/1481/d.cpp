#include <bits/stdc++.h>
using namespace std;

int n, m;
char to[2000][2000];
int has_a[2000];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        has_a[i] = -1;
        for (int j=0; j<n; j++) {
            cin >> to[i][j];
            if (to[i][j] == 'a') has_a[i] = j;
        }
    }

    int bidirection_pair = 0;
    int bi_i, bi_j;

    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            if (i != j) {
                if (to[i][j] == to[j][i]) {
                    bidirection_pair = 1;
                    bi_i = i; bi_j = j;
                }
            }
    
    if (bidirection_pair) {
        cout << "YES\n";
        cout << bi_i+1;
        for (int i=0; i<m; i++) {
            cout << ' ' << bi_j+1;
            swap(bi_i, bi_j);
        }
        cout << endl;
    } else {
        if (m % 2 == 1) {
            cout << "YES\n";
            cout << 1;
            for (int i=0; i<m; i++) {
                cout << ' ' << (i&1 ? 1 : 2);
            }
            cout << endl;
        } else {
            int v[3];
            int pos = 0;
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++) 
                    if (i != j) {
                        if (to[i][j] == 'a' and has_a[j] != -1) {
                            v[0] = i+1; v[1] = j+1; v[2] = has_a[j]+1;
                            pos = 1;
                            break;
                        }
                    }
            cout << (pos ? "YES" : "NO") << endl;
            if (pos) {
                vector<int> left, right;
                int l = 0, r = 2;
                for (; m > 0; m -= 2) {
                    left.push_back(v[l]); right.push_back(v[r]);
                    l = (l == 0 ? 2 : l-1);
                    r = (r == 2 ? 0 : r+1);
                }
                reverse(left.begin(), left.end());
                for (int i:left) cout << i << ' ';
                cout << v[1];
                for (int i:right) cout << ' ' << i;
                cout << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}