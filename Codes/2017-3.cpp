#include <cstdio>
#include <cstring>
const int maxn = 1010;

int father[maxn];

struct member {
    char name[maxn];
    int depth;
}m[maxn], temp;

int main() {
    int i = 3, j, k;
    char check;
    scanf("%s %s %s", m[0].name, m[1].name, m[2].name);
    m[0].depth = 1;
    m[1].depth = m[2].depth = 2;
    father[1] = father[2] = 0;
    while(1) {
        scanf("%*c%s %s%c", temp.name, m[i++].name, &check);
        //找出temp所在的编号
        for(j = 0; j < i - 1; j++) {
            if(strcmp(temp.name, m[j].name) == 0) {
                break;
            }
        }
        if(check == '\n') break; //当输入只有两个就换行时，退出循环，开始检查
        scanf("%s", m[i++].name); //若不是，继续扫描第三个变量
        //标记其父亲和深度信息
        father[i - 2] = father[i - 1] = j;
        m[i - 2].depth = m[i - 1].depth = m[j].depth + 1;
    }
    //退出扫描后，要求检查temp和m[i-1]深度差和共同的父节点
    //先找出m[i-1]之前所在的编号，temp所在编号为j
    for(k = 0; k < i; k++) {
        if(strcmp(m[i - 1].name, m[k].name) == 0) {
            break;
        }
    }
    int d = m[k].depth - m[j].depth;
    if(d > 0) { //若k比j深度更深
        int dtemp = d;
        while(dtemp--) { //k向上追溯至同一深度
            k = father[k];
        }
        while(strcmp(m[k].name, m[j].name) != 0) { //若同深度时不等，继续向上追溯
            k = father[k];
            j = father[j];
        }
        printf("%s %d", m[j].name, d); //输出此时的共同结点，与原深度差
    }
    else { //若前者比后者深度更深
        int dtemp = -d;
        while(dtemp--) { //追溯至同一深度
            j = father[j];
        }
        while(strcmp(m[k].name, m[j].name) != 0) { //若同深度时不等，继续向上追溯
            k = father[k];
            j = father[j];
        }
        printf("%s %d", m[j].name, -d); //输出此时的共同结点，与原深度差
    }
    return 0;
}
