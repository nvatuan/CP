#include <bits/stdc++.h>
using namespace std;

int n, m;

int a[51][51];
int b[51][51];

vector< pair<int, int> > operations;

int check(int x, int y){
	return (a[x][y] && a[x+1][y] && a[x][y+1] && a[x+1][y+1]);
}

void op(){
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m-1; j++){
			if(check(i, j)) {
				operations.push_back( {i+1, j+1} );
				b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
			}
		}
}

int sameMatrix(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if( a[i][j] != b[i][j] ) return 0;
	return 1;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	//
	op();
	if( sameMatrix() ){
		cout << operations.size() << '\n';
		for( auto p : operations ) cout << p.first << ' ' << p.second << '\n';
	} else cout << -1;
}
