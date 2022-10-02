//mridul1809
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = int(1e9) + 7;

template <typename T>
class Matrix {
public:
    vector < vector <T> > A;
    int r,c;

    //Default Constructor
    Matrix()
    {
      this->r = 0;
      this->c = 0;
    }

    //Matrix with given dimensions and random values
    Matrix(int r,int c)
    {
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    //Matrix with given value and dimensions
    Matrix(int r,int c,const T &val)
    {

        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }

    //Identity matrix with given dimension
    Matrix(int n)
    {
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }

    //Print the matrix
    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout << A[i][j] << " ";

            cout << endl;
        }
    }

    //Input called to get input
    //Put custom code
    void input()
    {
        // for(int i=0;i<r;i++)
        //     for(int j=0;j<c;j++)
        //         define inout here
    }

    //Overloaded * operator to multiply 2 matrices
    //with conformable dimensions
    Matrix operator * (const Matrix<T> &B)
    {

        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
          for(k=0 ; k<y ; k++)
            for(j=0 ; j<z ; j++) //cache friendly
                {
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }

        return C;
    }

    //Overloaded *= operator to add 2 matrices
    //of conformable dimensions
    //and save result in first matrix
    void operator *= (const Matrix<T> &B)
    {
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(k=0 ; k<y ; k++)
              for(j=0 ; j<z ; j++) //cache friendly
                {
                    C[i][j] = (C[i][j] + ( (long long)A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }
        this->r = C.r;
        this->c = C.c;
        this->A = C.A;
    }

    //Overloaded + operator to add 2 matrices
    //with same dimensions
    Matrix operator + (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                #endif
            }

        return C;
    }

    //Overloaded += operator to add 2 matrices
    //of same dimensions
    //and save result in first matrix
    void operator += (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                A[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                A[i][j] %= mod;
                #endif
            }
    }

    //Overload unary - to get negative of a matrix
    Matrix operator - ()
    {
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = -A[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }

    //Overload binary - to subtract a matrix
    //from other with same dimensions
    Matrix operator - (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }

    //Overload binary - to subtract a matrix
    //from other with same dimensions
    //and save result in first matrix
    void operator -= (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                A[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                A[i][j] %= mod;
                if(A[i][j] < 0)
                    A[i][j] += mod;
                #endif
            }
    }

    vector<T>& operator [] (int i)
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }
    const vector<T>& operator [] (int i) const
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    friend ostream& operator << (ostream &out,const Matrix<T> &M)
    {
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }

};

int offset[5000];
ll sum[5000];

int  n, t;
ll a[2000];
void solve() {
  cin >> n >> t;
  for (int i=0; i<n; i++) cin >> a[i];

  int tot = n*(n+1)/2;

  offset[0] = 0;
  for (int i=1; i<=n; i++) {
    offset[i] = offset[i-1] + (n-i+1);
  }

  for (int i=0; i<n; i++) {
    ll s=0;
    for (int j=i; j<n; j++) {
      s += a[j];
      s %= mod;
      ll p = offset[j - i] + i;
      sum[p] = s;
    }
  }

  Matrix <ll> A(1, tot, 0);
  A[0][tot-1] = 1;

  Matrix <ll> T(tot, tot, 0);
  for (int i=0; i<n; i++) {
    for (int j=i; j<n; j++) {

      for (int l=0; l<n; l++)
        for (int r=l; r<n; r++){
          if (! (l <= i and j <= r)) continue;
          ll p = offset[j - i] + i;
          ll pf = offset[r - l] + l;
          T[pf][p] = 1;
        }
    }
  }


  // for (int i=1; i<=t; i++) {
  //   A *= T;
  // }
  while (t) {
    if (t & 1) A *= T;
    T *= T;
    t >>= 1;
  }

  ll ans=0;
  for (int i=0; i<tot; i++) {
    ans += (A[0][i] * sum[i]);
    ans %= mod;
  }
  cout << ans << '\n';

}

int main() {
  int T; cin >> T;
  while (T--)
    solve();
}
