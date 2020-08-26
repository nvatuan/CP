#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	int d[7] = {0, 6, 5, 4, 3, 2, 1};
	cin >> n;
	cout << (n/6+d[n%6]) << ' ' << (n*6);
}