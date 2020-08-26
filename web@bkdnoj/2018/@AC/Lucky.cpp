#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long index = 0, bin = 2;
	int len = 1;

	while(bin < n){
		n -= bin;
		bin *= 2;
		len++;
	}

	bin = pow(2, len-1);

	n--;
	while(len > 0){
		if(n >= bin){
			n -= bin;
			cout << 7;
		}
		else{
			cout << 4;
		}
		bin /= 2;
		len--;
	}
}