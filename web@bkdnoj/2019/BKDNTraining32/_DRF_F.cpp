#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define BAC(i, b, a) for(i = b; i >= a; i--)
#define br cout << "\n"
using namespace std;

string k, h;
int l, rk, rh;
int lenk, lenh;
int sd, md;
int ai = 1, aj = 1;

void squeeze(){
	int i, j;
	rk = lenk;
	rh = lenh;
	l = -1;

	do{
		l++;
	} while(k[l] == h[l]);
	do{
		rk--;
		rh--;
	} while(k[rk] == h[rh]);

	if(l > rh){ l--; }

	FOR(i, l, rk) sd += (k[i] - '0');
	FOR(i, l, rh) md = md*10 + (h[i] - '0');

	if(sd == md){ ai = l; aj = rk;}
	//3 cases:
	//

	int tmp1 = 0, tmp2 = 0, exp101 = 1;
	int tmp11 = 0, tmp22 = 0, exp102 = 0;
	int expconst = 1;
	while( expconst <= md ) {expconst *= 10;}
	
	FOR(j, 0, 3){
		if(j>0){
			if(j <= l){
				tmp1 = tmp1 + (k[rk+j] - '0');
				tmp2 = tmp2*10 + (h[rh+j] - '0');
				exp101 *= 10;
				if((sd+tmp1) == (md*exp101+tmp2)) { ai = l; aj = rk+j; }
			}
		}
		//LEFT
		tmp11 = 0, tmp22 = 0, exp102 = expconst;
		FOR(i, 1, 3){
			if(i <= l){
				tmp11 = tmp11 + (k[l-i] - '0');
				tmp22 = (h[l-i] - '0')*exp102 + tmp22;
				exp102 *= 10;
				if((sd+tmp11) == (tmp22+md)) { ai = l-i; aj = rk+j; }
			}
		}

	}
	//
	//
}

int main(){
	getline(cin, k);
	getline(cin, h);
	lenk = k.length();
	lenh = h.length();

	if(k == h) cout << "1 1";
	else{
			squeeze();
			cout << ai << " " << aj;
		}
}