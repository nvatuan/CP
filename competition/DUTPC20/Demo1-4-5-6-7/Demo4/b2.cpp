#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<double> a;

bool checker(double x) {
	int cnt = 0;
	for (double d : a) cnt += (int)(d / x);
	return (cnt >= k);
}

int main() {
	cin >> n >> k;
	a.resize(n);
	for (double &d : a) {
		cin >> d;
	}

	double L = 1.0, R = *max_element(a.begin(), a.end());
	const double eps = 1e-9;
	while (R - L > eps) {
		double mid = (R+L)/2;
		if (checker(mid)) L = mid;
		else R = mid;
	}
	cout << setprecision(2) << fixed << L << endl;
}
