#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i < b; i++)
#define tnum ch-48
using namespace std;

int main(){
	int t, n;
	int r, c;
	int i, j, kolor;
	long long trips = 0;

	char ch;
	int a[1000][1000];
	char row[3][1000][1001], col[3][1001][1000];

	cin >> t;
	while(t > 0){
		t--;
		cin >> r >> c;
		FOR(i, 0, r){
			FOR(j, 0, c){
				cin >> ch;
				a[i][j] = tnum;
				if(ch != '0') {row[tnum][i][0]++; row[tnum][i][row[tnum][i][0]] = j;
								col[tnum][j][0]++; col[tnum][j][col[tnum][j][0]] = i;}
			}
			cin.ignore();
		}
	}

	//(kolor+1)%2
	int prev;
	FOR(i, 0, r){
		prev = row[1][i][0];
		if(prev != 0){
		FOR(j, 0, c){
			if((prev == 1) && (a[i][j] == 2)){
				trips += col[2][j][0] * prev;
			}
		}
		}

		prev = row[2][i][0];
		if(prev != 0){
		FOR(j, 0, c){
			if((prev == 2) && (a[i][j] == 1)){
				trips += col[1][j][0] * prev;
			}
		}
		}
	}
	cout << trips;
}