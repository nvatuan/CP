#include <bits/stdc++.h> 

int data[5 * int(1e5) + 10];
void update(int x, int d) {
    for ( ; x < 5 * int(1e5) + 10; x += (x & (-x)) ) data[x] += d;
}
int sum(int x) {
    int result = 0;
    for ( ; 0 < x; x -= (x & (-x)) ) result += data[x];
    return result;
}
int rangesum(int l, int r) { // [l, r]
    return sum(r) - sum(l-1);
}

using namespace std;

int N, nQ;
vector<int> Query[5 * int(1e5) + 10], Qid[5 * int(1e5) + 10];
vector<int> c;

void solve() {
    cin >> N >> nQ;
    c.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> c[i];

    for (int i = 1; i <= nQ; i++) {
        int l, r;
        cin >> l >> r;
        Query[l].push_back(r);
        Qid[l].push_back(i - 1);
    }

    vector<int> lastSeen (5 * int(1e5) + 10, 0);
    vector<int> answer (nQ);
    for (int L = N; L > 0; L--) {
        if (lastSeen[c[L]] == 0); 
        else update(lastSeen[c[L]], -1);
        
        lastSeen[c[L]] = L;
        update(L, 1);

        for (int iq = 0; iq < (int) Query[L].size(); iq++) {
            answer[Qid[L][iq]] = rangesum(L, Query[L][iq]);
        }
    }

    for (int a : answer) {
        cout << a << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
}