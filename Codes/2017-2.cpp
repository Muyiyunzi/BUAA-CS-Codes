/*
//写完第三题之后回来再做的，没办法写完特判数组
//指针和取地址直接完蛋了。
#include <cstdio>
#include <cstring>
const int maxn = 1000000;

char str[maxn], temp[1000];
char sub[1000][1000];
int cnt1 = 0, cnt2 = 0;

void deal() {
    for(int i = 0; i < strlen(str) && str[i] != ';'; ) {
        while(str[i] != ',' && str[i] != '=' && str[i] != ';' && str[i] != ' ' && str[i] != '[') {
            sub[cnt1][cnt2++] = str[i];
            i++;
        }
        sub[cnt1][cnt2] = '\0';
        cnt1++;
        cnt2 = 0;
        if(str[i] == '=' || str[i] == '[') { //遇到等号或数组的时候，跳过之后的一切字符直到逗号或分号
            while(str[i] != ',' && str[i] != ';') {
                i++;
            }
        }
        if(str[i] == ',') { //遇到逗号的时候，跳过之后的一切空格
            i++;
        }
        while(str[i] == ' ') { //遇到空格的时候，跳过之后一切空格
            i++;
        }
        //遇到分号的时候自动结束循环
    }
}

bool check() {
    for(int i = 0; i < cnt1; i++) {
        if(strcmp(temp, sub[i]) == 0) {
            return true;
        }
    }
    return false;
}

void deal2() {
    for(int i = 0; i < strlen(str) && str[i] != ';'; i++) {
        while(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '%' && str[i] != '=') {
            if(str[i] == ' ') {
                i++;
                continue;
            }
            temp[cnt2++] = str[i];
            i++;
        }
        temp[cnt2] = '\0';
        if(!check()) {
            printf("%s ", temp);
        }
        memset(temp, 0, sizeof(temp));
        cnt2 = 0;
    }
}

int main() {
    gets(str);
    deal();
    gets(str);
    deal2();
    return 0;
}
*/

#include <cstdio>
#include <cstring>

const int maxn = 1010;
char str[maxn * maxn];
char sub[maxn][maxn];
int cnt1 = 0, cnt2 = 0;

bool judge(char c) { //判断字符是否为合法变量名，即只能是字母、下划线、数字
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9') || c == '_') return true;
    else return false;
}

void deal() { //对str进行处理，将所有的合法变量名按顺序存入sub中
    int i = 0, len = strlen(str);
    while(str[i] != ' ') i++; //无论输入的变量类型，先忽略变量类型
    while(i < len) { //当i超出范围时退出循环（也可以判断分号）
        while(i < len && !judge(str[i])) i++; //跳过所有的不合法字符，直至i超出范围或遇到“合法”字符
        while(str[i] >= '0' && str[i] <= '9') i++; //当在非法字符后遇到数字，必为常数，不予记录
        while(judge(str[i])) { //对满足变量名称类型的字符，循环记录到sub里
            sub[cnt1][cnt2++] = str[i++];
        }
        //完善字符串的末尾，并对cnt1自增，cnt2置零，准备处理下一串字符
        sub[cnt1][cnt2] = '\0';
        cnt1++, cnt2 = 0;
    }
}

bool defined(char temp[]) { //检查变量名是否已经定义过
    for(int j = 0; j < cnt1; j++) {
        if(strcmp(temp, sub[j]) == 0) return true;
    }
    return false;
}

void deal2() {
    int i = 0, len = strlen(str);
    while(i < len) {
        char temp[maxn]; //类似地，处理合法变量名保存至temp，在循环中定义可以避免清零的麻烦
        while(i < len && !judge(str[i])) i++; //当i超出范围时退出循环，不一定有分号
        while(str[i] >= '0' && str[i] <= '9') i++; //当在非法字符后遇到数字，必为常数，不予记录
        while(judge(str[i])) { //对满足变量名称类型的字符，循环记录到temp里
            temp[cnt2++] = str[i++];
        }
        temp[cnt2] = '\0', cnt2 = 0;
        if(!defined(temp)) { //若temp未定义，打印temp
            printf("%s ", temp);
        }
    }
    printf("\n");
}

int main() {
    gets(str);
    deal();
    gets(str);
    deal2();
    return 0;
}









