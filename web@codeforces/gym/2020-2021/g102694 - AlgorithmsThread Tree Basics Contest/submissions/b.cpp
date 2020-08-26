#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edge;

int furthestNode;
vector<int> furthestPath;

void furthestTravel(int x, vector<int>& path, int p = -1) {
    path.emplace_back(x);
    for (int& nextNode : edge[x])
        if (nextNode != p) {
            furthestTravel(nextNode, path, x);
        }

    if (path.size() > furthestPath.size()) {
        furthestPath = path;
        furthestNode = x;
    }
    path.pop_back();
}

int ans[300005];
int onDiameter[300005];
void checkDepth(int x, int longestPossibleSubtreeDepth, int d = 1, int p = -1) {
    if (d == longestPossibleSubtreeDepth) {
        ans[x]++;
    }
    for (int& child : edge[x])
        if (child != p and not onDiameter[child])
            checkDepth(child, longestPossibleSubtreeDepth, d+1, x);
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

    vector<int> temp;
    furthestTravel(0, temp);
    furthestPath.clear();
    furthestTravel(furthestNode, temp);


    int dist = furthestPath.size();
    for (int i = 0; i < dist; i++) onDiameter[furthestPath[i]] = true;

    fill(ans, ans + n, dist);
    for (int i = 0; i < dist; i++) {
        int longestPossibleSubtreeDepth = min(i+1, dist - i);
        checkDepth(furthestPath[i], longestPossibleSubtreeDepth);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] - 1 << '\n';
}