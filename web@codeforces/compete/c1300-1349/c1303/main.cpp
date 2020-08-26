#include <bits/stdc++.h>
using namespace std;

char lastchar;

void dfs(char c, vector<int> &Ch, vector<vector<char>> &edgelist) {
	Ch[c] = 1;
	for(char &cc : edgelist[c]) {
		if(Ch[cc] == 0) dfs(cc, Ch, edgelist);
	}
	if(lastchar == '.') lastchar = c;
}

int  dc;
bool answerfound;
void dfs2(char c, vector<int> &Ch, vector<vector<char>> &E, int Count = 1) {
	Ch[c] = 1;
	for(char &cc : E[c]) {
		if(Ch[cc] == 0) dfs2(cc, Ch, E, Count+1);
		if(answerfound) {
			cout << c;
			return;
		}
	}
	if(Count == dc) {
		cout << "YES\n";
		answerfound = true;
		cout << c;
	}
}

void solve() {
	string S;
	cin >> S;
	// --
	vector< vector<char> > edgelist (256, vector<char> ());
	vector< vector<char> > adja     (256, vector<char> (256, 0));
	//
	set<char> difchar;
	difchar.insert(S[0]);
	for(int i = 1; i < S.length(); i++) {
		difchar.insert(S[i]);
		if(adja[S[i-1]][S[i]] == 0) {
			if(edgelist[S[i-1]].size() + edgelist[S[i]].size() >= 2) {
				cout << "NO\n";
				return;
			}
			adja[S[i-1]][S[i]] = adja[S[i]][S[i-1]] = 1;
			edgelist[S[i-1]].push_back(S[i]);
			edgelist[S[i]].push_back(S[i-1]);
		}
	}
	//
	lastchar = '.';
	vector<int> check (256, 0);
	dfs(*difchar.begin(), check, edgelist);
	//
	dc = difchar.size();
	answerfound = false;
	fill(check.begin(), check.end(), 0);
	dfs2(lastchar, check, edgelist);
	//
	for(char c = 'a'; c <= 'z'; c++) {
		if( difchar.find(c) == difchar.end() ) cout << c;
	}
	cout << endl;
}

int main() {
	int t;
	for(cin >> t; t; t--) {
		solve();
	}
}
