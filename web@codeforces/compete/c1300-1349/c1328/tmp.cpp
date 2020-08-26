#include <bits/stdc++.h>
using namespace std;

template<typename T>
T In() {
	T x;
	cin >> x;
	return x;
}

template<typename T, typename U>
void Out(T x, U punc = " ") {
	cout << x << punc;
}

// ---------------------------------
int dif(vector<int> &t) {
	unordered_map<int, int> retype;
	int res = 0;
	for (int& i : t) {
		if ( !!retype[i] ) i = retype[i];
		else {
			res++;
			retype[i] = res;
			i = res;
		}
	}
	return res;
}
void solve() {
	int n = In<int>();
	vector<int> t (n);
	generate(t.begin(), t.end(), In<int>);
	//
	int d = dif(t);
	//
	set< pair<int, int> > check;
	vector< vector<int> > edgeList (d + 1, vector<int>());
	//
	for (int i = 0; i < n; i++) {
		int a = ((i-1)+n)%n;
		if( t[ ((i-1)+n)%n ] != t[i] and !check.count(make_pair(t[a], t[i])) ) {
			edgeList[ t[ ((i-1)+n)%n ]  ].push_back( t[i] );
			edgeList[t[i]].push_back( t[ ((i-1)+n)%n ] );
			check.insert(make_pair(t[a], t[i]));
			check.insert(make_pair(t[i], t[a]));
		}
		int b = (i+1)%n;
		if( t[ (i+1)%n ] != t[i] and !check.count(make_pair(t[b], t[i])) ) {
			edgeList[t[i]].push_back( t[ (i+1)%n ] );
			edgeList[ t[ (i+1)%n ] ].push_back( t[i] );
			check.insert(make_pair(t[b], t[i]));
			check.insert(make_pair(t[i], t[b]));
		}
	}
	//
	int maxCol = 1;
	unordered_map<int, int> ans;
	vector<int> vis (d + 1, 0);
	queue<int> q;
	for (int i = 1; i <= d; i++) {
		if ( !vis[i] ) {
			q.push(i);
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			//
			if (vis[node]) continue;
			vis[node] = 1;
			//
			set<int> colors;
			for (int adj : edgeList[node]) {
				if (vis[adj]) colors.insert(ans[adj]);
			}
			for (int cl = 1; true; cl++) {
				if( !colors.count(cl) ) {
					maxCol = max(maxCol, cl);
					ans[node] = cl;
					break;
				}
			}
			//
			for (int adj : edgeList[node]) {
				if (!vis[adj]) q.push(adj);
			}
		}
	}
	//
	cout << maxCol << "\n";
	for (int &i : t) cout << ans[i] << " ";
	cout << endl;
}
// ---------------------------------


int main() {
	for (int t = In<int>(); t; t--) solve();
}
