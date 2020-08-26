#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define BAC(i, a, b) for(int i = a; i >= b; i--)
using namespace std;

int n;
long long ans;
int bigdp[251][1001];

int CELL = 1000000;
int LAST_IND = 1000;

void addBig(int des, int s1, int s2){
	int l1 = max(bigdp[s1][0], bigdp[s2][0]);
	//int l2 = min(bigdp[s1][0], bigdp[s2][0]);

	int carry = 0;
	bigdp[des][0] = -1;
	FOR(i, 0, l1){
		carry = bigdp[s1][LAST_IND - i] + bigdp[s2][LAST_IND - i] + carry;
		bigdp[des][0]++;
		bigdp[des][ LAST_IND - bigdp[des][0] ] = carry % CELL;
		carry = carry / CELL;
	}
	if(carry != 0){ bigdp[des][0]++; bigdp[des][ LAST_IND - bigdp[des][0] ] = carry; }
}

void presentBig(int index){
	int l = bigdp[index][0];
	long tmp;

	cout << bigdp[index][LAST_IND - l];

	BAC(i, l-1, 0){
		int c = CELL/10;
		tmp = bigdp[index][LAST_IND - i];
		while(tmp < c){
			cout << 0;
			c /= 10;
		}
		if(tmp > 0) cout << tmp;
	}
}

int main(){
	cin >> n;
	bigdp[0][0] = 0; bigdp[0][LAST_IND] = 1;
	bigdp[1][0] = 0; bigdp[1][LAST_IND] = 1;

	for(int i = 2; i <= n; i++){
		addBig(i, i-1, i-2);
		//cout << "\n";
		addBig(i, i, i-2);
		//dp[i] = (dp[i-1]) + dp[i-2]*2;
		//presentBig(i); cout << "\n";
	}
	presentBig(n);
}