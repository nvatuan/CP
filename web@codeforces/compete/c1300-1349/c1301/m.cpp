#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
	string instruct = "";
	//
	cin >> m >> n >> k;
	if( k > (4*n*m - 2*n - 2*m) ) {
		cout << "NO\n";
	} else {
		vector< vector<int> > Mt ( n+2, vector<int> (m+2, 1));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				Mt[i][j] = 0;
		string Ins = "RDLU";
		vector<int> dx = {1, 0, -1, 0};
		vector<int> dy = {0, 1, 0, -1};
		int iidx = 0;
		//
		int trav = 1;
		int x = 1, y = 1;
		//
		Mt[x][y] = 1;
		while(k) {
			if(trav == (n*m)) break;
			//
			if( Mt[x+dx[iidx]][y+dy[iidx]] ) {
				iidx = (iidx + 1) % 4;
			} else {
				instruct += Ins[iidx];
				trav++;
				Mt[x+dx[iidx]][y+dy[iidx]] = 1;
				k--;
				x += dx[iidx];
				y += dy[iidx];
			}
		}
		//
		map<char, char> rvr {
			{'R', 'L'}, {'L', 'R'},
			{'U', 'D'}, {'D', 'U'}
		};
		int ridx = instruct.length() - 1;
		while(k) {
			instruct += rvr[instruct[ridx]];
			ridx--;
			k--;
			//
			if(ridx == -1) {
				cerr << "k is too large!!\n";
				assert(false);
			}
		}
		//
		instruct += "?";
		// -- Path compression
		cout << "YES\n";
		queue<string> printings;
		//
		char cur = instruct[0];
		int rep = 1;
		for(int i = 1; i < instruct.length(); i++) {
			if(instruct[i] == cur) {
				rep++;
			} else {
				//printf("%d %c\n", rep, cur);
				printings.push(to_string(rep) + " " + cur + "\n");
				cur = instruct[i];
				rep = 1;
			}
		}
		//
		printf("%d\n", printings.size());
		while(!printings.empty()) {
			cout << printings.front();
			printings.pop();
		}
	}
}
