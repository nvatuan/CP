#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long (i) = (a); (i)<=(b); (i)++)
#define br cout << "\n"
using namespace std;
typedef long long ll;

ll la, ra, ta, lb, rb, tb;
ll MAX;

ll ka, kb;

ll cy = 1e8;

ll overlap(){
	ll lla = la + ta*ka;
	ll rra = ra + ta*ka;
	ll llb = lb + tb*kb;
	ll rrb = rb + tb*kb;

	return (min(rra, rrb) - max(lla, llb) + 1);
}


int main(){
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;

	while(cy-- > 0){
		MAX = max(MAX, overlap());
		if((la+ta*ka < lb+tb*kb)&&(ra+ta*ka < rb+tb*kb)){ 
			//ka += min( min( ((lb-la)/ta), ((rb-ra)/ta) ), 1); 
			ka++;
		}
		else if((lb+tb*kb < la+ta*ka)&&(rb+tb*kb < ra+ta*ka)){
				//kb += min( min( ((la-lb)/tb), ((ra-rb)/tb) ), 1); 
				kb++;
			} else if(ta > tb) ka++;
				   else kb++;
	}	
	cout << MAX;
}