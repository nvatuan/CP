#include <bits/stdc++.h>
using namespace std;

const int M = (int(1e9) + 7);

int N;
vector<int> X;

long long fact[100001];
void _fact() {
    fact[0] = 1;
    for(int i = 1; i < 100000; i++) fact[i] = (i * fact[i-1]) % M;
}

long long form() {
    long long sigma = (X[N] - X[1]);
    long long ans = fact[N-1]*sigma;
    for(int i = 2; i < N; i++) {
        for(int j = 1; j < i; j++ ) {
            ans = (ans + fact[N-2]*(X[i] - X[j]) ) % M;
        }
    }
    return ans;
}

int main() {
    try {
        _fact();
        X.resize(N+2, 0);
        //
        cin >> N;
        for(int x, i = 1; i <= N; i++) {
            cin >> x;
            X[i] = x;
        }
        // sort(X.begin(), X.end());
        //
        cout << form() << endl;
        return 0;
    } catch(...) {
        cout << "Catched!";
    }
}