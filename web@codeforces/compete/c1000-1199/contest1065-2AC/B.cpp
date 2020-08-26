#include <bits/stdc++.h>
using namespace std;

int main(){
	long long v, e;
	cin >> v >> e;

	if(e == 0)
		cout << v << ' ' << v;
	else{
		//min
		if(e*2 >= v) cout << 0;
		else cout << (v - e*2);
		cout << ' ';
		//
		long long n = 1;
		long long retr = 0;
		do{
			retr += n;
			n++;
		} while(retr < e);

		if(v < n) cout << 0;
		else cout << (v - n);
	}
}