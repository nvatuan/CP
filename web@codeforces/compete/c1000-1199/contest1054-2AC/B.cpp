#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define BAC(i, a, b) for(int i = a; i >= b; i--)


using namespace std;

int main(){
	int n, tmp;
	int step = 0;
	int expected = 0;
	
	cin >> n;
	FOR(i, 1, n){
		step++;
		cin >> tmp;
		if(tmp == expected) expected++;
		else if (tmp > expected) {cout << step; return 0;}
	}
	cout << "-1";
}