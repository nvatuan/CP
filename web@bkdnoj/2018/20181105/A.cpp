#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long (i) = (a); (i) <= (b); (i)++)
#define BAC(i, a, b) for(long long (i) = (a); (i) >= (b); (i)--)
#define br cout << "\n"
using namespace std;
typedef long long ll;

//unsigned long long pow2[65];
long long answer[1000001];

bool sv[1000001];
bool svsq[1000001];
long long p[78500];
int primes;

void siev(){
	sv[1] = true;

	FOR(i, 2, 1000000){
		if(!sv[i]){
			
			FOR(j, (i*i), 1000000){
				sv[j] = true;
				j+=(i-1);
			}
		}
		//cout << i; br;
	}

	primes = 1;
	FOR(i, 2, 1000000){
		if(!sv[i]){
			p[primes++] = i;
		}
	}
	primes--;
	FOR(i, 2, 1000) svsq[i*i] = true;
}

int divisors(ll n){
	long long ans = 1;
	if(n == 1) return 1;

	int i = 0;
	int count;

	while(++i){
		if(p[i]*p[i]*p[i] > n) break;

		count = 1;

		while(n % p[i] == 0){
			cout << p[i] << " ";
			n /= p[i];
			count++;
		}

		ans = ans*count;
	}	

	if(!sv[n]) ans = ans*2;
	else if(svsq[n]) ans = ans*3;
		 else if(n!=1) ans = ans*4;

	return ans;
}

int main(){
//	ios::sync_with_stdio(0); cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	int T;

	siev();
	//cout << "???";
	cin >> n;
	while(!!n){
		T = divisors(n);
		cout << " = " << T; br;
		cin >> n;
	}

	/*pow2[0] = 1;
	FOR(i, 1, 64) pow2[i] = pow2[i-1]*2;
	br;

	FOR(i, 1, 64) cout << (pow2[i]-1) << ", ";
	
	testn[1] = 0;
	FOR(i, 2, 64){
		testn[i] = testn[i-1];

		FOR(j, 1, i-1){
			if( !((pow2[i]-1)%(pow2[j]-1)) ) testn[i]++;
		}
	}*/

	answer[0] = 1;
	//FOR(i, 1, 1000000)	if(svsq[i]) cout << i << " ";
	FOR(i, 1, 1000000) answer[i] = divisors(i)-1;
	FOR(i, 2, 1000000) answer[i] = answer[i]+answer[i-1];
	//FOR(i, 1, 64) cout << answer[i] << " ";

	cin >> T;
	while(T-- > 0){
		cin >> n;
		cout << (answer[n]);
		br;
	}

}
