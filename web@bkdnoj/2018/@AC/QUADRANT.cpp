#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, state;
	string region[] = {"IV", "II", ":)", "III", "I"};
	cin >> x >> y;

	if(x*y > 0) state = 1;
	else state = -1;
	if(x > 0) state *= 2;
	cout << region[state + 2];

	return 0;
}