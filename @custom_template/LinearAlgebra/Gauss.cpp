#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
        int n = 0;
        vector< vector<double> > data, echelon;
        vector< double > Roots;
        
        void swap_row(int i, int j) {
            for(int k = 0; k <= n; k++) swap(data[i][k], data[j][k]);
        }

        void print() {
            printf("Data is a (%d x %d) matrix:\n", n, n);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= n; j++) {
                    printf("%d ", data[i][j]);
                }
                printf("\n");
            }
        }
        
        void print_Roots() {
            printf("Roots of Matrix is:\n");
            for(double &f : Roots) {
                printf("%d ",  f);
            }
            cout << endl;
        }

        const double EPS = 1e-9;
        const int INF = 2; // it doesn't actually have to be infinity or a big number

        int gauss (vector < vector<double> > a, vector<double> & ans) {
            int n = (int) a.size();
            int m = (int) a[0].size() - 1;

            vector<int> where (m, -1);
            for (int col=0, row=0; col<m && row<n; ++col) {
                int sel = row;
                for (int i=row; i<n; ++i)
                    if (abs (a[i][col]) > abs (a[sel][col]))
                        sel = i;
                if (abs (a[sel][col]) < EPS)
                    continue;
                for (int i=col; i<=m; ++i)
                    swap (a[sel][i], a[row][i]);
                where[col] = row;

                for (int i=0; i<n; ++i)
                    if (i != row) {
                        double c = a[i][col] / a[row][col];
                        for (int j=col; j<=m; ++j)
                            a[i][j] -= a[row][j] * c;
                    }
                ++row;
            }

            ans.assign (m, 0);
            for (int i=0; i<m; ++i)
                if (where[i] != -1)
                    ans[i] = a[where[i]][m] / a[where[i]][i];
            for (int i=0; i<n; ++i) {
                double sum = 0;
                for (int j=0; j<m; ++j)
                    sum += ans[j] * a[i][j];
                if (abs (sum - a[i][m]) > EPS)
                    return 0;
            }

            for (int i=0; i<m; ++i)
                if (where[i] == -1)
                    return INF;
            return 1;
        }

        int Gaussian_Elimination() {
            int res = gauss(this->data, this->Roots);
            return res;
        }
};

int main() {
    // Matrix A;
    // A.input();
    // A.print();
    // auto V = A.Gaussian_Elimination();
    // A.print_Roots();
    
    int w, h; cin >> h >> w;
    vector<vector<int>> numbering (h, vector<int>(w, 0));
    
    for (int i = 0; i < w*h; i++) {
        numbering[i / w][i % w] = i;
    }
    //for (auto v : numbering) {
    //    for (auto i : v) cout << i <<  ' ';
    //    cout << endl;
    //}

    vector<vector<int>> affect (w*h, vector<int> (w*h, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++)
                    if (dx*dy == 0)
                        try {
                            int button = numbering[i][j];
                            affect[button][numbering.at(i+dx).at(j+dy)] = 1;
                            // cerr << "button: " << button << ' ';
                            // cerr << "added : " << i+dx << ' ' << i+dy << endl;
                        } catch (...) {
                            // cerr << "not added : " << i+dx << ' ' << i+dy << endl;
                        }
            }
        }
    }
    
    // for (int b = 0; b < w*h; b++) {
    //     cerr << "Button#" << b << endl;
    //     for (int i = 0; i < h; i++) {
    //         for (int j = 0; j < w; j++) {
    //             cerr << affect[b][i*w+j] << ' ';
    //         }
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }

    vector<int> rhs (h*w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            rhs[i*w + j] = (c == 'B' ? 1 : 0);
        }
    }

    Matrix gauss;
    gauss.n = h*w;
    gauss.data = vector<vector<int>> (gauss.n, vector<int> (gauss.n + 1, 0));
    for (int r = 0; r < gauss.n; r++) {
        for (int c = 0; c < gauss.n; c++) gauss.data[r][c] = affect[r][c];
        gauss.data[r][gauss.n] = rhs[r];
    }
    gauss.print();
    gauss.Gaussian_Elimination();

    //gauss.print_Roots();
    cerr << gauss.Roots.size() << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (gauss.Roots.at(i*w+j) % 2 != 0 ? "1 " : "0 ");
        }
        cout << endl;
    }

    return 0;
}