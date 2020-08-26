#include <bits/stdc++.h>
using namespace std;

bool isTwoSameSequences(std::vector<int> arr)
{
    vector<long long> sum ( arr.size() + 1, 0 );
    int index = 1;
    for(int x : arr) {
        sum[index] = sum[index - 1] + x;
        index++;
    }
    for(int i = 1; i < sum.size(); i++) {
        if( sum[i] == (*(sum.rbegin())-sum[i]) ) return true;
        //cout << sum[i] << ' ';
    }
    return false;
}


int main () {
    vector<int> v {1,2,5,-8};
    cout << isTwoSameSequences(v);
}