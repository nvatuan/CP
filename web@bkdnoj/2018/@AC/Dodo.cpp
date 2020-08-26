#include <bits/stdc++.h>
using namespace std;

int letters[26];

int main(){
	string a;

	cin >> a;
	int l = a.length();
	for(int i = 0; i < l; i++) letters[a[i]-'a']++;

	cin >> a;
	l = a.length();
	for(int i = 0; i < l; i++) letters[a[i]-'a']--;

	int ans = 0;
	for(int i = 0; i < 26; i++) ans += abs(letters[i]);
	cout << ans;
}