#include <bits/stdc++.h>
#define BAC(i, b, a) for(i = b; i >= a; i--)
using namespace std;

long long fib(int n){
	if(n == 1) return 1;
	if(n == 2) return 1;
	else return( fib(n-1) + fib(n-2) );
}


void bignumMul(int n, int exp){
	int cell_size = 1000000, la = 99;
	long long bn[100] = {0};

	int ie, ie2;
	int i, j;
	int st = 99;
	long long carry = 0;

	bn[la] = n;
	//
	while(exp > 1){
		carry = 0;
		
		BAC(j, la, st){
			carry = bn[j] * n + carry;
			//cout << carry <<endl;
			bn[j] = carry%cell_size;
			carry /= cell_size;
		}

		if(carry != 0){
				st--;
				bn[st] = carry;
		}
		exp--;
	}

	cout << bn[st];
	for(i = st+1; i <= la; i++){
		ie = cell_size/10;
		while(ie > 0){
			if(bn[i] < ie) cout << 0;
			ie /= 10;
		}
		cout << bn[i];
	}
}


int main(){
	//long long f;
	int n;
	cin >> n;
	//for(n = 1; n < 26; n++){
	//	cout << n <<": ";
		bignumMul(fib(n), n);
	//	cout << endl;
	//}

	/* hu hu code ngu qua
	while(n > 0){
		st--;
		bn[st] = n % cell_size;
		n /= cell_size;
	}
	//ie = exp%2;
		//ie2 = (exp+1)%2;

		//for(i = st; i <= la; i++) cout << '['<<bn[ie][i]<<"] ";
		//cout << bn[ie][9];
		//cout << endl;

		/*BAC(i, la, st){
			BAC(j, la, st){
				carry = bn[ie][i] * bn[ie][j] + carry;
				//cout << carry <<endl;
				bn[ie2][j] += carry%cell_size;

				carry /= cell_size;
			}
			if(carry != 0){
				st--;
				bn[ie2][st] = carry;
			}
		}
		}
		i = 9;
	*/
}