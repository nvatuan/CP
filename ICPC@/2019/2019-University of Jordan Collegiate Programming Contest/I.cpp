#include <bits/stdc++.h>
using namespace std;

void tokenize(string& s, vector<string>& tkns) {
    string num = "";
    for (char c : s) {
        if (c == '(' or c == ')') {
            if (num != "") {
                tkns.push_back(num);
                num = "";
            }
            tkns.push_back(string("") + c);
        } else {
            num += c;
        }
    }
}

int isnum(string s) {
    int poss = (s.length() > 0);
    for (char c : s) poss &= isdigit(c);
    return poss;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<string> tokens;
    tokenize(s, tokens);

    map<int, int> boss;
    stack<int> stk;
    int num;
    for (string tok : tokens) {
        if (isnum(tok)) {
            num = stoi(tok);
            if (! stk.empty()) {
                boss[num] = stk.top();
            }
            stk.push(num);
        } else {
            if (tok == "(") {
            } else {
                stk.pop();
            }
        }
    }
    for (int i=1; i<=n; i++) printf("%d ", boss[i]); printf("\n");
}