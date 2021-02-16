#include <bits/stdc++.h>
using namespace std;

int n;
const int N = (int) (4e5) + 10;
int e[N];
vector<int> d[N], dr[N];
map<int, int> depend_count;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> e[i];
        int dsize;
        cin >> dsize;
        d[i].resize(dsize);
        for (int & j : d[i]) {
            cin >> j;
            j--;
        }
        for (int & j : d[i]) {
            dr[j].push_back(i);
        }
        depend_count[i] = dr[i].size();
    }

    // priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i=0; i<n; i++) 
        if (dr[i].size() == 0) pq.push({e[i], i});
    

    vector<int> job;
    while (not pq.empty()) {
        int ind = pq.top().second;
        int dur = pq.top().first;
        pq.pop();

        job.push_back(ind);
        for (int prev_job : d[ind]) {
            depend_count[prev_job]--;
            if (depend_count[prev_job] == 0) 
                pq.push({e[prev_job], prev_job});
        }
    }
    reverse(job.begin(), job.end());

    for (int j : job) cout << j << ' '; cout << endl;

    long long t = 0, ans = 0;
    for (int j : job) {
        ans = max(ans, e[j] + t);
        t++;
    }
    cout << ans << '\n';
}