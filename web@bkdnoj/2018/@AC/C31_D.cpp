#include <bits/stdc++.h>
using namespace std;

int divisors(int a){
	int i, d = 2;

	for(i = 2; i <= sqrt(a); i++){
		if(a % i == 0) d += 2;
	}
	if(a/i == i) d--;
	return d;
}

int tab[10000][10000] = { 0 };

int main(){
	int a, b, d, n = 0;
	cin >> a >> b;

	for(int i = a; i <= b; i++){
		d = divisors(i);
		tab[d][0]++;
		tab[d][ tab[d][0] ] = i;
		n = max(n, d);	
	}
	/*
	for(int i = 54; i < 74; i++){
		cout << i << ": ";
		for(int j = 0; j <= tab[i][0]; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	*/

	cout << tab[n][1] << " " << n << " " << tab[n][0];
	return 0;
}