#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int i, l, st;
    int cap;
    string str;

    cin>>t;
        getline(cin, str);

    while(t > 0){
        t--;
        cap = 0;
        getline(cin, str); //cin>>str;

        char tmp;

        str += ' ';
        l = str.length();

        st = 0;

        for(i = 0; i < l; i++){

            if(str[i] == ' '){

                if(i - st == 1){
                    if(cap == 0){
                        cout<<str[st]<<"ay ";
                        cap = 1;
                    }
                    else cout<<str[st]<<"ay ";
                    i++;
                    st = i;
                }
                else{
                    tmp = str[st];

                    if(cap == 0){
                        str[st+1] -= ('a'-'A');
                        tmp += ('a'-'A');
                        cap = 1;
                    }

                    for(int j = st+1; j < i; j++) cout<<str[j];
                    cout<<tmp<<"ay ";
                    st = ++i;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
