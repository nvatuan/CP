#include <bits/stdc++.h>
using namespace std;

string raw;
string intergral, decimal;

void die() {
    cout << -1 << endl;
    exit(0);
}

int split_intergral_decimal() {
    intergral = "";
    decimal = "";

    if (count(raw.begin(), raw.end(), '.') > 1) return 2;
    int idx = raw.find('.');
    if (idx == string::npos) {
        intergral = raw;
        decimal = "";
    } else {
        if (idx + 1 == raw.length()) return 1;
        else {
            intergral = raw.substr(0, idx);
            decimal = raw.substr(idx+1);
        }
    }
    return 0;
}

int invalid() {
    if (intergral == "0") return 0;
    if (intergral[0] == '0')
        return 1;
    for (char c : intergral) {
        if (!isdigit(c)) return 21;
    }
    for (char c : decimal) {
        if (!isdigit(c)) return 22;
    }

    return 0;
}

int ctoi(char c) {
    return (int)(c - '0');
}

string _under_20[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
string _tens[] = {
    "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};
string _unit[] = {
    "", "thousand", "million", "billion"
};

string pronouce_deicmal(string dec) {
    string res = "";
    for (char c : dec) {
        if (res != "") res += " ";
        res += _under_20[(int)(c - '0')];
    }
    return res;
}

string pronouce_intergral(string num) {
    if (num.length() <= 3) {
        num = string(3 - (int)num.length(), '0') + num;
        string res = "";
        if (num[0] != '0') res += _under_20[ctoi(num[0])] + " hundred";
        if (num[1] != '0') {
            if (num[1] < '2') {
                int tens_n_digit = stoi(num.substr(1));
                if (res != "") res += " ";
                res += _under_20[tens_n_digit];
                return res;
            } else {
                if (res != "") res += " ";
                res += _tens[(ctoi(num[1]))];
            }
        }
        if (num[2] != '0') {
            if (res != "") res += " ";
            res += _under_20[ctoi(num[2])];
        }
        return res;
    } else {
        stack<string> parts;
        for (int idx = (int)num.length() - 3; ; idx -= 3) {
            parts.push(num.substr(idx, 3));
            if (idx <= 3) {
                parts.push(num.substr(0, idx));
                break;
            }
        }

        string fin = "";
        while (!parts.empty()) {
            string part_pro = pronouce_intergral(parts.top());
            parts.pop();
            if (fin != "") fin += " ";
            fin += part_pro;
            if (_unit[parts.size()] != "") fin += " ";
            fin += _unit[parts.size()];
        }
        return fin;
    }
}

string capitalize(string st) {
    st[0] = toupper(st[0]);
    return st;
}

int main() {
    cin >> raw;
    if (split_intergral_decimal()) die();
    if (invalid()) die();

    string _final;
    if (intergral == "0") _final = "zero";
    else _final = pronouce_intergral(intergral); 

    if (decimal != "") _final += " point " + pronouce_deicmal(decimal);
    cout << capitalize(_final) << endl;
}