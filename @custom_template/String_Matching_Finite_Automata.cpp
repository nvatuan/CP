
class String_Automata {
	string __alphabet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
	vector< vector<int, int> > __table;
	// --
	String_Automata(string S) {
		__table = vector (S.length() + 1, vector<int> (__alphabet.length(), 0));
		//
		for(
	}
	String_Automata(string S, string alphabet) {
		__alphabet = alphabet;
		String_Automata(S);
	}
	//
};




/*

   aaabba

[b] 0  0  0  4  5  0  |
[a] 1  2  3  3  1  6  |
[ ][0][1][2][3][4][5][6][7][8]



*/
