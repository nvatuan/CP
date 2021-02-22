#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    // --
    int seg = 0;
    int loop = 0;
    vector<int> AtStep (2*n, 1);
    vector<int> Reach (n, -1);
    //
    Reach[0] = 0;
    AtStep[0] = 0;
    for (int city = 0, step = 1; step <= 2*n; step++) {
        if (Reach[a[city]] != -1) {
            loop = step - Reach[a[city]];
            seg = Reach[a[city]];
            break;
        }
        //
        city = a[city];
        Reach[city] = step;
        AtStep[step] = city;
    }
    //
    //cout << seg << " " << loop << endl;
    //
    if (k < seg) {
        cout << AtStep[k]+1 << endl;
    } else {
        k = k - seg;
        k %= loop;
        int city = AtStep[seg];
        //cout << "At Start of Loop" << AtStep[seg] << endl;
        while (k > 0) {
            k--;
            city = a[city];
        }
        cout << city+1 << endl;
    }
}