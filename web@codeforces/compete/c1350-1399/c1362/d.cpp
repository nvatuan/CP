#include <bits/stdc++.h>
using namespace std;

const int __multitest = 1;
const int __debugmode = 0;

template<typename T>
T In() { T x; cin >> x; return x; }
// --
int n, m;
vector<vector<int>> edge_list;
vector< pair<int, int> > desired;

vector< int > topic;

void solve() {
    cin >> n >> m;
    edge_list.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge_list[a].push_back(b);
        edge_list[b].push_back(a);
    }
    // 
    desired.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> desired[i].first;
        desired[i].first--;
        desired[i].second = i;
    }
    // --
    topic.resize(n, -1);

    std::sort(desired.begin(), desired.end());

    bool possible = true;
    for (int i = 0; i < n; i++) {
        //
        int least;
        vector<int> written;
        //
        for (const int& blog : edge_list[desired[i].second]) {
            if (topic[blog] == -1) continue;
            written.push_back(topic[blog]);
        }
        //
        std::sort(written.begin(), written.end());
        written.erase(std::unique(written.begin(), written.end()), written.end());
        least = 0;
        int ptr = 0; 
        while (ptr < written.size() && written[ptr] == least) {
            ptr++;
            least++;
        }
        //
        topic[desired[i].second] = least;
        if (topic[desired[i].second] != desired[i].first) possible = false;
        // ----
        if (possible == false) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << desired[i].second + 1 << " ";
    }
    cout << endl;
}

int main() {
    for (int t = (__multitest ? 1 : In<int>()); t; t--) solve();
}