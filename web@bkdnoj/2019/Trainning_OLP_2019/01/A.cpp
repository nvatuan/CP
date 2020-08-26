#include <bits/stdc++.h>
using namespace std;

int n, k;
int v1, v2;

int s;

pair<long long, int> Oil[100002];

#define X first
#define A second

double Lbound, Rbound;

bool Catch(double time) {
	double s1 = s*1.0;
	double s2 = 0.0;
	double pass = s1/(v2-v1);
	//
	int K = 0;
	multiset<int> delay;
	//
	s1 += pass*v1;
	s2 = pass*v2;

	while( time - pass >= 0.000000001 ) {

		for(; (s1 - Oil[K].X > 0.000000001) && (K < n); K++) {
			if( Oil[K].X >= s ) delay.insert(Oil[K].A);
		}

		while( s2 >= s1 ) {
			if(delay.size() == 0) return 1;
			//
			pass += *(delay.rbegin());
			s1 += (*(delay.rbegin()) * v1);
			//
			delay.erase( *(delay.rbegin()) );
		}

		if( s1 - s2 > 0.000000001 ) {
			double newTime = (s1 - s2)/(v2-v1);
			pass += newTime;
			s1   += newTime*v1;
			s2   += newTime*v2;
		}
	}
	return 0;
}

int main() {
	cin >> n >> k;
	cin >> v1 >> v2;
	cin >> s;
	//
	if(v1 >= v2) {
		cout << "inf";
		return 0;
	}
	// -- Able to catch
	Lbound = s*1.0/(v2 - v1);
	Rbound = s*1.0/(v2 - v1) + 69;

	for(int i = 0; i < n; i++) {
		cin >> Oil[i].X >> Oil[i].A;
		Rbound += Oil[i].A;
	}
	Oil[n+1].X = LLONG_MAX;
	sort(Oil, Oil + n + 1);
	// --

	cout << fixed << setprecision(6);

	while( fabs(Lbound - Rbound) >= 1e-7) {
		double givenTime = (Lbound + Rbound)/2;

		//cout << Lbound << " & " << Rbound << " | " << givenTime << endl;
	
		if(Catch(givenTime)) {
			Rbound = givenTime;
		} else {
			Lbound = givenTime;
		}
	}
	cout << setprecision(6) << Lbound;
}