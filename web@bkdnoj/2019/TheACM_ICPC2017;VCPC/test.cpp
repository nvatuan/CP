#include <bits/stdc++.h>
using namespace std;

int main(){

	int T = 1;
	long long S = 1, i = 1;
	char c;
	string sx = "1";

	cout << "i runs from 1 to 7: " <<endl;
	while(i <= 7){
		cout << "With i =" << i << endl;
		cout << "   " << "T = " << T << " + S " << " * " << (i*2-1) << " * " << (i*2) <<endl;
		cout << "  -> With S equal to: " << sx;

		S = S*(i*2-1)*(i*2);
		T = T + S;

		c = i*2 + 48;

		sx = sx + " * " + c + " * " + (char) (c-1) ;
		i++;
		cout << endl;
	}
}