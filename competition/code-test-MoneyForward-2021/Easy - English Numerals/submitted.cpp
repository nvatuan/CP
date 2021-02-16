#include <bits/stdc++.h>
using namespace std;

string S;
string intergral, decimal;

int valid(string input) {
  if (input.length() == 1 && input == "0") return true;

  int prefixZero = (input[0] == '0');
  for (int i=1; i<(int)input.length(); i++) {
    if (prefixZero && (input[i] != '0') && (input[i] != '.')) return false;
  }

  int dotCnt = 0;
  for (char c : input) {
    dotCnt += (c == '.');
    if (!(('0' <= c and c <= '9') || c == '.')) return false;
  }
  if (dotCnt > 1) return false;
  return true;
}

string _under20[20] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "nineteen"
};

string _tens[10] = {
  "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string pronounce(string num) {
  if (num.length() <= 3) {
    int n = stoi(num);
    string st = "";
    if (n >= 100) {
      st += _under20[n / 100] + " " + "hundred";
      n = n % 100;
    }
    if (n >= 20) {
      if (st != "") st += " ";
      st += _tens[n / 10];
      if (n % 10 != 0) {
        if (st != "") st += " ";
        st += _under20[n % 10];
      }
    } else {
      if (st != "") st += " ";
      st += _under20[n];
    }
    return st;
  } else {
    vector<string> parts;
    for (int idx = (int)num.length() - 3; idx >= 0; idx -= 3) {
      parts.push_back(num.substr(idx, 3));
      if (idx <= 3) {
        if (idx == 0);
        else parts.push_back(num.substr(0, idx+1));
        break;
      }
    }
    string part_pro[] = {"billion", "million", "thousand", "hundred", ""};
    assert (parts.size() <= 5);
    int startIdx = 4;
    string read = "";

    for (string& p : parts) {
      read += p + " " + part_pro[startIdx];
      startIdx--;
      if (startIdx < 0) break;
    }
    return read;
  }
}

int main(int argc, char *argv[]) {
  cin >> S;
  if (!valid(S)) {
    cout << -1 << endl;
    return 0;
  }

  int point = S.find('.');
  if (point == string::npos) {
    intergral = S;
    decimal = "";
  } else {
    intergral = S.substr(0, point);
    decimal = S.substr(point+1);
  }

  string pro = pronounce(intergral);
  string pro_final = string("") + (char)toupper(pro[0]) + pro.substr(1);
  if (decimal != "") {
    pro_final += " point";
    for (char c : decimal) {
      pro_final += " " + _under20[(int)(c - '0')];
    }
  }
  cout << pro_final << endl;

  return 0;
}
