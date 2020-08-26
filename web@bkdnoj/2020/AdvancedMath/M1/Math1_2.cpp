// http://bkdnoj.dut.udn.vn/public/practice_problem.php?id=Math1_2
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e6) + 3;
long long f[1000004];

long long T, N, x;

int main(){
	f[0] = 1;
	for(int i = 1; i <= MOD; i++){
		f[i] = f[i-1] * i % MOD;
	}
	for(cin >> T; T; T--){
		cin >> N >> x;
		cout << ( (N >= MOD) ? 0 : (f[N]*x % MOD) ) << '\n';
	}
}
