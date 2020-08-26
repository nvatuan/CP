#include <bits/stdc++.h>
using namespace std;

int n;

long long k[2001];
long long c[2001];

long long E[2001];

int powerBy[2001];

vector<pair<int, int>> pos;

#define x first
#define y second

inline long long conCost(int i, int j) {
    return ((abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y))) * (k[i] + k[j]);
}

void dfs(vector<int> & V, int city, int& minCostCity, long long& minCost) {
    if(city == powerBy[city]) return;
    if(V[city]) {
        E[minCostCity]          = c[minCostCity];
        powerBy[minCostCity]    = minCostCity;
        return;
    }
    V[city] = 1;
    if(minCost > c[city]) {
        minCostCity = city;
        minCost = c[city];
    }
    dfs(V, powerBy[city], minCostCity, minCost);
}

int main() {
    cin >> n;
    pos = vector<pair<int, int>> (n, pair<int, int>());
    for(int i = 0; i < n; i++) cin >> pos[i].x >> pos[i].y;
    for(int i = 0; i < n; i++) {
        cin >> E[i];
        c[i] = E[i];
    }
    for(int i = 0; i < n; i++) cin >> k[i];

    for(int i = 0; i < n; i++) powerBy[i] = i;

    // --
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(i != j) {
                if(conCost(i, j) < E[j]) {
                    if(powerBy[i] == j) {
                        //if(c[i] + c[j] + conCost(i, j);
                    } else {
                        E[j] = conCost(i, j);
                        powerBy[j] = i;   
                    }
                }
            }
    }

// debug
// printf("connect %d\n", conCost(0, 2));
// printf("connect %d\n", conCost(1, 2));

// for(int i = 0; i < n; i++) cout << i << " ";
// cout << endl;
// for(int i = 0; i < n; i++)
//     cout << E[i] << " ";
// cout << endl;
// for(int i = 0; i < n; i++)
//     cout << powerBy[i] << " ";
// cout << endl;

    // -- cycle detection:
    // for(int i = 0; i < n; i++) {
    //     vector<int> visited (n, 0);
    //     int minCostCity = -1;
    //     long long minCost     = INT_MAX;
    //     dfs(visited, i, minCostCity, minCost);
    // }
    // --
    long long ans = 0;
    for(int i = 0; i < n; i++) ans += E[i];
    cout << ans << '\n';
    // --
    vector<int> selfPower;
    for(int i = 0; i < n; i++) {
        if( powerBy[i] == i ) selfPower.push_back(i);
    }
    //
    cout << selfPower.size() << '\n';
    for(int& i : selfPower) cout << i+1 << " ";
    cout << "\n";
    // --
    cout << n - selfPower.size() << '\n';
    for(int i = 0; i < n; i++) {
        if( powerBy[i] != i) {
            cout << i+1 << " " << powerBy[i]+1 << "\n";
        }
    }
    cout << "\n";
}