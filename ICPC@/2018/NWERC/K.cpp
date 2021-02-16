#include <bits/stdc++.h>
using namespace std;

int n, m;

int plain[1000], cypher[1000], key[1000];

char to_char(int x) {
    return (char) (x + 'a');
}
int to_int(char c) {
    return (int) (c - 'a');
}

int inv(int cy, int pl) {
    return (cy - pl + 26) % 26;
}

int main() {
    cin >> n >> m;
    for (int i=m-n; i<m; i++) {
        char c; cin >> c;
        plain[i] = to_int(c);
    }
    for (int i=0; i<m; i++) {
        char c; cin >> c;
        cypher[i] = to_int(c);
    }
    int R = m-1, L = m-n-1;
    while (0 <= L) {
        plain[L] = inv(cypher[R], plain[R]);
        //printf("Cy=%c Pl=%c => %c\n", to_char(cypher[R]), to_char(plain[R]), to_char(plain[L]));
        key[L] = plain[L];
        L--;
        R--;
    }
    for (int i=0; i<m; i++) {
        cout << to_char(plain[i]);
    }
    cout << '\n';
}