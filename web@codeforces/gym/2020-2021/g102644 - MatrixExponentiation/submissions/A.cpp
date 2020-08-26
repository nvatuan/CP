#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double p;
    scanf("%d %lf", &n, &p);

    double happy = 1;
    while (n) {
        if (n & 1) {
            happy = happy * (1 - p) + (1 - happy) * p;
        }
        p = p * (1 - p) * 2;
        n /= 2;
    }

    cout << setprecision(9) << fixed << happy << '\n';
}