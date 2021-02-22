#include <bits/stdc++.h>
using namespace std;

const int N = 150;
int x[N], y[N];

int n;

int sqr(int x) { return x*x; }
const int EPS = 10e-9;

int check(double d) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])) - d < EPS) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin>>x[i]>>y[i];
    
    double L = 0, R = 100.0;
}