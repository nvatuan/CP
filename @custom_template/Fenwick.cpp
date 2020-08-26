#include <bits/stdc++.h>
using namespace std;

// ##################################### CLASS DEF #####################################
typedef long long int64;
class Fenwick {
        int             _n;
        vector<int64>   _F;
    public:
        // -- sum queries
        const int64 sum (int64 K) {
            int64 res = 0;
            while ( K > 0 ) {
                res += _F[K];
                K -= (K & -K);
            }
            return res;
        }
        const int64 sum (const int64 L, const int64 R) {
            return sum(R) - sum(L-1);
        }
        // -- constructors / deconstructor
        Fenwick() {
            _n  = 0;
            _F  = vector<int64> ();
        }
        Fenwick(const vector<int64>& A) {
            _n  = A.size() + 1;
            _F  = vector<int64> (_n, 0);
            //
            for(int i = 1; i < _n; i++) {
                _F[i] = sum( i - (i & -i) + 1, i - 1) + A[i - 1];
            }
        }
        ~Fenwick(){}
        // --
        void add(int64 K, const int64& x) {
            while(K <= _n) {
                _F[K] += x;
                K += (K & -K);
            }
        }
        // --
        friend ostream& operator<<(ostream&, Fenwick);
};

ostream& operator<<(ostream& os, Fenwick F) {
    for(int i = 1; i < F._n; i++) {
        os << F._F[i] << " ";
    }
    os << endl;
    return os;
}
// ##################################### TESTING #####################################

int main() {
    vector<int64> A {1, 1, 1, 1, 0, 1, 1, 1};
    Fenwick F (A);
    cout << F;
    F.add(5, 1);        // indexing starts from 1;
    cout << F;
}