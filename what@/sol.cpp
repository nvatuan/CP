#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 1;
    for (; x != 1000000; x++) {
        next_permutation(a.begin(), a.end());
    }
    for (int i : a) cout << i;
}