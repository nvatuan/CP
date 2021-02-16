#include <bits/stdc++.h>
using namespace std;

int main() {   
    map<int, int> M;
    int rotate = 1;
    for (int i = 0; i < (int)(1e6); i++) {
        M[rotate]++;
        rotate = (rotate > 100000 ? 1 : rotate + 1);
    }

    cout << "a";
}