




//12:50 预计14:00停止
//大约在13:20写完，debug到13:40，测试完成并开始写注释
//因为也不清楚数据的规模，以及会不会成环，所以采用邻接表存储图的方式
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10010;
const int inf = 0x3fffffff;

int n, m, s;
int pre[maxn];
bool vis[maxn] = {false};
bool flag; //flag=true时表示已找到
vector<int> Adj[maxn]; //邻接表

struct client {
    int num, prior;
}c[maxn];

bool cmp(client a, client b) {
    return a.prior < b.prior;
}

void printDFS(int v) {
    if(pre[v] != -1) {
        printDFS(pre[v]);
        printf("%d ", v);
    }
}

void DFS(int s, int ed) {
    vis[s] = true; //访问时先标记已访问，防止重复访问
    for(int i = 0; i < Adj[s].size(); i++) {
        int v = Adj[s][i];
        if(flag == true) return; //若已找到，直接返回
        if(vis[v] == false) { //当未找到时且当前v结点未被访问过
            pre[v] = s; //进入并设定v的前驱结点为s
            if(v != ed) { //若此时v不是终点，继续DFS遍历
                DFS(v, ed);
            }
            else { //到达终点
                printDFS(pre[v]); //打印先前的所有结点并空格
                printf("%d\n", v); //打印最后一个结点并换行
                flag = true; //并标记已找到
            }
        }
    }
}

int main() {
    int f, c1, c2, c3; //father & child 1~3
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &f, &c1, &c2, &c3);
        if(i == 0) s = f;
        if(c1 != -1) {
            Adj[f].push_back(c1);
            Adj[c1].push_back(f);
        }
        if(c2 != -1) {
            Adj[f].push_back(c2);
            Adj[c2].push_back(f);
        }
        if(c3 != -1) {
            Adj[f].push_back(c3);
            Adj[c3].push_back(f);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &c[i].num, &c[i].prior);
    }
    sort(c, c + m, cmp);
    //假设不存在环，那么路径唯一，直接使用DFS即可
    printf("%d ", s); //打印起点，此后遍历时均不打印起点
    for(int i = 0; i < m; i++) {
        flag = false;
        memset(pre, -1, sizeof(pre));
        memset(vis, 0, sizeof(vis));
        if(i == 0) {
            DFS(s, c[i].num);
        }
        else DFS(c[i - 1].num, c[i].num);
    }
    flag = false;
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    DFS(c[m - 1].num, s);
    return 0;
}









