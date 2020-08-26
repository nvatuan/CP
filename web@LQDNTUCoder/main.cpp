#include <bits/stdc++.h>
using namespace std;

const int K = 111539786;

vector<vector<long long>> mt_mul(vector<vector<long long>> A, vector<vector<long long>> B){
	if(A.size() != A[0].size()) assert(0);
	if(B.size() != B[0].size()) assert(0);
	//--
	vector< vector<long long> > C (2, vector<long long>(2, 0));
	C[0][0] = (A[0][0] * B[0][0] % K + A[0][1] * B[1][0] % K) % K;
	C[0][1] = (A[0][0] * B[0][1] % K + A[0][1] * B[1][1] % K) % K;
	C[1][0] = (A[1][0] * B[0][0] % K + A[1][1] * B[1][0] % K) % K;
	C[1][1] = (A[1][0] * B[0][1] % K + A[1][1] * B[1][1] % K) % K;
	//
	return C;
}

vector<vector<long long>> expMul(vector<vector<long long>> mt, int expo){
	if(expo == 1) return mt;
	if(expo % 2 == 0){
		return expMul( mt_mul(mt, mt), expo/2 );
	} else {
		return mt_mul(expMul( mt_mul(mt, mt), expo/2 ), mt);
	} 
}

long long fb( int n ){
	vector< vector<long long> > E {{1, 1}, {1, 0}}, MT;	
	MT = expMul(E, n);
	return MT[0][1];
}

int main(){
//	vector<vector<long long> > A {{1, 2}, {3, 4}};
//	vector<vector<long long> > B {{5, 6}, {7, 8}}; 
//	cout << A[0][0] << ' ' << A[0][1] << '\n';
//	cout << A[1][0] << ' ' << A[1][1] << endl << endl;
//	A = mt_mul(A, B);
//	cout << A[0][0] << ' ' << A[0][1] << '\n';
//	cout << A[1][0] << ' ' << A[1][1];
//	return 0;
	//
	int T;
	int n = 1;
	for(cin >> T; T; T--){
		cin >> n;
		cout << fb(n) << '\n';
	}	
}
