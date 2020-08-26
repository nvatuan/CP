#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define BAC(i, b, a) for(i = b; i >= a; i--)
#define br cout << "\n"
using namespace std;

string s;
string lname, mname, fname, smney;
long stm , lsm;
long i;

void capitalise(){
	long l = lname.length()-1;
	FOR(i, 0, l)
		if(lname[i] <= 'Z') lname[i] += ('a'-'A');
	lname[0] -= ('a'-'A');

	l = mname.length()-1;

	if(mname[0] >= 'a') mname[0] -= ('a'-'A');
	FOR(i, 1, l)
		if(mname[i] != ' '){
			if((mname[i] <= 'Z')&&(mname[i-1] != ' ')){
				mname[i] += ('a'-'A');
			}
			if((mname[i] >= 'a')&&(mname[i-1] == ' ')){
				mname[i] -= ('a'-'A');
			}
		}

	l = fname.length()-1;
	FOR(i, 0, l)
		if(fname[i] <= 'Z') fname[i] += ('a'-'A');	
	fname[0] -= ('a'-'A');
} 

bool isChar(char c){
	return (((c>='a')&&(c<='z')) || ((c>='A')&&(c<='Z'))) ;
}

int main(){
	getline(cin, s);
	long l = s.length();

	//lowercap();
	FOR(i, 0, l-1){
		if((s[i]>='A')&&(s[i]<='Z')) s[i] += ('a'-'A');
	}

	FOR(i, 0, l-1) 
		if(s[i] == ' ') {fname = s.substr(0, i); break;}
		
		FOR(i, i+1, l-1)
			if( isChar(s[i])) { stm = i; break; }

	BAC(i, l-1, 0)
		if(s[i] == ' ') {smney = s.substr(i+1, l-i-1); break;}
	
		BAC(i, i-1, 0)
			if( isChar(s[i]) ){ lsm = i; break; }

	BAC(i, lsm, 0)
		if(s[i] == ' ') {lname = s.substr(i+1, lsm-i); break;}
	lsm = i-1;

	mname = s.substr(stm, lsm-stm+1);

	capitalise();
	cout << lname; br;
	cout << fname; br;
	
	l = (mname.length()-1);
	FOR(i, 0, l ){
		if(mname[i] == ' ')
			{if( isChar(mname[i+1]) ) cout << ' ';}
		else cout << mname[i];
	}
	br;

	cout << smney;
}