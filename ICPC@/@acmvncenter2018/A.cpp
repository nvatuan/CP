#include <bits/stdc++.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
#define BAC(i,a,b) for(i=a; i>b; i--)
#define br cout << endl
using namespace std;

int main(){
	long x1, x2, y1, y2, x3, y3;
	double t1, tc;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if(x2 == x1){
		if(x3 == x2) cout << "TOWARDS";
		else if(x3 > x2) cout << "RIGHT";
			 else cout << "LEFT";
	}
	else{
			t1 = (y2-y1)/(x2-x1);
			tc = (y3-y2)/(x3-x2);
			
			if(t1 == tc) cout << "TOWARDS";
			else //same sign
				if(tc*t1 > 0){
					if(t1 > tc) cout << "RIGHT";
					else cout << "LEFT";
				}
				else{
					if(t1 > tc) cout << "LEFT";
					else cout << "RIGHT";
				}
		}
}