#include <bits/stdc++.h>
using namespace std;

bool isValidPassword(std::string pass)
{
    int valid = 1;
    int lowercaseCount, uppercaseCount, digitsCount, specialCount;
       // -- check length
        valid &= ((6 <= pass.length()) && (pass.length() <= 12));
    
       // -- count lowercase letters
        lowercaseCount = 0;
        for(char c : pass) lowercaseCount += ('a' <= c && c <= 'z');
        valid &= ((1 <= lowercaseCount)&&(lowercaseCount <= 4));
    
       // -- count uppercase letters
        uppercaseCount = 0;
        for(char c : pass) uppercaseCount += ('A' <= c && c <= 'Z');
        valid &= ((1 <= uppercaseCount)&&(uppercaseCount <= 4));
    
       // -- count digits
        digitsCount = 0;
        for(char c : pass) digitsCount += ('0' <= c && c <= '9');
        valid &= ((1 <= digitsCount)&&(digitsCount <= 4));
    
       // -- count special characters
        std::unordered_map<char, int> specialMap {
            {'!', 1}, {'@', 1},
            {'#', 1}, {'$', 1},
            {'%', 1}, {'^', 1},
            {'&', 1}, {'*', 1},
            {'(', 1}, {')', 1} 
        };
        specialCount = 0;
        for(char c : pass) specialCount += specialMap[c];
        valid &= (specialCount == 1);
    
       // -- check for total numbers (detect other characters)
        valid &= (pass.length() == (lowercaseCount + uppercaseCount + digitsCount + specialCount));
    
       // -- check for positional condition
        // -- 3 consecutive lowercase char is not allowed
        for(int i = 0; i < pass.length()-2; i++) {
            valid &= !(
                ('a' <= pass[i] && pass[i] <= 'z') &&
                ('a' <= pass[i+1] && pass[i+1] <= 'z') &&
                ('a' <= pass[i+2] && pass[i+2] <= 'z')
            );
        }
        // -- 3 consecutive uppercase char is not allowed
        for(int i = 0; i < pass.length()-2; i++) {
            valid &= !(
                ('A' <= pass[i] && pass[i] <= 'Z') &&
                ('A' <= pass[i+1] && pass[i+1] <= 'Z') &&
                ('A' <= pass[i+2] && pass[i+2] <= 'Z')
            );
        }
        // -- 3 consecutive lowercase char is not allowed
        for(int i = 0; i < pass.length()-2; i++) {
            valid &= !(
                ('0' <= pass[i] && pass[i] <= '9') &&
                ('0' <= pass[i+1] && pass[i+1] <= '9') &&
                ('0' <= pass[i+2] && pass[i+2] <= '9')
            );
        }
    
    return valid;
}

int main () {

}