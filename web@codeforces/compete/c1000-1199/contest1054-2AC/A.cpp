#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define BAC(i, a, b) for(int i = a; i >= b; i--)


using namespace std;

int main(){
	int x, y, z, t1, t2, t3;
	int elevator, stairs;

	cin >> x >> y >> z >> t1 >> t2 >> t3;

	stairs = abs(x - y) * t1;
	elevator = abs(z - x)*t2 + abs(x-y)*t2 + t3*3;

	if(elevator > stairs) cout << "NO";
	else cout << "YES";
}