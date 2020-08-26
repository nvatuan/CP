#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<long long> a (11);
//--
vector<long long> s (11);
vector<long long> bags(11, 0);
//--

int sameVect(vector<long long> a, vector<long long> b){
	// for(auto k : b) cout << k << ' ';
	// cout << endl;
	//
	if(a.size() == b.size()){
		//sort(a.begin(), a.end()); 
		// -- Vector a is already sorted
		//sort(b.begin(), b.begin() + k);
		//
		for(int i = 0; i < k; i++){
			if(a[i] != b[i]) return 0;
		}
		//
		return 1;
	}
	return 0;
}

void Try(int indx){
	if(indx == n){
		if(sameVect(s, bags)) {
			cout << "YES";
			exit(0);
		}
	}
	else{
		for(int b = 0; b < k; b++){
			if(bags[b] + a[indx] <= s[b]){
				bags[b] += a[indx];
				Try(indx + 1);
				bags[b] -= a[indx];
			}
		}
	}
}

int main(){
	//clock_t now = clock();
	//=========
	//
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < k; i++) {
		cin >> s[i]; //assert(s[i] != 0);
		//if(s[i] <= 0) {cout << "NO"; return 0;}
	}
	sort(a.begin(), a.begin() + n);
	sort(s.begin(), s.begin() + k);
	// --
	Try(0);
	cout << "NO";
	//=========
	//cout << endl << float(clock() - now)/CLOCKS_PER_SEC << 's';
}