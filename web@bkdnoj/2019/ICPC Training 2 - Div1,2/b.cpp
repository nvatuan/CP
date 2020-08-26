#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

int main() {
	ios::sync_with_stdio(0);
	//
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	//
	double L = 0.0, R = 1000000.0;
	vector<int> last_saved_answer (k);
	//
	//while ( (R-L) > EPS ) {
	for (int iter = 0; iter < 100; iter++) {
		double Mid = (L+R)/2;
		//
		// Root-problem: find K fractions that
		// P/Q is at least equals to Mid
		// 
		// Observation 1: There exists a ratio that if
		// goes beyond it just a tiny bit makes it impossible 
		// to construct a solution, 
		// but before that is feasible
		// => monotone property => binary search
		//
		// every (p, q) can be written as:
		// (q*mid + excess, q) with excess can be negative (***)
		//    (( excess now will be: excess = p - q*mid ))
		// then, after choosing K column, we ended up with
		// (Q*mid + Sigma_excess, Q)
		//
		// From the Root-problem,
		// Observation 2: P/Q >= Mid
		// <=> P >= Mid*Q <=> Q*Mid + E >= Q*Mid
		// <=> E >= 0 (this shows why Sigma_excess must be atleast Zero
		// for a solution to exist for such Mid)
		//
		// Here you see the elegantness of (***) because the left-hand side
		// completely cancels out the bit from right-hand side, leaving only
		// ONE VARIABLE on the table
		// 
		// One important thing to note is we Q doesn't matter
		// in deciding how high Mid should be, or even P!
		// They only matters in DECIDING THE SOLUTION EXISTS FOR THE ROOT-PROBLEM
		//
		// When how to confirm the existence of the solution,
		// Binary search will do its job in deciding how high Mid should be.
		//
		vector< pair<double, int> > excess (n);
		for (int i = 0; i < n; i++) excess[i] = { a[i] - b[i]*Mid , i };
		//
		sort(excess.begin(), excess.end(), greater< pair<double, int> >() );
		//
		double Sigma_excess = 0.0;
		for (int i = 0; i < k; i++) Sigma_excess += excess[i].first;
		if(Sigma_excess >= EPS) {
			L = Mid;
			for (int i = 0; i < k; i++) last_saved_answer[i] = excess[i].second;
		} else {
			R = Mid;
		}
	}
	//
	long long P = 0, Q = 0;
	for (int &idx : last_saved_answer) P += a[idx], Q += b[idx];
	cout << P/__gcd(P, Q) << " " << Q/__gcd(P,Q) << '\n';
}
