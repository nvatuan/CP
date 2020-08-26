#include <bits/stdc++.h>
using namespace std;

string S;
string Bs;

void BitsForm(){
	Bs = "";
	for(char c : S)
		if(c == 'B') Bs += '1';
		else Bs += '0';
}
//--
unsigned long long Min = ULLONG_MAX, Max = 0;

unsigned long long num, newNum;
unsigned BITS;

void updateAns(){
	Max = max(Max, newNum);
	Min = min(Min, newNum);
}

inline void cyclicShiftandCheck(bitset<30> Bin){
	num = (Bin.to_ullong() & ((1 << BITS) - 1));
	//--
	for(unsigned K = 0; K < BITS; K++){
		newNum = ( (num << (K)) | (num >> (BITS-K)) ) & ((1 << BITS) - 1);
		updateAns();
		//
		//cout << newNum << endl;
	}
}

//--
int main(){
	cin >> S;
	BITS = S.length();
//==================================================================
	{
		BitsForm();
		bitset<30> Bin (Bs);
		//--
		cyclicShiftandCheck(Bin);
		Bin.flip();
		cyclicShiftandCheck(Bin);
	}
//==================================================================
	//-- Reverse S;
	reverse(S.begin(), S.end());
//==================================================================
	{
		BitsForm();
		bitset<30> Bin (Bs);
		//--
		cyclicShiftandCheck(Bin);
		Bin.flip();
		cyclicShiftandCheck(Bin);
	}
//==================================================================
	cout << Min << ' ' << Max;
}