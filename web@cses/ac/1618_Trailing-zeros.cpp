#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int z = 0;

    while (n > 0) {
        z += (n / 5);
        n /= 5;
    }
    cout << z << endl;
}