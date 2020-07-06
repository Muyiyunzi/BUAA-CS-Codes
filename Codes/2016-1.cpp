

//15:10-15:29
#include <cstdio>

const int maxn = 1000010;

int n, m, cnt = 0;
int a[maxn];

int revNum(int n) { //将输入n逆序，数值形式记录在m中，数组形式记录在a[]中
    int num = 0, temp;
    do{
        temp = n % 10;
        n /= 10;
        a[cnt++] = temp;
        num = num * 10 + temp;
    } while(n > 0);
    return num;
}

int main() {
    scanf("%d", &n);
    m = revNum(n);
    if(m % n == 0) {
        printf("%d*%d=%d\n", n, m / n, m);
    }
    else {
        printf("%d %s", n, a);
        printf("\n");
    }
    return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000010;

char str[maxn];

int toInt() { //将str转换为数值
    int num = 0;
    for(int i = 0; i < strlen(str); i++) {
        num = num * 10 + str[i] - '0';
    }
    return num;
}

int main() {
    scanf("%s", str);
    int n = toInt();
    printf("%d", n);
    reverse(str, str + strlen(str));
    int m = toInt();
    if(m % n == 0) {
        printf("*%d=%d\n", m / n, m);
    }
    else {
        printf(" ");
        for(int i = 0; i < strlen(str); i++) {
            printf("%d", str[i] - '0');
        }
        printf("\n");
    }
    return 0;
}

*/
