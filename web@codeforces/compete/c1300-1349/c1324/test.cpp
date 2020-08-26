#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> V {3, 3, 4, 4, 5, 6, 7};
	cout << upper_bound(V.begin(), V.end(), 4) - V.begin() << endl;
	cout << upper_bound(V.begin(), V.end(), 2) - V.begin() << endl;
	cout << upper_bound(V.begin(), V.end(), 8) - V.begin() << endl;
}
