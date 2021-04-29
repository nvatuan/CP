#include <bits/stdc++.h>
using namespace std;

int n;
int q;
int t, a, b;

int flip;
string s;

int conv(int x) {
    if (x < n) {
        if (flip) return x + n;
        else return x;
    } else {
        if (flip) return x - n;
        else return x;
    }
}

void swap(int a, int b) {
    int va = conv(a);
    int vb = conv(b);  

    swap(s[va], s[vb]);
}

void doFlip() {
    flip^=1;
}

int main() {
    cin >> n;
    cin >> s;
    cin >> q;
    while (q--) {
        cin >> t >> a >> b;
        t--;
        if (t) doFlip();
        else swap(a-1, b-1);
    }
    for (int i=0; i<2*n; i++) {
        cout << s[conv(i)];
    }
    cout << endl;
}
