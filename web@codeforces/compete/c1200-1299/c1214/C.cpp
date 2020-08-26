#include <bits/stdc++.h>
using namespace std;

int n;
string brackets;

int equalType() {
    int open = 0, close = 0;
    for(char c : brackets) {
        open    += (c == '(');
        close   += (c == ')');
    }
    return (open == close);
}

int validMinState(){
    int minstate = 0;
    int state = 0;
    unordered_map<char, int> br { {'(', 1}, {')', -1} };
    for(char c : brackets) {
        state += (br[c]);
        minstate = min(minstate, state);
    }
    return (minstate >= -1);
}

int main() {
    cin >> n;
    cin >> brackets;
    //
    if( equalType() ) {
        if(validMinState()) {
            cout << "Yes";
            return 0;
        }
    } 
    cout << "No";
    return 0;
}