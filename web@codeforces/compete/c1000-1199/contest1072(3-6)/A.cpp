#include <bits/stdc++.h>
using namespace std;

long gold;

int main(){
	int n, m, k;
	
	cin >> n >> m >> k;
	while(k > 0){
		k--;
		gold += (n*m) - (n-2)*(m-2);
		n-=4; m-=4;
	}
	cout << gold;
}