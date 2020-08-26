#include <bits/stdc++.h>
using namespace std;

int n, m, k;

string s;
int st[10];

int main(){
	cin >> n;
	cin >> s;
	//--
	for(char c : s){
		if(c == 'L'){
			int i = 0;
			while(i < 10) 
				if( st[i] ) i++;
				else break;
			st[i] = 1;
		}
		if(c == 'R'){
			int i = 9;
			while(i > -1)
				if(st[i]) i--;
				else break;
			st[i] = 1;
		}
		if( '0' <= c && c <= '9' ){
			st[ c - '0' ] = 0;
		}
	}
	//--
	for(int i = 0; i <= 9; i++) cout << st[i];
}
