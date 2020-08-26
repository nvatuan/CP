#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct {
	ll m[2][2];
}mt22;

const int MOD = 1e4 + 7;
ll n;
mt22 f1;

mt22 matrixMul(mt22 ma, mt22 mb){
	mt22 t;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++){
			t.m[i][j] = 0;
			for(int r=0; r < 2; r++)
				t.m[i][j] += (ma.m[i][r] * mb.m[r][j]) % MOD;
		}
	return t;
}

mt22 fibMtrxMul(ll n){
	if(n==1) return f1;
	else{
		mt22 tmp = fibMtrxMul(n/2);
		if(n%2)	return matrixMul(matrixMul(tmp, tmp), f1);
		else return matrixMul(tmp, tmp);
	}
}

int main(){
	for(int i = 0; i < 4; i++) f1.m[i/2][i%2] = 1;
	f1.m[1][1] = 0;

	cin >> n;
	cout << (fibMtrxMul(n).m[1][0]%MOD) << "\n";
}