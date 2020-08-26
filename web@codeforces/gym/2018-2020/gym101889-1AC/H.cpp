#include <bits/stdc++.h>
using namespace std;

int a[3], r[3];

int main(){
	int unsatified = 0;
	cin >> a[0] >> a[1] >> a[2];
	cin >> r[0] >> r[1] >> r[2];
	for(int i = 0; i < 3; i++){
		if(a[i] < r[i]) unsatified += r[i]-a[i];
	}
	cout << unsatified;
}