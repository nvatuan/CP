#include <bits/stdc++.h>
using namespace std;

int n; 
vector<vector<int>> magic;

void magicSquareOdd() {
    int x = n/2 + 1;
    int y = 1;
    for(int i = 1; i <= n*n; i++) {
        magic[y][x] = i;
        x++;
        if(x > n) x = 1;
        y--;
        if(y < 1) y = n;
        // --
        if( magic[y][x] ) {
            x--; if(x < 1) x = n;
            y++; if(y > n) y = 1;
            y++; if(y > n) y = 1;
        }
    }
}

void magicSquareDoublyEven() {
    vector<vector<int>> logic = magic;
    for(int i = 1; i <= n; i++) {
        logic[i][i] = 1;
        logic[n-i+1][i] = 1;
    }
    // --
    int c = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if( !logic[i][j] ) {
                magic[i][j] = c;
            }
            c++;
        }
    }
    c = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            if( logic[i][j] ) {
                magic[i][j] = c;
            }
            c++;
        }
    }
}

// ======================================================================================
// This part of code was shamelessly stolen from:
// https://rosettacode.org/wiki/Magic_squares_of_singly_even_order 
// ======================================================================================
class magicSqr
{
public: 
    magicSqr() { sqr = 0; }
    ~magicSqr() { if( sqr ) delete [] sqr; }
 
    void create( int d ) {
        if( sqr ) delete [] sqr;
        if( d & 1 ) d++;
        while( d % 4 == 0 ) { d += 2; }
        sz = d;
        sqr = new int[sz * sz];
        memset( sqr, 0, sz * sz * sizeof( int ) );
        fillSqr();
    }
    void display() {
        // cout << "Singly Even Magic Square: " << sz << " x " << sz << "\n";
        // cout << "It's Magic Sum is: " << magicNumber() << "\n\n";
        ostringstream cvr; cvr << sz * sz;
        int l = cvr.str().size();
 
        for( int y = 0; y < sz; y++ ) {
            int yy = y * sz;
            for( int x = 0; x < sz; x++ ) {
                cout << setw( l + 2 ) << sqr[yy + x];
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
private:
    void siamese( int from, int to ) {
        int oneSide = to - from, curCol = oneSide / 2, curRow = 0, count = oneSide * oneSide, s = 1;
 
        while( count > 0 ) {
            bool done = false;
            while ( false == done ) {
                if( curCol >= oneSide ) curCol = 0;
                if( curRow < 0 ) curRow = oneSide - 1;
                done = true;
                if( sqr[curCol + sz * curRow] != 0 ) {
                    curCol -= 1; curRow += 2;
                    if( curCol < 0 ) curCol = oneSide - 1;
                    if( curRow >= oneSide ) curRow -= oneSide;
 
                    done = false;
                }
            }
            sqr[curCol + sz * curRow] = s;
            s++; count--; curCol++; curRow--;
        }
    }
    void fillSqr() {
        int n = sz / 2, ns = n * sz, size = sz * sz, add1 = size / 2, add3 = size / 4, add2 = 3 * add3;
 
        siamese( 0, n );
 
        for( int r = 0; r < n; r++ ) {
            int row = r * sz;
            for( int c = n; c < sz; c++ ) {
                int m = sqr[c - n + row];
 
                sqr[c + row] = m + add1;
                sqr[c + row + ns] = m + add3;
                sqr[c - n + row + ns] = m + add2;
            }
        }
 
        int lc = ( sz - 2 ) / 4, co = sz - ( lc - 1 ); 
        for( int r = 0; r < n; r++ ) {
            int row = r * sz;    
            for( int c = co; c < sz; c++ ) {    
                sqr[c + row] -= add3;
                sqr[c + row + ns] += add3;
            }
        }
        for( int r = 0; r < n; r++ ) {
            int row = r * sz;    
            for( int c = 0; c < lc; c++ ) {
                int cc = c;
                if( r == lc ) cc++;
                sqr[cc + row] += add2;
                sqr[cc + row + ns] -= add2;
            }
        }
    }
    int magicNumber() { return sz * ( ( sz * sz ) + 1 ) / 2; }
 
    void inc( int& a ) { if( ++a == sz ) a = 0; }
 
    void dec( int& a ) { if( --a < 0 ) a = sz - 1; }
 
    bool checkPos( int x, int y ) { return( isInside( x ) && isInside( y ) && !sqr[sz * y + x] ); }
 
    bool isInside( int s ) { return ( s < sz && s > -1 ); }
 
    int* sqr;
    int sz;
};
// ======================================================================================
void whyMathOutOfAllThings(){
    magicSqr mg;
    mg.create(n);
    mg.display();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // --
    cin >> n;
    magic = vector<vector<int>> (n + 1, vector<int>(n + 1));
    // --
    if(n % 2 == 1) {
        magicSquareOdd();
        goto OUTPUT;
    }
    if(n % 4 == 0) {
        magicSquareDoublyEven();
        goto OUTPUT;
    }
    if(n % 2 == 0 && n % 4 != 0) {
        whyMathOutOfAllThings();
        return 0;
    }
    // -- output
OUTPUT:
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", magic[i][j]);
        }
        printf("\n");
    }
}