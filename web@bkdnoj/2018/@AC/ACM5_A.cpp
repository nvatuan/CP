#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define BAC(i, b, a) for(i = b; i >= a; i--)
#define br cout << endl

using namespace std;

bool bomb[1001];
int ans;

int main(){
	int n, r;
	//int a[1000];

	int i, k;

	cin >> n >> r;
	//FOR(i, 1, n) {cin >> a[i]; bomb[a[i]] = true;}
	FOR(i, 1, n) {cin >> k; bomb[k] = true;}

	//
	//sort(a, a+n+1);
	int pointer = 0;
	while( pointer <= 1000 ){
		if(bomb[pointer]){
			BAC(i, pointer+r, pointer+1)//-r)
				if((0 < i) && (i < 1001))
					if(bomb[i]){
						pointer = i + r;	
						break;
					}
			ans++;
		}
		pointer++;
	}
	
	cout << ans;
}