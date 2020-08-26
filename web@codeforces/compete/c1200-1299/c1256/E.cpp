#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[100000];

int main() {
    cin >> n;
    for(int v, i = 0; i < n; i++) {
        cin >> v;
        a[i] = {v, i};
    }
    sort(a, a+n);
    //

}