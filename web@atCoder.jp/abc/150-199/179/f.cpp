#include <bits/stdc++.h>
using namespace std;

int N, Q;
int qtype, qx;

int H, V;
vector<int> Vs, Hs;
unordered_map<int, int> Vx, Hx;
long long ans = 0;

void topdown(int v){
    if (V < s.back()) {
        ans += (N-1);
        s.back() = v;
    } else {

    }
}

void leftright(int v){}

int main() {
    cin >> N >> Q;
    H = N-1; Hs.push_back(H);
    V = N-1; Vs.push_back(V);

    while (Q--) {
        scanf("%d%d", &qtype, &qx);
        if (qtype == 1) topdown(qx);
        else leftright(qx);
    }
}