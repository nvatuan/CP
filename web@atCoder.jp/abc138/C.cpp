#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	//--
	sort(v.begin(), v.end());
	double greed = 1.0*v[0];
	for(int i = 1; i < n; i++){
		greed = (greed + v[i])/2;
	}
	//
	printf("%.6lf", greed);
}
