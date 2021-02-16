#include <bits/stdc++.h>
using namespace std;


int n;

void solve() {
    cin >> n;

    int brute_ans = 0;
    for (int a=1; a<=n; a++)
        for (int b=a+1; b<=n; b++)
            for (int c=b+1; c<=n; c++)
                brute_ans += (a*a + b*b == c*c);

    cerr << brute_ans << endl;


}

int main() {
    vector<long long> cs;
    for (long long a=1; a*a <= (long long)(2e9); a++) {
        if ((a*a - 1) % 2 == 0) {
            long long b = (a*a - 1)/2;
            long long c = (a*a - b);
            if (1 <= a && a <= b && b <= c) {
                cs.push_back(c);
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        //cerr << "*" << *upper_bound(cs.begin(), cs.end(), n) << '\n';;
        int u = upper_bound(cs.begin(), cs.end(), n) - cs.begin();
        cout << u << endl;
    }
}