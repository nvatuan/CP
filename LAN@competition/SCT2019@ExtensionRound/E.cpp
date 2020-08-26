#include <bits/stdc++.h>
using namespace std;

string st;

int minDup = 1;

int check(int jump){
	for(unsigned i = 0; i < st.length(); i += jump){
		int subDup = 1;
		for(unsigned p = 1; p < jump; p++){
			if(i+p >= st.length()) return 1;
			if(st[i+p] == st[i]) subDup++;
			if(subDup > (jump/7)) return 0;
		}
	}
	return 1;
}

int main(){
	cin >> st;
	//
	for(int N7 = 1; ;){
		if(check(N7 * 7)){
			cout << N7*7;
			return 0;
		}
		else{
			N7++;
		}
	}
}