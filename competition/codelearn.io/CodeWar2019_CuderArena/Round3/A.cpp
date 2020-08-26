#include <bits/stdc++.h>
using namespace std;

std::string digitalNumber(std::vector<std::string> lightStatus)
{
    unordered_map<int, char> hax = {
        {0b111101101101111, '0'},
        {0b001001001001001, '1'},
        {0b111001111100111, '2'},
        {0b111001111001111, '3'},
        {0b101101111001001, '4'},
        {0b111100111001111, '5'},
        {0b111100111101111, '6'},
        {0b111001011001001, '7'},
        {0b111101111101111, '8'},
        {0b111101111001111, '9'}
    };
    //
    string res = "";
    int i = 0, j = 0;
    //
    int dig = 0;
    //
    while( dig*3 < int(lightStatus[0].size()) ) {
        int subhax = 0;
        //
        for(i = 0; i < 5; i++) {
            for(j = 0; j < 3; j++){
                subhax <<= 1;
                subhax |= (lightStatus[i][j + dig*3] == '*');
            }
        }
        res += hax[subhax];
        dig++;
        //
    }
    //
    return res;
}

int main() {
    std::vector<std::string> lightStatus = {"***************","*.*..**..*.**..","*.*************","*.*..**.**.**.*","***************"};
    cout << digitalNumber(lightStatus);
}