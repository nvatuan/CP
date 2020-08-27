#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
vector<int> rope;

long long count_cut_rope(int leng) {
    long long cnt = 0;
    for (int d : rope) {
        int q = d/leng;
        cnt += q;
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    rope.resize(n);

    double tmp;
    for (int &i : rope) {
        cin >> tmp;
        tmp += 0.001;
        tmp *= 100;
        i = ((int) tmp);
    }

    
    int L = 0;
    int R = rope[0];
    for (int& d : rope) { R = max(R, d); }

    while (R > L) {
        int mid = (R + L + 1) / 2;
        //cerr << mid << " " << count_cut_rope(mid) << endl;
        if (count_cut_rope(mid) >= k) L = mid;
        else R = mid - 1;
        // cout << L << " " << R << endl;
    }

    // cout << L << endl;
    // cout << R << endl;

    printf("%.2lf\n", ((double) L)/100);
}