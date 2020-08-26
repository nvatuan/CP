#include <bits/stdc++.h>
using namespace std;


int main(){
	string input;
	getline(cin, input);
	//input = "a b c d e f g h i j";
	input += ' ';
	//
	//cout << input.substr(0, input.length());
	
	int i, st = 0, index = 0;
	string d[10];
	for(i = 0; i < input.length(); i++){
		if(input[i] == ' '){
			d[index] = input.substr(st, i-st+1);
			index++;
			st = ++i;
		}
	}

	//for(i = 0; i < 10; i++) cout << d[i] << endl;

	int n, num;

	cin >> n;
	for(i = 0; i < n; i++){
		cin >> num;
		input = "";

		do{
			if(input.compare(d[num % 10]) < 0){
				input = d[num % 10];
			}
			num /= 10;
		} while(num > 0);
		cout << input << endl;
	}
	return 0;
}