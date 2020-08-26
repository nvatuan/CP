#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define BAC(i,a,b) for(i=a; i>=b; i--)
#define br cout << endl
#define llong long long
using namespace std;

int r, c;
int x, y;
llong aL, aR;
char ch;
bool visited[2002][2002];
long long ans;

void spread(int x, int y, llong lL, llong lR){
	ans++;
	visited[x][y] = true;
	if(!visited[x+1][y]) spread(x+1, y, lL, lR);
	if(!visited[x-1][y]) spread(x-1, y, lL, lR);
	if((!visited[x][y+1])&&(lR>0)) spread(x, y+1, lL, lR-1);
	if((!visited[x][y-1])&&(lL>0)) spread(x, y-1, lL-1, lR);
}

int main(){
	int i, j;
	cin >> r >> c;
	cin >> x >> y;
	cin >> aL >> aR;
	FOR(i, 1, r)
		FOR(j, 1, c){
			cin >> ch;
			//o[i][j] = (ch=='*');
			visited[i][j] = !!(ch=='*');
		}
		///
	FOR(i, 0, r+1) {visited[i][0] = true; visited[i][c+1] = true;}
	FOR(j, 0, c+1) {visited[0][j] = true; visited[r+1][j] = true;}
	spread(x, y, aL, aR);
	cout << ans;
}
/*
	br;
		FOR(i, 0, r+1){
		FOR(j, 0, c+1){
			if(visited[i][j]) cout << 'X';
			else cout << 'O';
		}
		br;}
	getchar();

*/