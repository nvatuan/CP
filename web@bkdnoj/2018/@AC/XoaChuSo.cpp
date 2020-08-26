#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define BAC(i, a, b) for(i = a; i >= b; i--)
#define br cout << "\n"

using namespace std;

string digits;
int k, i, st = 0;
bool selc[100000];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w+", stdout);
	cin >> digits;
	cin >> k;
	int i = 0, j = 0, maxd, maxid;
	int l = digits.size();

	while(i < l){
		maxd = digits[i];
		maxid = i;
		FOR(j, i, i+k){ 
			if(maxd < digits[j]){ maxd = digits[j]; maxid = j;} 
		}

		cout << maxd-'0';
		k -= (maxid - i);
		i = maxid + 1;
	}
	//wtf ko TLE a???? 10**5 * 5 * 10**4 trong 1s
}