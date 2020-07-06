

//12:40
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct STR { //使用结构体替代二维数组，便于排序
    char s[105];
}str[1010];

int num = 0;

bool judgeExist(char b[]) { //判断此单词是否已经记录过
    for(int i = 0; i < num; i++) {
        if(strcmp(str[i].s, b) == 0)
            return true;
    }
    return false;
}

bool judgeChar(char c) { //判断是否为英文字符
    if(c >= 'a' && c <= 'z')
        return true;
    else return false;
}

bool cmp(STR a, STR b) { //对结构体按字典序排序
    return strcmp(a.s, b.s) < 0;
}

int main() {
    char a[100010], temp[105];
    while(gets(a) != NULL) {
        int i = 0, j = 0;
        while(i < strlen(a)) { //当i不为末尾时重复循环
            while(i < strlen(a) && judgeChar(a[i])) { //当为英文字母时，记录单词
                temp[j++] = a[i++];
            }
            if(j && !judgeExist(temp)) { //若j不为0，且未出现过，则将该单词copy到记录结构体里
                temp[j++] = '\0'; //养成习惯给字符串加结尾字符
                strcpy(str[num++].s, temp);
            }
            memset(temp, 0, sizeof(temp));
            j = 0;
            while(i < strlen(a) && !judgeChar(a[i])) i++;
        }
    }
    sort(str, str + num, cmp);
    for(int i = 0; i < num; i++) {
        printf("%s\n", str[i].s);
    }
    return 0;
}


/*典型错误做法
char str[1010][1010];
bool cmp(char a[], char b[]) {
    return strcmp(a, b) < 0;
}
sort(str, str + num, cmp);

*/
/*
//15:19-15:30
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int main() {
    char a[100010];
    set<string> s;
    while(gets(a) != NULL) {
        int i = 0;
        while(i < strlen(a)) {
            string temp; //每次使用每次定义，相当于清空的操作
            while(i < strlen(a) && a[i] >= 'a' && a[i] <= 'z') {
                temp += a[i++];
            }
            s.insert(temp);
            while(i < strlen(a) && (a[i] < 'a' || a[i] > 'z')) i++;
        }
    }
    for(set<string>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
*/
