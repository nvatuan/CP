#include <bits/stdc++.h>
using namespace std;

long long T, n, a, b;
string s;

vector< pair<int, int> > trough;

long long initialCost(){
	long long c = (n+1)*b + n*a;
	int lift = 0;
	//
	int ts = -1, te = -1;
	for( int i = 0; i < n; i++ ){
		if( s[i] == '1' ){
			if(!lift){
				lift = 1;
				c += (b);
				c += (a);
				//
				te = i-1;
				if(ts != -1) trough.push_back( {ts, te} );
			}
			c += (b);
		} else {
			if(lift){
				lift = 0;
				c += (a);
				//
				ts = i;
			}
		}
	}

	return c;
}

int main(){
	for(cin >> T; T; T--){
		cin >> n >> a >> b;
		cin >> s;
		//
		long long cost = initialCost();
//		cout << "Test:\n";
//		cout << cost << endl;
//		for( auto p : trough ) cout << p.first << ' ' << p.second << endl;
		//
		for( auto p : trough ){
			long long s = p.first;
			long long e = p.second;
			if( (e-s)*b - (2*a) < 0 ) cost += ((e-s)*b - (2*a));
		}
		cout << cost << '\n';
		trough.clear();
	}
}
