#include <bits/stdc++.h>
using namespace std;

const int __debug_mode = 1;
const int __multitest = 0;
#define db if(__debug_mode)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- template ends here
class Station {
public:
    int x;
    int a;
    int b;
    Station() {}
    Station(int xx, int aa, int bb) : x(xx), a(aa), b(bb) {}
    //
    bool operator<(Station o) {
        if (this->x != o.x) return this->x < o.x;
        else {
            return false;
        }
    }
    //
    void p() {
        cout << x << " " << a << " " << b << endl;
    }
};

int n, d;
vector<Station> v;

void possible(int f) {
    int x = 0;
    int f_no = f;
    int f_yes = f;
    //
    for (Station s : v) {
        f_no -= (s.x - x); 
        f_yes -= (s.x - x);
        x = s.x;
        //
        int ff_yes = 0;
        if (f_no <= s.b) ff_yes = max(ff_yes, f_no + s.a);
        if (f_yes <= s.b) ff_yes = max(ff_yes, f_yes + s.a);
        int ff_no = max(f_yes, f_no);
    }
}

void solve() {
    cin >> n >> d;
    v = vector<Station> (n);
    //
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].a >> v[i].b;
    }
    //
    std::sort(v.begin(), v.end());
    //
    int L = 0, R = MAX_INT;
    while (L < R) {
        int f = (L + R + 1)/2;
        if (possible(f)) L = f;
        else R = f - 1;
    }
}

int main() {
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}

