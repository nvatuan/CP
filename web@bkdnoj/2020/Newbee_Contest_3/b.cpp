#include <bits/stdc++.h> 
using namespace std;
 
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int __MULTITEST = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// ================================================= SOLUTION =================================================
int N;
int A[300001];

long long one, two, three;
long long ans = 0;

long long choose_3(long long x) {
    return (x - 2) * (x - 1) * x / 6;
}

long long choose_2(long long x) {
    return x * (x - 1)/2;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    one = two = three = 0;
    for (int i = N-1; i >= 0; i--) {
        one     = one   + (A[i] == 1);
        two     = two   + (A[i] == 2);
        three   = three + (A[i] == 3);
    }

    // a == b == c == 1
    ans = choose_3(one) * 3;
    
    // a != 1, b == c == 1
    //         a == 2
    ans += (choose_2(one) * two) *2;
    //         a > 2
    ans += (choose_2(one) * (N - one - two));

    // a != 1, b != 1, c == 1
    //  a == 2, b == 2
    ans += (one * choose_2(two));
    //  a == 2, b == 3
    ans += (one * two * three);
    
    // other cases = 0
    
    cout << ans << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}