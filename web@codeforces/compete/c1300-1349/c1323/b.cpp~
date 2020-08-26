#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
vector<int> A, B;

int main() {
	ios::sync_with_stdio(0);
	//
	cin >> n >> m >> k;
	A.resize(n + 1);
	B.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i-1];
	}
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i-1];
	}
	// --
	vector<int> dk;
	for (int i = 1; i*i <= k; i++)
		if (k % i == 0) {
			dk.push_back(i);
			if (i*i != k) dk.push_back(k/i);
		}
	//
	long long ans = 0;
	for (int &d : dk) {
		long long calA = 0;
		for (int i = 1; i + d - 1<= n; i++)
			calA += (A[i+d-1] - A[i-1] == d);
		//
		long long calB = 0;
		int d2 = k / d;
		for (int i = 1; i + d2 - 1 <= m; i++)
			calB += (B[i+d2-1] - B[i-1] == d2);
		//printf("d1 = %d | calA = %lld || d2 = %d | calB = %lld\n", d, calA, d2, calB);
		ans += (calA * calB);
	}
	cout << ans;
}
