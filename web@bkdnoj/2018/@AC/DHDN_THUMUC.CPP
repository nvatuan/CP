#include <bits/stdc++.h>
using namespace std;

int main(){
	int i;
	string s;
	getline(cin, s);
	for(i = 0; i <= s.length(); i++) if(s[i]!='/'){cout << '/'; break;}
	for(i = i; i < s.length(); i++)
		if(!(s[i]=='/')||((s[i+1]!='/')&&(i+1<s.length()))) cout << s[i];
}