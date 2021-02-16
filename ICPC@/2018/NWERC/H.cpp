#include <bits/stdc++.h>
using namespace std;

int n, c, b;
int z[int(5e5) + 10];

int main() {
    cin >> n >> c >> b;
    string st (n, '0');
    for (int i=0; i<b; i++) { int no; cin >> no; z[no-1] = 1; }

    int ptr = 1;
    if (c & 1) {
        st[0] = '1';
        c--;
        ptr++;
    }

    while (ptr < n and c > 0) {
        if ( z[ptr] ) ptr++;
        else {
            c -= 2;
            st[ptr] = '1';
            ptr += 2;
        }
    }
    cout << st << '\n';
    
}