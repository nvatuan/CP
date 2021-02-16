#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[(int)(3e5) + 50];
int b[(int)(3e5) + 50]; 

struct App {
    int mem;
    int conv;
    App (int m, int c) {
        mem = m; conv = c;
    }
    bool operator<(const App& app) const{
        return this->mem < app.mem;
    }
};

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> cn1, cn2;
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == 1) cn1.push_back(a[i]);
        else cn2.push_back(a[i]);
    }

    sort(cn1.begin(), cn1.end(), greater<int>());
    sort(cn2.begin(), cn2.end(), greater<int>());

    long long curr_conv_loss = 0;
    int idx1=0, idx2=0;

    long long curr_mem = 0;
    for (; idx1 < (int)(cn1.size()); ) {
        curr_mem += cn1[idx1];
        curr_conv_loss += 1;
        idx1++;
        if (curr_mem >= m) break;
    }
    idx1--;

    if (curr_mem < m)
        for (; idx2 < (int)(cn2.size());) {
            curr_mem += cn2[idx2];
            curr_conv_loss += 2;
            idx2++;
            if (curr_mem >= m) break;
        }

    if (curr_mem < m) {
        cout << -1 << endl;
        return;
    }

    while (idx1 >= 0 && curr_mem - cn1[idx1] >= m) {
        curr_mem -= cn1[idx1--];
        curr_conv_loss -= 1;
    }
    long long best_conv_loss = curr_conv_loss;

    while (true) {
        if (idx2 < (int)(cn2.size())) {
            curr_conv_loss += 2;
            curr_mem += cn2[idx2++];
        }
        while (idx1 >= 0 && curr_mem - cn1[idx1] >= m) {
            curr_mem -= cn1[idx1--];
            curr_conv_loss -= 1;
        }
        best_conv_loss = min(curr_conv_loss, best_conv_loss);
        if (idx1 < 0) break;
        if (idx2 == (int)(cn2.size())) break;

    }
    cout << best_conv_loss << endl;

}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}