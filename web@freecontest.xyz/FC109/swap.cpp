#include <bits/stdc++.h>
using namespace std;

int N, Q;
long long A[100001];
long long F[100002];

long long Sum(int x) {
    long long value = 0;
    while(x > 0) {
        value += F[x];
        x -= (x&-x);
    }
    return value;
}
long long Sum(int l, int r) {
    return Sum(r) - Sum(l-1);
}

void Update(int x, int add) {
    while(x <= N) {
        F[x] += add;
        x += (x&-x);
    }
}

void Swap(int x, int y) {
    int v1 = A[x], v2 = A[y];
    swap(A[x], A[y]);
    // --
    Update(x, (v2 - v1));
    Update(y, (v1 - v2));
}

int main() {
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        Update(i, A[i]);
    }
    for(int k, u, v; Q; Q--) {
        cin >> k >> u >> v;
        if(k == 0) {
            Swap(u, v);
        } else {
            printf("%lld\n", Sum(u, v));
        }
    }
}