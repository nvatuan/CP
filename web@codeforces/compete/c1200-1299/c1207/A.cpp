#include <bits/stdc++.h>
using namespace std;

int t, b, p, f, h, c;

int main(){
	for(cin >> t; t; t--){
		cin >> b >> p >> f;
		cin >> h >> c;
		//--
		int profit = 0;
		int quantity = 0;
		if(h > c){
			quantity = min( b/2, p );
			b -= quantity*2;
			p -= quantity;
			profit += h*quantity;
			//
			quantity = min( b/2, f );
			b -= quantity*2;
			f -= quantity;
			profit += c*quantity;
		} else {
			quantity = min( b/2, f );
			b -= quantity*2;
			f -= quantity;
			profit += c*quantity;

			quantity = min( b/2, p );
			b -= quantity*2;
			p -= quantity;
			profit += h*quantity;
		}
		cout << profit << '\n';
	}
}
