#include <bits/stdc++.h>
using namespace std;

unordered_set<long long> fibo;
const long long THRESHOLD = (long long)(1e11);

string[] keypad = {
    "ABC", "DEF", "GHI", "JKL", "MNO", ""
};

void solve() {
    long long f1=0, f2=1;
    while (f2 < THRESHOLD) {
        long long tmp = f1 + f2;
        fibo.insert(tmp);
        f1 = f2; f2 = tmp;
    }

}

int main() {
    solve();
}