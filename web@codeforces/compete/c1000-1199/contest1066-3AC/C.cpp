#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
#define BAC(i,a,b) for(i=a; i>b; i--)
#define br cout << endl
using namespace std;

long shelf[2][200001], i, j;
long l1, r1;
long LR[200001], ADL[200001], ADR[200001];

int main(){
	long q, id;
	char c;
	long ins, ous;
	cin >> q;
	l1 = 1; r1 = 1;

	while(q > 0){
		q--;
		cin >> c;
		cin >> id;
		switch(c) {
			case 'L':	shelf[1][l1] = id;
						LR[id] = 1;
						ADL[id] = l1;
						l1++;
						break;
			case 'R':	shelf[0][r1] = id;
						LR[id] = 0;
						ADR[id] = r1;
						r1++;
						break;
			case '?':	if(LR[id]){ //left
							ins = l1 - ADL[id] - 1;
							ous = ADL[id] + r1 - 2;
							if(ins < ous){
								cout << ins;
								//l1 = ADL[id]+1;
							}
							else{
								cout << ous;
								//r1 = 1;
							}
							br;
						}
						else{ //right
							ins = r1 - ADR[id] - 1;
							ous = ADR[id] + l1 - 2;
							if(ins < ous){
								cout << ins;
								//r1 = ADR[id]+1;
							}
							else{
								cout << ous;
								//l1 = 1;
							}
							br;
						}
		}
	}
}