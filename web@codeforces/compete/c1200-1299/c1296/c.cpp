#include <bits/stdc++.h>
using namespace std;

void move(int &x, int &y, char c) {
	switch(c) {
		case 'L':
			x -= 1;
			break;
		case 'R':
			x += 1;
			break;
		case 'U':
			y += 1;
			break;
		case 'D':
			y -= 1;
			break;
	}
}

void solve() {
	int N; string S;
	// --
	cin >> N >> S;
	int x = 0, y = 0;
	map< pair<int, int>, int > beenthere;
	//
	int IDX = 1;
	int ans[2];
	int Min = INT_MAX;
	//
	for(char c : S) {
		beenthere[ {x, y} ] = IDX;
		move(x, y, c);
		IDX++;
		//
		if(beenthere[ {x, y} ] == 0) {
		} else {
			if(IDX - beenthere[ {x, y} ] < Min) {
				ans[0] =  beenthere[ {x, y} ];
				ans[1] = IDX - 1;
				Min = IDX - beenthere[ {x, y} ]; 
			}
		}
	}
	if(beenthere[ {x, y} ] == 0) {
	} else {
		if(IDX - beenthere[ {x, y} ] < Min) {
			ans[0] = beenthere[ {x, y} ];
			ans[1] = IDX - 1;
			Min = IDX - beenthere[ {x, y} ]; 
		}
	}
	if(Min == INT_MAX) {
		cout << "-1\n";
	} else {
		cout << ans[0] << " " << ans[1] << "\n";
	}
}

int main() {
	int T;
	for(cin >> T; T; T--) {
		solve();
	}
}
