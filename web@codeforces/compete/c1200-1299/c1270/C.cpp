#include <bits/stdc++.h>
using namespace std;

long long SUM;
long long XOR;

int n;
long long a[100001];

void solve() {
    // cerr << "SUM " << SUM << endl << "xor " << XOR << endl;

    printf("1\n");
    long long num = 0;

    long long curransbit = 0;
    long long borrowbit  = 0;
    //
    const long long BITS = 69;    // i meant 64
    for(long long b = 0; b < BITS; b++) {
        for(long long bit = 0; bit <= 1; bit++) {
            if( curransbit == (((SUM >> b) & 1LL) ^ bit ^ borrowbit) ) {
                num         = (num | (bit << b));
                borrowbit   = (( (((SUM >> b) & 1LL)) + bit + borrowbit) > 2);
                break;
            }
        }
        // -- update new ans bit
        curransbit = ((XOR >> b) & 1LL) ^ ((num >> b) & 1LL);
        // cerr << ((num >> b) & 1LL) << " " << curransbit << endl;
    }
    //
    // cerr << endl;
    cout << num << "\n";
}

int main() {
    int t;
    for(cin >> t; t; t--) {
        SUM = XOR  = 0;
        // --
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            SUM += a[i];
            XOR ^= a[i];
        }
        // --
        if(SUM == 2*XOR) {
            printf("0\n\n");
        } else {
            solve();
        }
    }
}