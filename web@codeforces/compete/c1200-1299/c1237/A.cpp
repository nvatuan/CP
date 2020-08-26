#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v (n);
    for(int &i : v) cin >> i;
    //
    vector<int> mark(n, 0);
    vector<int> neg (n, 0);
    for(int i = 0; i < n; i++) {
        neg[i] = (v[i] < 0);
        if( v[i] % 2 == 0 ) {
            v[i] /= 2;
            mark[i] = 1;
        } else {
            v[i] /= 2;
        }
    }
    //
    int sum = 0;
    for(int &i : v) sum += i;
    //
    for(int i = 0; i < n; i++) {
        if( !mark[i] ) {
            if(sum > 0 && neg[i]) {
                v[i]--;
                sum--;
            }
            if(sum < 0 && !neg[i]) {
                v[i]++;
                sum++;
            }

        }
    }
    //
    for(int &i : v) cout << i << endl;
}
