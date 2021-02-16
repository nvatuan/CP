#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;

void solve() {
    cin >> n;
    p = vector<int> (n+1, 0);

    int qries = 0;
    int p1 = 0, p2 = 1;
    while (p2 < n) {
        cout << "? " << p1+1 << " " << p2+1 << endl;
        int q1; cin >> q1;
        cout << "? " << p2+1 << " " << p1+1 << endl;
        int q2; cin >> q2;

        qries += 2;
        assert(qries <= 2*n);

        if (q1 < q2) {
            p[p2] = q2;
            //printf("!! Guess p[%d] = %d\n", p2, q2);
            p2++;
        } else { // q1 > q2
            p[p1] = q1;
            //printf("!! Guess p[%d] = %d\n", p1, q1);
            p1++;
            while (p[p1] != 0) p1++;
            p2 = p1+1;
        }
    }

    set<int> s;
    for (int i=1; i<=n; i++) s.insert(i);
    for (int i=0; i<n; i++) s.erase(p[i]);
    for (int i=0; i<n; i++)
        if (p[i] == 0) {
            p[i] = *s.begin();
            break;
        }
    cout << "! ";
    for (int i=0; i<n; i++) cout << p[i] << " ";
    cout << endl;
}

int main() {
    solve();
}