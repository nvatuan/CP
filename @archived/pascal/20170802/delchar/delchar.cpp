#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#define mp(x, y) std::make_pair(x, y)

static struct {
    int length;
    int direction;
} dp[5001][5001];

typedef std::vector<std::pair<int, std::pair<int, int> > > vpipii;

std::ifstream in;
std::ofstream out;

unsigned i, i2;
int w;
std::string s, s2, result;

vpipii queue;

std::string extract(int i, int i2){
    std::string result = s.substr(i-1, 1);
    
    int currX = i-1, currY = i2-1, lastX = i, lastY = i2;
    
//    std::cout << "new session\n";

    while (currX != 0 && currY != 0){
//        std::cout << currX << " " << currY << " " << lastX << " " << lastY<< std::endl;
        switch (dp[currX][currY].direction){
            case 1:
//                std::cout << "match\n";
                if (((lastX - currX - 1) > w) || (lastY - currY - 1) > w){
//                    std::cout << "fail";
                    return "-1";
                }
                result += s[currX-1];
                lastX = currX;
                lastY = currY;
                currX--;
                currY--;
                break;
            case 2:
                currX--;
                break;
            case 3:
                currY--;
                break;
        }
    }
    
    return result;
}

int main(){
    in.open("DELCHAR.INP");
    
    in >> w;
    in >> s;
    in >> s2;

    in.close();

    for (i = 1; i <= s.length(); i++){
        for (i2 = 1; i2 <= s2.length(); i2++){
            if (s[i-1] == s2[i2-1]){
                dp[i][i2].length = dp[i-1][i2-1].length + 1;
                dp[i][i2].direction = 1;
                queue.push_back(mp(-dp[i][i2].length, mp(i, i2)));
            } else {
                if (dp[i-1][i2].length > dp[i][i2-1].length){
                    dp[i][i2] = dp[i-1][i2];
                    dp[i][i2].direction = 2;
                } else {
                    dp[i][i2] = dp[i][i2-1];
                    dp[i][i2].direction = 3;
                }
            }
        }
    }
    
    out.open("DELCHAR.OUT");

    std::sort(queue.begin(), queue.end());

    for (vpipii::iterator j = queue.begin(); j != queue.end(); i++){
        if ((result = extract((*j).second.first, (*j).second.second)) != "-1"){
            std::reverse(result.begin(), result.end());
            out << result;
            out.close();
            return 0;
        }
    }
    
    out << "No solution";
    out.close();
    return 0;
}

