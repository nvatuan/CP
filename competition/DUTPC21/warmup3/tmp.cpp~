#include <bits/stdc++.h>
using namespace std;

int n;

const int N = 200000;
int a[N];
int bit[N];

void update(int x, int v) {
	for (; x<N; x += (x & (-x))) bit[x] += v;
}

int query(int x) {
	int rs=0;
	for (; x>0; x -= (x & (-x))) rs += bit[x];
	return rs;
}

int main() {
	cin >> n;
	int ans=0;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		ans += query(x-1);
		update(x, 1);
	}
	cout << ans << endl;
}
