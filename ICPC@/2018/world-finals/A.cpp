#include <bits/stdc++.h>
using namespace std;

int n;

struct Art {
	int price	= -1;
	int height	= -1;
	int index	= -1;
	Art(int p, int h, int i) : price(p), height(h), index(i) {}
	// --
};


bool cmp (const Art& a, const Art& b) {
	if( a.price < b.price ) return 1;
	if( a.price > b.price ) return 0;
	return a.height < b.height;
}

void input(vector<Art> &a) {
	for(int x, i = 0; i < n; i++) {
		cin >> x;
		a[i].price = x;
		a[i].index = i;
	}
	for(int x, i = 0; i < n; i++) {
		cin >> x;
		a[i].height = x;
	}
}

void output(const vector<Art> &a) {
	for(int i = 0; i < n; i++) {
		cout << "Index = " << a[i].index << " | Price = " << a[i].price << " | Height = " << a[i].height << endl;
	}
}

int main() {
	cin >> n;
	vector<Art> A1 (n, Art(-1, -1, -1)), A2 (n, Art(-1, -1, -1));
	// --
	input(A1);
	input(A2);

//	cout << "Before sort\n";
//	output(A1);
//	output(A2);

	sort(A1.begin(), A1.end(), cmp);
	sort(A2.begin(), A2.end(), cmp);

//	cout << "After sort\n";
//	output(A1);
//	output(A2);
	// --
	set<int> replacement;
	int p1 = 0, p2 = 0;
	while( p2 < n ) {
		while( replacement.empty() || A1[p1].price == A1[p1-1].price) {
			replacement.insert(A1[p1].height);
			p1++;
		}
		while( !replacement.empty() ) {

		}
	}
}
