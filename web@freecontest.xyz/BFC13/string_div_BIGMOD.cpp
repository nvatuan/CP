#include <bits/stdc++.h>
using namespace std;

string A, B;
long long a, b;
long long M;

pair<string, int> div2(string C) {
    int n = C.length();

    long long r = 0;
    
    string res = "";

    int counter = 0;

    for(int i = 0; i < n; i++) {
        r = r*10 + (C[i] - '0');
        counter++;
        //
        if(counter == 10 || i + 1 == n) {
            string divRes = to_string(r / 2);
            if(res.length() > 0) {
                res += string (counter - divRes.length(), '0');
            }
            res += divRes;
            r = r%2;
            counter = 0;
        }
    }

    pair<string, int> p = {res, r};
    return p;
}

long long powMod(long long base, string exp) {
    if(exp == "0") return 1;
    if(exp == "1") return base % M;
    
    string chop;
    int remainFlag;

    pair<string, int> p = div2(exp);

    chop = p.first;
    remainFlag = p.second;
    
    if(remainFlag)
        return powMod(base*base % M, chop) % M * base % M;
    else
        return powMod(base*base % M, chop) % M;
}

int main() {
    cin >> A >> B;
    cin >> M;
    //
    for(int i = 0; i < int(A.length()); i++) {
        a = a * 10 + (A[i] - '0');
        a %= M;
    }
    //
    cout << powMod(a, B);
}