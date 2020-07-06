
//9:21 - 9:35
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000010;

struct node {
    int x, t; //输入的数值和次序
}num[maxn];

bool cmp(node a, node b) {
    if(a.x == b.x) return a.t < b.t;
    return a.x < b.x;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i].x);
        num[i].t = i + 1;
    }
    sort(num, num + n, cmp);
    if(n % 2 == 1) {
        printf("%d %d\n", num[n / 2].x, num[n / 2].t);
    }
    else {
        printf("%d %d\n", num[n / 2 - 1].x, num[n / 2 - 1].t);
        printf("%d %d\n", num[n / 2].x, num[n / 2].t);
    }
    return 0;
}










