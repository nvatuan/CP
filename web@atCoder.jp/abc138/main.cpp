#include <bits/stdc++.h>
using namespace std;

int n;

string s, t;

int look[26][100001];

void initLookup(){
	for( int i = 0; i < 26; i++ ){
		int tmp = INT_MAX;
		for( int j = int(s.length()) - 1; j > -1; j-- ){
			if( s[j] - 'a' == i ) tmp = j;
			look[i][j] = tmp;
		}
	}
}

int check(long long len){
	int tmp = -1;
	for( int i = 0; i < int(t.length()); i++){
		tmp = look[t[i]-'a'][tmp+1];
		if(tmp == INT_MAX) len -= t.length(), tmp = -1;
	}
	len -= (tmp + 1);
	return (len >= 0);
}

int main(){
	cin >> s >> t;
	//
	initLookup();
	//--
	long long R = (100000LL*100000);
	long long L = t.length();
	//
	if( !check(R) ) {
		cout << "-1";
		return 0;
	}
	//
	while(L < R){
		long long mid = (L + R)/2;
		//
		if( check(mid) ){
			R = mid;
		} else {
			L = mid + 1;
		}
	}
	cout << R;
}
