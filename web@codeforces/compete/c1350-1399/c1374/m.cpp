#include <bits/stdc++.h>
using namespace std;

const int _MULTITEST = 0;
const int _DEBUGMODE = 0;
#define db if (_DEBUGMODE)

template <typename T>
T In() { T x; cin >> x; return x; }
// -------------- template ends here
class Book {
    public:
        int t, a, b;
        int ia = -1, ib = -1, i2 = -1;
        Book () {}
        Book (int tt, int aa, int bb) : t (tt), a (aa), b (bb) {}
        Book (int tt, int aa, int bb, int iia, int iib, int ii2) : t (tt), a (aa), b (bb), ia (iia), ib (iib), i2 (ii2) {}
        //
        bool operator<(Book o) {
            return this->t < o.t;
        }

        int getIndex() {
            if (i2 != -1) return i2;
            if (ia != -1) return ia;
            if (ib != -1) return ib;
        }
        
        bool likedByBoth() { return this->a and this->b; }
        bool likedByAlice() { return this->a and not this->b; }
        bool likedByBob()   { return not this->a and this->b; }
};

vector<Book> v, AliceLikes, BobLikes, BothLike;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    v = vector<Book>(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].t >> v[i].a >> v[i].b;

        if (v[i].a and v[i].b) {
            v[i].i2 = i;
            BothLike.push_back(v[i]);
        } else {
            if (v[i].a) {
                v[i].ia = i;
                AliceLikes.push_back(v[i]);
            }
            if (v[i].b) {
                v[i].ib = i;
                BobLikes.push_back(v[i]);
            }
        }
    }
    sort(AliceLikes.begin(), AliceLikes.end());
    sort(BobLikes.begin(), BobLikes.end());

    for (int i = 0; i < min(AliceLikes.size(), BobLikes.size()); i++) {
        BothLike.push_back(
            Book( AliceLikes[i].t + BobLikes[i].t, 0, 0, AliceLikes[i].ia, BobLikes[i].ib, -1)
        );
    }

    if (BothLike.size() < k) {
        cout << -1 << endl;
        return;
    }

    set<int> chosen;

    sort(BothLike.begin(), BothLike.end());
    long long totalTime = 0;
    for (int i = 0; i < k; i++) {
        totalTime += BothLike[i].t;
        if (BothLike[i].likedByBoth()) {
            chosen.insert(BothLike[i].i2);
            m--;
        } else {
            chosen.insert(BothLike[i].ia);
            chosen.insert(BothLike[i].ib);
            m -= 2;
        }
    }

    // --
    sort(v.begin(), v.end());
    int p = 0;
    while (m > 0) {
        if (p == v.size()) {
            cout << "-1\n"; return;
        } else {
            if (chosen.find(v[p].getIndex()) != chosen.end()) p++;
            else {
                totalTime += v[p].t;
                chosen.insert(v[p].getIndex());
                m--;
                p++;
            }
        }
    }

    cout << totalTime << endl;
    for (const int& i : chosen) cout << i << " ";
    cout << endl;
}


int main() {
    for (int t = (_MULTITEST ? In<int>() : 1); t; t--) solve();
}