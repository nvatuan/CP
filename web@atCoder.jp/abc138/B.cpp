#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	int q;
	double sig = 0.0;
	while(n--){
		cin >> q;
		sig += (1.0/q);
	}
	printf("%.6lf", 1.0/sig);
}
