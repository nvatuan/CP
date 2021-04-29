#include <bits/stdc++.h>
using namespace std;

int n;
const int N = (int)(2e5)+10;
int incPre[N], decPost[N];
int a[N];

int calc(int idx) {
    if ( incPre[idx] == decPost[idx] )  return incPre[idx];
    else return 0; 
}

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        incPre[i] = 1;
        decPost[i] = 1;
    }
    for (int i=1; i<n; i++) {
        if (a[i-1] < a[i]) incPre[i] = incPre[i-1] + 1;
    } 
    for (int i=n-1; i>=1; i--) {
        if (a[i-1] > a[i]) decPost[i-1] = decPost[i] + 1;
    } 

    // fprintf(stderr, "incrs: ");
    // for (int i=0; i<n; i++) {
    //     fprintf(stderr, "%d ", incPre[i]);
    // }
    // fprintf(stderr, "\ndecs: ");
    // for (int i=0; i<n; i++) {
    //     fprintf(stderr, "%d ", decPost[i]);
    // }
    // fprintf(stderr, "\n");

    int cnt=0;
    int d = 0;
    int idx=-1;

    for (int i=1; i<n-1; i++) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            if (incPre[i] == decPost[i]) {
                if (d < incPre[i]) {
                    d = incPre[i];
                    idx = i;
                } 
            }
        }
    }

    int good = (idx != -1);
    // fprintf(stderr, "d=%d\n", d);
    for (int i=0; i<n; i++) {
        // fprintf(stderr, "i=%d, good=%d\n", i, good);
        if (i == idx) continue;
        if (decPost[i] >= d)
            if (i + decPost[i] >= idx-d) {
                if ((idx - i) % 2 == 1) good = 0;
            } else good = 0;
        if (incPre[i] >= d) 
            if (i - incPre[i] <= idx-d) {
                if ((i - idx) % 2 == 1) good = 0;
            } else good = 0;
    }

    cout << (good ? 1 : 0) << endl;
}

int main() {
    solve();
}