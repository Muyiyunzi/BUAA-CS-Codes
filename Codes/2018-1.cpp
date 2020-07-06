//19:30
//20:21
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10010;
int cnt[maxn], temp = 0;
int n, s, t;

struct line {
    int sx, sy, tx, ty;
}l[maxn];

void check(int i, int now) { //对线段i进行讨论，查看now之后的线段是否与线段i重合
    for(int j = now + 1; j < n; j++) {
        if(l[j].sx == l[now].tx && l[j].sy == l[now].ty) { //若此时重合
            temp++;
            check(i, j);
            temp--;
        }
        else if(l[j].sx > l[now].tx) { //因已按横坐标排序，此句用于加速判断，可以不写
            return;
        }
    }
    //当未找到退出循环后，比较temp和对i的计数器，若更大则赋值
    //虽然每次从check退出都会判断一下，但是如果开flag标记找到，也会判断一下所以就这样吧
    if(temp > cnt[i]) {
        cnt[i] = temp;
    }
    return;
}

bool cmp(line a, line b) {
    return a.sx < b.sx;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &l[i].sx, &l[i].sy, &l[i].tx, &l[i].ty);
    }
    sort(l, l + n, cmp); //对所有线段按起点横坐标从小到大排序
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
        check(i, i);
    }
    int MAX = -1, num;
    for(int i = 0; i < n; i++) {
        if(cnt[i] > MAX) {
            MAX = cnt[i];
            num = i;
        }
    }
    printf("%d %d %d\n", MAX + 1, l[num].sx, l[num].sy);
    return 0;
}


