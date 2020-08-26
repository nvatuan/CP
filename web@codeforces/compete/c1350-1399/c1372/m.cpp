#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 0;

template<typename T>
T In() { T x; cin >> x; return x; }
// --
typedef long long llong;

llong n;
llong a[200001];

bool pointerInit;

int disposed[200001];
int ptrRight[200001], ptrLeft[200001];
void initPointer() {
    if (not pointerInit) {
        for (int i = 0; i < n; i++) {
            ptrRight[i] = (i + 1 == n ? 0 : i + 1);
            ptrLeft[i] = (i == 0 ? n-1 : i-1);
        }        
        pointerInit = true;
    }
}

int getLeft(int i) {
    initPointer();

    int orig = i;
    stack<int> log;

    i = ptrLeft[i];
    while (disposed[i]) {
        log.push(i);
        i = ptrLeft[i];
    }
    
    ptrLeft[orig] = i;
    while (not log.empty()) {
        ptrLeft[log.top()] = i;
        log.pop();
    }

    return ptrLeft[orig];
}
int getRight(int i) {
    initPointer();

    int orig = i;
    stack<int> log;

    i = ptrRight[i];
    while (disposed[i]) {
        log.push(i);
        i = ptrRight[i];
    }

    ptrRight[orig] = i;
    while (not log.empty()) {
        ptrRight[log.top()] = i;
        log.pop();
    }

    return ptrRight[orig];
}

class AdjaSum {
    public:
        llong value;
        int i1, i2;

        AdjaSum() {}
        AdjaSum(llong v, int ii1, int ii2) : value(v), i1(ii1), i2(ii2) {}
        AdjaSum(const AdjaSum& o) {
            this->value = o.value;
            this->i1 = o.i1;
            this->i2 = o.i2;
        }
};

struct AdjaSumCmp {
    bool operator()(const AdjaSum& o1, const AdjaSum& o2) const {
        return o1.value > o2.value;
    }
};

multiset<AdjaSum, AdjaSumCmp> bags;

class Elem {
    public:
        llong value;
        int i;

        Elem() {}
        Elem(llong v, int ind) : value(v), i(ind) {}
};

struct ElemCmp {
    bool operator()(const Elem& o1, const Elem& o2) const {
        return o1.value < o2.value;
    }
};

multiset<Elem, ElemCmp> elems;

void solve() {
    // reset
    bags.clear();
    pointerInit = false;
    fill(disposed, disposed + n, 0);

    // input
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Elem e = Elem(a[i], i);
        elems.insert(e);
    }
    
    // process
    for (int i = 0; i < n; i++) {
        AdjaSum obj;
        obj.value = (i + 1 == n ? a[0] + a[i] : a[i] + a[i+1]);
        obj.i1 = i;
        obj.i2 = (i + 1 == n ? 0 : i + 1);

        bags.insert(obj);
    }

    while (bags.size() > 1) {
        AdjaSum adja = AdjaSum(*bags.begin());
        bags.erase(bags.begin());

        // remove adja pair
        disposed[adja.i1] = disposed[adja.i2] = true;

        // update sum
        int indL = getLeft(adja.i1);
        int indR = getRight(adja.i2);

        bags.insert(AdjaSum(a[indL] + a[indR], indL, indR));

        // replacing..
        Elem repl = Elem(*elems.begin());
        elems.erase(elems.begin());
        
        Elem ins = Elem( adja.value, repl.i );
        elems.insert(ins);

        llong sum1 = repl.value + a[getLeft(repl.i)];
        llong sum2 = repl.value + a[getRight(repl.i)];

        AdjaSum toRem1 (sum1, getLeft(repl.i), repl.i);
        AdjaSum toRem2 (sum2, repl.i, getRight(repl.i));

        AdjaSum toIns1 (sum1 - repl.value + adja.value, getLeft(repl.i), repl.i);
        AdjaSum toIns2 (sum2 - repl.value + adja.value, repl.i, getRight(repl.i));

        bags.erase(toRem1);
        bags.erase(toRem2);
        bags.insert(toIns1);
        bags.insert(toIns2);
    }

    cout << bags.begin()->value << endl;
}

int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}