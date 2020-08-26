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
        Book () {}
        Book (int tt, int aa, int bb) : t (tt), a (aa), b (bb) {}
        //
        bool operator<(Book o) {
            return this->t < o.t;
        }
        bool likeddByBoth() { return this->a and this->b; }
        bool likedByAlice() { return this->a and not this->b; }
        bool likedByBob()   { return not this->a and this->b; }
};

vector<Book> v, AliceLikes, BobLikes, BothLike;

void solve() {
    int n, k;
    cin >> n >> k;
    v = vector<Book>(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].t >> v[i].a >> v[i].b;
        if (v[i].a and v[i].b) BothLike.push_back(v[i]);
        else {
            if (v[i].a) AliceLikes.push_back(v[i]);
            if (v[i].b) BobLikes.push_back(v[i]);
        }
    }
    sort(AliceLikes.begin(), AliceLikes.end());
    sort(BobLikes.begin(), BobLikes.end());

    for (int i = 0; i < min(AliceLikes.size(), BobLikes.size()); i++) {
        BothLike.push_back(
            Book( AliceLikes[i].t + BobLikes[i].t, 1, 1)
        );
    }

    if (BothLike.size() < k) {
        cout << -1 << endl;
        return;
    }

    sort(BothLike.begin(), BothLike.end());
    long long totalTime = 0;
    for (int i = 0; i < k; i++) totalTime += BothLike[i].t;
    cout << totalTime << endl;
}


int main() {
    for (int t = (_MULTITEST ? In<int>() : 1); t; t--) solve();
}