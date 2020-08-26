#include <bits/stdc++.h>
using namespace std;

int s, g;

#define _ADD 	1
#define _MINUS 	2
#define _MUL 	3
#define _DIV	4
#define _INSERT 5
#define _REMOVE	6
#define	_NEG	7
#define	_SUMDIG	8
#define _REVERSE 9

vector<string> button;
vector<int> f;
vector<int> v;

string givenButton;
void addOption(){
	
	//--
	if(givenButton.find("[+/-]") != string::npos){
		f.push_back(_NEG);
		v.push_back(0);
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[+") != string::npos){
		f.push_back(_ADD);
		v.push_back(givenButton[2] - '0');
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[-") != string::npos){
		f.push_back(_MINUS);
		v.push_back(givenButton[2] - '0');
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[x") != string::npos){
		f.push_back(_MUL);
		v.push_back(givenButton[2] - '0');
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[/") != string::npos){
		f.push_back(_DIV);
		v.push_back(givenButton[2] - '0');
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[<]") != string::npos){
		f.push_back(_REMOVE);
		v.push_back(0);
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[Sum]") != string::npos){
		f.push_back(_SUMDIG);
		v.push_back(0);
		button.push_back(givenButton);
	}
	else
	if(givenButton.find("[Reverse]") != string::npos){
		f.push_back(_REVERSE);
		v.push_back(0);
		button.push_back(givenButton);
	}
}

void bfs(){
	queue< pair<int, int> > q;
	queue< string > eachStep;
	//
	q.push({s, 0});
	eachStep.push("");
	//
	while(!q.empty()){
		int val = q.front().first;
		int step = q.front().second;
		string instruct = eachStep.front();
		//
		q.pop();
		eachStep.pop();
		//--
		if(val == g){
			//cout << step;
			cout << instruct;
			exit(0);
		}
		//--
		for(unsigned i = 0; i < f.size(); i++){
			switch(f[i]){
				case _ADD:
					q.push({val + v[i], step+1});
					eachStep.push(instruct + button[i] + ' ');
					break;
				case _MINUS:
					q.push({val - v[i], step+1});
					eachStep.push(instruct + button[i] + ' ');
					break;
				case _MUL:
					q.push({val * v[i], step+1});
					eachStep.push(instruct + button[i] + ' ');
					break;
				case _DIV:
					if(!(val % v[i]))
					{
						q.push({val / v[i], step+1});
						eachStep.push(instruct + button[i] + ' ');
					}
					break;
				case _INSERT:
					if(-1000 < val && val < 10000)
					{
						q.push({val * 10 + v[i], step+1});
						eachStep.push(instruct +  button[i] + ' ');
					}
					break;
				case _REMOVE:
					if(val != 0)
					{
						q.push({val / 10, step+1});
						eachStep.push(instruct +  button[i] + ' ');
					}
					break;
				case _NEG:
					if(val != 0){
						q.push({val * -1, step+1});
						eachStep.push(instruct +  button[i] + ' ');
					}
					break;
				case _SUMDIG:
					if(val != 0){
						int d = val;
						int sd = 0;
						while(d > 0){
							sd += (d%10);
							d /= 10;
						}
						//
						q.push({sd, step + 1});
						eachStep.push(instruct +  button[i] + ' ');
					}
					break;
				case _REVERSE:
					if(val != 0){
						int sign = (val < 0);
						int d = val;
						int rd = 0;
						while(d > 0){
							rd = rd*10 + (d%10);
							d /= 10;
						}
						if(sign) rd *= -1;
						q.push({rd, step + 1});
						//
						eachStep.push(instruct +  button[i] + ' ');
					}
					break;
				default:
					assert(0);
			}
		}
	}
}

int main(){
	cin >> s >> g;
	for(int times = 0; times < 9; times++){
		cin >> givenButton;
		addOption();
	}
	//--
	bfs();
}