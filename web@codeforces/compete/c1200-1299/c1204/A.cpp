#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	string t = "1";
	int ans = 0;
	while(t.length() + 2 <= s.length()){
		ans++;
		t += "00";
	}
	if(s.length() == t.length()) ans += (s > t);
	if(s.length() > t.length()) ans++;
	cout << ans;
}
