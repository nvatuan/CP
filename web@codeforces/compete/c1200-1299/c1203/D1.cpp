#include <bits/stdc++.h>
using namespace std;

string s, t;

int include(string S, int l, int L){
	S.erase(l, L);
	//
	int i = 0;
	int j = 0;
	while(i < S.length()){
		if(S[i] == t[j]) j++;
		i++;
		if(j == t.length()) return 1;
	}
	return 0;
}

int main(){
	cin >> s;
	cin >> t;
	//--
	int maxAns = 0;
	for(int l = 0; l < s.length(); l++){
		for(int L = 1; L <= int(s.length()) - l; L++){
			if( include(s, l, L) ) maxAns = max(maxAns, L);
		}
	}
	//
	cout << maxAns;
}
