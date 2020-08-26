// http://bkdnoj.dut.udn.vn/public/practice_problem.php?id=Math1_6 
#include <bits/stdc++.h>
using namespace std;

const int M = int(1e9) + 7;

long long bExp(long long base, long long e, long long M){
	if(e == 0) return 1;
	if(e == 1) return base % M;
	if( e % 2 ) 
		return bExp(base * base % M, e/2, M) * base % M;
	else 	return bExp(base * base % M, e/2, M);
}

int main(){
	int n;
	cin >> n;
	vector<int> a (n);
	for(int i = 0; i < n; i++) cin >> a[i];
	//
	int G = a[0];
	for(int x : a) G = __gcd(G, x);
	//
	long long prod = 1;
	for(int x : a) prod = (prod * x) % M;
	//
	cout << bExp(prod, G, M);
}
