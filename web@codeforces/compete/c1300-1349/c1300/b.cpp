#include <bits/stdc++.h>
using namespace std;

int T;

void solve() {
	int N;
	vector<int> A;
	cin >> N;
	N *= 2;
	A.resize(N);
	for(int &i : A) cin >> i;
	// ----
	sort(A.begin(), A.end());
	int min_dif = INT_MAX;
	for(int i = 0; i < N; i++) {
		int med1 = i;
		int med2 = (N-i-1 + i+1)/2;
		if(med1 >= med2) break;
		min_dif = min(min_dif, abs(A[med2] - A[med1]));
	}
	cout << min_dif << endl;
}

int main(){
	for(cin >> T; T; T--) {
		solve();
	}	
}
