#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
        int n = 0;
        vector< vector<float> > data, echelon;
        vector< float > Roots;
        // --
        void input() {
            cin >> n;
            data = vector< vector<float> > (this->n, vector<float> (this->n + 1, 0.0));
            for(vector<float>& V : data) 
                for(float& f : V) {
                    cin >> f;
                }
        }
        
        void swap_row(int i, int j) {
            for(int k = 0; k <= n; k++) swap(data[i][k], data[j][k]);
        }

        void print() {
            printf("Data is a (%d x %d) matrix:\n", n, n);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= n; j++) {
                    printf("%*.*f ", 5, 3, data[i][j]);
                }
                printf("\n");
            }
        }

        friend ostream& operator<<(ostream&, vector<vector<float>>);
        
        void print_Roots() {
            printf("Roots of Matrix is:\n");
            for(float &f : Roots) {
                printf("%*.*f ", 5, 3, f);
            }
            cout << endl;
        }

        vector<float> Gaussian_Elimination() {
            vector<float> roots (n, 0);
            vector< vector<float> >& A = data;
            // --
            for(int i = 0; i < n; i++) {
                print();
                if(A[i][i] == 0.0) {
                    for(int j = i+1; j < n; j++) {
                        if(A[j][i] != 0.0) {
                            swap_row(i, j);
                        }
                    }
                }
                // --
                if(A[i][i] == 0.0) return vector<float> ();
                for(int j = i+1; j < n; j++) {
                    float m = (- A[j][i] / A[i][i]);
                    for(int k = 0; k <= n; k++) {
                        A[j][k] += A[i][k] * m;
                    }
                }
            }
            echelon = A;
            // --
            for(int i = n-1; i >= 0; i--) {
                roots[i] = A[i][n];
                for(int j = n-1; j > i; j--) {
                    roots[i] -= roots[j]*A[i][j];    
                }
                roots[i] /= A[i][i];
            }
            Roots = roots;
            return roots;
        }
};

int main() {
    Matrix A;
    A.input();
    A.print();
    auto V = A.Gaussian_Elimination();
    A.print_Roots();
    //
    return 0;
}