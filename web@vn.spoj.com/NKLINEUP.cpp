//vn.spoj.com/problems/NKLINEUP/
#define infile freopen("input.txt", "r", stdin)
#define outfile freopen("output.txt", "w", stdout)

#include <bits/stdc++.h>
#define FOR(i, a, b) for(long i = a; i <= b; i++)
#define br cout << "\n"
using namespace std;

const int MAXVAL = 1000000;
const int MINVAL = 1;

int lgb2;
long n, q, l, r;
long sparseTable[2][50001][17];
long A[50001];

long long mypow(long n, long k){
	if(k<0) return 0;
	if(k==0) return 1;
	if(k==1) return n;
	
	if(k%2) return mypow(n*n, k/2) * n;
	else return mypow(n*n, k/2);
}

bool cmp(long x, long y, bool lookForMax){
	return( !((x>y)^lookForMax) );
}

void buildSparseTable(long lg, long M[50001][17], bool (*cmp)(long, long, bool), bool lookForMax){
	int l;
	FOR(j, 0, lg){

		FOR(i, 0, n-1){ // - j
			l = mypow(2, j-1);

			if(i + l == n) break;
			if(j){
				//if(A[ M[i][j-1] ] > A[ M[i + l][j-1] ] ) 
				if( cmp( A[M[i][j-1]], A[M[i + l][j-1]], !lookForMax) )
					M[i][j] = M[i + l][j-1];
				else M[i][j] = M[i][j-1];
			}
			else M[i][j] = i;
		}
	}
}

long surf(long i, long lg, long Accel, bool lookForMax){
	//cout << A[sparseTable[lookForMax][i][lg]]; br;
	//cout << "i: " << i << " lg: " << lg; br;

	if((i+Accel>r)&&(i<r)) return(surf(i, lg-1, Accel/2, lookForMax));
	if(i==r) return A[sparseTable[lookForMax][r][0]];
	else if(lookForMax)	return max( A[sparseTable[lookForMax][i][lg]] , surf(i+Accel, lg-1, Accel/2, lookForMax));
		 else return min(A[ sparseTable[lookForMax][i][lg] ], surf(i+Accel, lg-1, Accel/2, lookForMax));
}

int main(){
	//infile;
	//outfile;

	cin >> n >> q;
	FOR(i, 0, n-1) cin >> A[i];
	////
	lgb2 = (int) (log(n)/log(2));
	buildSparseTable(lgb2, sparseTable[1], cmp, true);
	buildSparseTable(lgb2, sparseTable[0], cmp, false);
	////

	string bk = " ";/*
	cout << lgb2; br;
	FOR(i, 0, lgb2){
 		FOR(j, 0, n-1){
 			if (!((i)&&(mypow(2, i) + j > n)))
			cout << A[ sparseTable[0][j][i] ] << bk;
		}
		br;
	}*//*
	bk = " ";
	FOR(i, 0, lgb2){
		FOR(j, 0, n-1){
			if(i>0) 
				if(mypow(2, i) + j > n) break;
			cout << A[ sparseTable[1][j][i] ] << bk;
		}
		br;
	}
	br; br;*/


	int lg;
	long Accel;
	long mx, mn;
	while(q-- > 0){
		cin >> l >> r;
		l--;
		r--;

		if(l==r) cout << 0 << "\n";
		else{
			lg = (int) floor( log(r-l)/log(2) );
			Accel = (long) pow(2, lg);
			//
			//cout << l << " " << lg << " " << Accel; br;
			mx = surf(l, lg, Accel, true);
			mn = surf(l, lg, Accel, false);

			//cout << mx << " " << mn; br; br;
			cout << mx - mn; br;
		}
	}		
}