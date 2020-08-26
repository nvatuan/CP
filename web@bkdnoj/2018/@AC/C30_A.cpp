#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a ; i<b ; i++)
using namespace std;

int row[100] = {0} , col[100] = {0};

int main(){
	int r, c;
	int i, j;
	char ch[100][100];

	cin >> r >> c;
	FOR(i, 0, r){
		FOR(j, 0, c) cin >> ch[i][j];
		cin.ignore();
	}

	FOR(i, 0, r)
		FOR(j, 0, c)
			if(ch[i][j] == '.') {
				row[i]++;
				col[j]++;
			}
	
	FOR(i, 0, r){
		if(row[i] < c){
			FOR(j, 0, c) 
				if(col[j] < r) cout << ch[i][j];
			cout << endl;
		}
	}
}