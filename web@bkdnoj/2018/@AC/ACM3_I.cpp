#include <bits/stdc++.h>

using namespace std;

int main(){
	int h, m, s, c = 0;
	cin >> h >> m >> s;
	if(s == 59){
		s = 0;
		if(m == 59){
			m = 0;
			if(h == 23){
				h = 0;
			}
			else h++;
		}
		else m++;
	}
	else s++;
	
	cout <<h<<":"<<m<<":"<<s;
	return 0;
}