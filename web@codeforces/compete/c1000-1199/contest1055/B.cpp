#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long (i) = (a); (i)<=(b); (i)++)
#define br cout << "\n"
using namespace std;
typedef long long ll;

ll n, m, l, p, g;
ll hair[100001];
ll sec;
bool higher[100002];

bool t;

int main(){
	cin >> n >> m >> l;
	FOR(i, 1, n) {
		cin >> hair[i];
		higher[i] = (hair[i] > l);
		if(!higher[i-1]) sec += (hair[i] > l);
	}

	while(m-- > 0){
		cin >> t;
		if(t){
			cin >> p >> g;
			hair[p]+=g;

			if(!higher[p]){
				if (hair[p] > l){
					if(!((higher[p-1])||(higher[p+1]))){
						sec++;
					}
					if(((higher[p-1])&&(higher[p+1]))){
						sec--;
					}
					higher[p] = true;
				}
			}	
		}
		else{
			cout << sec;
			br;
		}
	}
}