#include <bits/stdc++.h>
using namespace std;

const int N = (int)(3e5) + 10;

vector<int> adj[N];
int n;
int h[N];

void make_graph() {
	deque<int> stac;
	for (int i=0; i<n; i++) {
		if (stac.empty()) stac.push_back(i);
		else {
			while (not stac.empty() and h[stac.back()] <= h[i]) {
				adj[stac.back()].push_back(i);
				stac.pop_back();
			}
			stac.push_back(i);
		}
	}
}

void solve() {
	cin >> n;
	for(int i=0; i<n; i++) cin>>h[i];
	//
	make_graph();
	for (int i=0; i<n; i++) h[i] *= -1;
	make_graph();
	for (int i=0; i<n-1; i++) adj[i].push_back(i+1);
	//
	queue<pair<int, int>> q;
	set<int> seen;
	q.push({0, 0});

	while (not q.empty()) {
		int curr = q.front().first;
		int cost = q.front().second;
		//printf("%d %d\n", curr, cost);
		q.pop();

		if (curr == n-1) {
			cout << cost << "\n";
			return;
		}

		for (int nxt : adj[curr])
			if (seen.find(nxt) == seen.end()) {
				q.push({nxt, cost+1});
				seen.insert(nxt);
			}
	}

}

int main() {
        solve();
}
