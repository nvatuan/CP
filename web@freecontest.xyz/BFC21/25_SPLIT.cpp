#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

int minPrime[1000001];
void minPrimeSieve() {
    for (int i = 0; i < 1000001; i++) minPrime[i] = i;
    minPrime[1] = 1; minPrime[0] = 1;

    for (int p = 2; p < 1000001; p++)
        if (minPrime[p] == p)
            for (long long d = p*2; d < 1000001; d += p)
                minPrime[d] = min(minPrime[d], p);
}

long long _C[1001][1001];
int _Cinit = false;
long long C(int k, int n) {
    if (not _Cinit) {
        _C[0][0] = 1;
        for (int i = 1; i < 1000; i++) {
            _C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                _C[i][j] = _C[i-1][j-1] + _C[i-1][j];
                if (_C[i][j] >= MOD) _C[i][j] -= MOD;
            }
        }
        _Cinit = true;
    }
    return _C[n][k];
}

// -- dsu
vector<int> Root;
vector<int> Size;
unordered_map<int, int> primeToDSU;

int getRoot(int x) {
    while (x != Root[x]) {
        Root[x] = Root[Root[x]];
        x = Root[x];
    }
    return x;
}

void Union(int a, int b) {
    int ra = getRoot(a);
    int rb = getRoot(b);
    
    if (ra == rb) return;
    if (Size[ra] < Size[rb]) {
        Root[ra] = rb;
        Size[rb] += Size[ra];
    } else {
        Root[rb] = ra;
        Size[ra] += Size[rb];
    }
}


int n;
int cov[1000001];

int ones;
set<int> factors;
unordered_map<int, vector<int>> factorsOf;

void initDSU() {
    Root.resize(factors.size());
    Size.resize(factors.size());
    int i = 0;
    for (const int& f : factors) {
        Size[i] = 1;
        Root[i] = i;
        primeToDSU[f] = i;
        i++;
    }
}

void solve() {
    factorsOf.clear();
    factors.clear();
    primeToDSU.clear();
    ones = 0;

    // -- input
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cov[i];
    
    // -- defactor numbers
    for (int i = 0; i < n; i++) {
        if (cov[i] == 1) {
            ones++; continue;
        }
        int k = cov[i];
        int prevPrime = 0;
        while (k != 1) {
            if (prevPrime != minPrime[k]) {
                prevPrime = minPrime[k];
                factorsOf[cov[i]].push_back(prevPrime);
            }
            k /= minPrime[k];            
        }
    }

    // -- gather distinct factors in the test
    for (const auto& p : factorsOf) 
        for (const int& f : p.second)
            factors.insert(f);
    
    initDSU();
    for (int i = 0; i < n; i++) {
        if (cov[i] == 1) continue;
        const vector<int>& fs = factorsOf[cov[i]];
        for (int a = 0; a < (int) fs.size(); a++)
            for (int b = a + 1; b < (int) fs.size(); b++) {
                Union(primeToDSU[fs[a]], primeToDSU[fs[b]]);
            }
    }

    // answers
    unordered_set<int> roots;
    for (const int& r : Root) roots.insert(getRoot(r));
    int uniqueGroups = ones + roots.size();

    long long ans = 0;
    for (int g = 1; g < uniqueGroups; g++) {
        ans += C(g, uniqueGroups);
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << endl;
    
}

int main() {
    minPrimeSieve();
    
    int t; cin >> t;
    while(t--) solve();
}