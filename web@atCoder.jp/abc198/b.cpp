#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N > 0 and N % 10 == 0) N /= 10;

    string repr;
    while (N > 0) {
        repr += (char)(N%10 + '0');
        N /= 10;
    }

    string rrepr = repr;
    reverse(rrepr.begin(), rrepr.end());
    if (rrepr == repr) {
        cout  << "Yes" << endl;
    } else {
        cout  << "No" << endl;
    }
}
