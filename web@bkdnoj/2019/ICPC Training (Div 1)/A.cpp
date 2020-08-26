#include <bits/stdc++.h>
using namespace std;

int T;
string N;

bool check(string& N) {
	int type = 3;
	int index = 0;
	//
	for(; index < N.length(); index++) {
		if(N[index] == '1') {
			if(type == 0) {
				type = 0;
				continue;
			} else {
				type = 0;
				continue;
			}
		}
		if(N[index] == '2') {
			if(type < 2) {
				type++;
				continue;
			} else {
				return false;
			}
		}
		//
		return false;
	}
	return true;
}

int main() {
	for(cin >> T; T; T--) {
		cin >> N;
		cout << ( check(N) ? "Yes\n" : "No\n" );
	}	
}
