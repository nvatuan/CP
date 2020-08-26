#include <bits/stdc++.h>
#define FOR(i,a,b) for(long i=a; i<=b; i++)
#define BAC(i,a,b) for(long i=a; i>=b; i--)
#define br cout << endl
using namespace std;
typedef long long ll;

long long cube(long long n){
	return n*n*n;
}
long long n, mx = 0, nn, a, sum,  b, c;
long long aa[5];

long re(long n, long i){
	if(i == 1) return n;
	if(n%2) return(re(3*n+1,i-1))
	else return(re(n/2, i-1));
}

int main(){
	//freopen("input.txt","r", stdin);
	//freopen("output.txt","w",stdout);
	
	cin >> a >> b >> c;
	a*=a;
	b*=b;
	c*=c;
	if ((a + b > c) && (b + c > a) && (c + a > b)) 
		printf("YES");
	else printf("NO");
}
