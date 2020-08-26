#include <bits/stdc++.h>
using namespace std;

void retry(long k, long n){
	//cout << k << " " << n <<endl;
	if(k % n == 0) cout << n;
	else retry(n+n%k, k%n);
}

int main(){
	long long n, k;
	cin >> n >> k;
	
	if(k % n == 0) cout << n;
	else retry(n+k%n, k%n);
	return 0;
}