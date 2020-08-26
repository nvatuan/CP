#include <bits/stdc++.h>
using namespace std;

int main(){
	int e[3];
	cin >> e[0] >> e[1] >> e[2];
	sort(e, e+3);
	if(e[0]+e[1]>e[2]) cout << 0;
	else cout << (e[2]-(e[1]+e[0])+1);
}