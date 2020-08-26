// http://bkdnoj.dut.udn.vn/public/practice_problem.php?id=Math1_0
#include <bits/stdc++.h>
using namespace std;

long long bPow(long long base, long long e, long long M){
	if(e == 0) return 1;
	if(e == 1) return base % M;
	if( e % 2 ) return bPow(base*base%M, e/2, M) * base % M;
	else return bPow(base*base%M, e/2, M);
}

long long inv(long long x, long long y, long long p, long long q, long long r, long long s, long long M) {
	if(y == 0) return (p % M + M)%M;
	return inv(y, x%y, r, s, p-r*(x/y), q-s*(x/y), M);
}

int main(){
	int A, B, C, M;
	cin >> A >> B >> C >> M;
	//
	cout << bPow(A, B, M)*inv(C, M, 1, 0, 0, 1, M)%M;
}
