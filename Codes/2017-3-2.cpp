#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

string member[100];
map<string, int> m;

int checkDepth(int num) {
    int d = 0;
    while(num) {
        num /= 2;
        d++;
    }
    return d;
}

int main() {
    string s, s1, s2, s3;
    int i;
    cin >> s1 >> s2 >> s3;
    member[1] = s1;
    member[2] = s2;
    member[3] = s3;
    m[s1] = 1, m[s2] = 2, m[s3] = 3;
    getchar(); //在cin和getline前吸收掉换行
    while(1) {
        getline(cin, s);
        s1.clear();
        s2.clear();
        s3.clear();
        for(i = 0; s[i] != ' '; i++) {
            s1 += s[i];
        }
        for(i = i + 1; s[i] != ' ' && i < s.length(); i++) {
            s2 += s[i];
        }
        if(i == s.length()) break;
        for(i = i + 1; i < s.length(); i++) {
            s3 += s[i];
        }
        int f = m[s1];
        member[2 * f] = s2;
        member[2 * f + 1] = s3;
        m[s2] = 2 * f, m[s3] = 2 * f + 1;
    }
    //退出后查询s1和s2共同的父节点和深度差
    //先获得s1 s2在数组中的编号
    int num1 = m[s1], num2 = m[s2];
    int d1 = checkDepth(num1), d2 = checkDepth(num2);
    int d = abs(d1 - d2); //记录此时深度差信息
    while(d1 > d2) { //若s1比s2深度更深
        num1 /= 2;
        d1--;
    }
    while(d1 < d2) { //若s2比s1深度更深
        num2 /= 2;
        d2--;
    }
    while(num1 != num2) { //此时处于同一深度，若不相同则均向上追溯
        num1 /= 2;
        num2 /= 2;
    }
    cout << member[num1] << " " << d << endl;
    return 0;
}
