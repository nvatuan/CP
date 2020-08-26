#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edge;

int furthest = 0;
int dist = 0;

void furthestNode(int x, int d = 0, int p = -1) {
    if (d > dist) {
        dist = d;
        furthest = x;
    }
    for (int& nextNode : edge[x]) {
        if (nextNode != p) {
            furthestNode(nextNode, d+1, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n;
    edge = vector<vector<int>> (n, vector<int>());
    for (int a, b, i = 0; i < n-1; i++) {
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }

    furthestNode(0);
    dist = 0;
    furthestNode(furthest);
    cout << dist * 3 << '\n';
}