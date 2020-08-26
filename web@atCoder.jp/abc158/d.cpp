clude <bits/stdc++.h>
using namespace std;
 
#define rev(x) string(x.rbegin(), x.rend())
 
int main() {
	ios::sync_with_stdio(0);
	//
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	int qtype, f;
	char c;
	//
	bool is_rev = 0;
	string head = "";
	string tail = "";
	//
	while (Q--) {
		cin >> qtype;
		if (qtype == 1) {
			is_rev ^= 1;
		} else {
			cin >> f >> c;
			if ( !((f-1) ^ is_rev) ) {
				head += c;
			} else {
				tail += c;
			}
		}
	}
	//
	string Ans;
	if (is_rev) {
		Ans = rev(tail) + rev(S) + head;
	} else {
		Ans = rev(head) + S + tail;
	}
	cout << Ans << endl;
}